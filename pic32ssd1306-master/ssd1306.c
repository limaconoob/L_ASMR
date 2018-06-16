/*
** ssd1306.c
**
** This file has been imported from https://github.com/brynthomas/pic32ssd1306
** It is supposed to make the OLED LCD works with I2C protocol.
**
** Thanks to brynthomas for sharing his work on GitHub.
** You can check out more of his work at https://github.com/brynthomas
**
** I modified this file for fitting the electronical materials of my project.
** Due to the limited space of the PIC32 micro-controller's flash, I supressed 
** some functions which I was not using in my project.
*/

#include "..\L_ASMR.X\outils.h"

#include "ssd1306.h"
#define _DISABLE_OPENADC10_CONFIGPORT_WARNING
#define _SUPPRESS_PLIB_WARNING

#include <stdint.h>
#include <plib.h>

// This lot of defines is present to allow me to specify a single instance of
// "SSD1306_I2C_CHANNEL" and then dynamically generate all the combinations
// of BRG/CON/IRQ etc that are needed.

#define DEF_MERGER_INDIRECTOR(x,y,z) x ## y ## z
#define DEF_MERGER(x,y,z) DEF_MERGER_INDIRECTOR(x,y,z)
#define CHAN_FUNC(suffix) DEF_MERGER(SSD1306_I2C_CHANNEL, suffix, )
#define CHAN_FUNC_PREFIXED(prefix, suffix) DEF_MERGER(prefix, SSD1306_I2C_CHANNEL, suffix)

// A set of definitions defining the font and screen information
// It's only been tested with this one particular font at this one font size
// It definitely won't work with fonts that could vertically straddle more than
// two pages (i.e. height > 16), nor will it work with fonts that are not 4 or
// possible 8 pixels wide. It's not been built with flexible fonts in mind.

#define FONT_WIDTH 4
#define FONT_HEIGHT 7
#define FONT_FIRST_CHAR 32
#define FONT_LAST_CHAR 126
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define SCREEN_PAGES 8
#define TEXT_ROWS 9
#define TEXT_COLUMNS 32

// The array that stores the full screen data. Is this really necessary?
// Could it be done to work directly off the memory in the SSD1306 and avoid
// a local buffer? Yes, but for expedience and simplicity it's done like this.
// Not particularly RAM constrained on the PIC32 either.

// The screen is set to "Horizontal Addressing Mode" in this mode
// it is accessed in 8 pixel vertical pages, then 128 pixel columns,
// and then those 128 byte columns are organised into 8 rows of 8 pixels.
// Top to bottom (1 byte), then left to right (128 bytes),
// then more top to bottom. (1024 bytes)

static uint8_t screen_data[1024];

// Tracks the state of the I2C transmission for the interrupt handler.

static int i2c_irq_phase;
static int i2c_data_count;

// Used to signal the state of transmission.

static uint8_t i2c_refresh_queued = 0;
static uint8_t i2c_in_transfer = 0;

// Begins a refresh of the on-chip pixel data to the SSD1306
// If a transfer is already in progress, another one gets queued up.
// If a transfer is not happening, it directly starts up the I2C system
// knowing that the interrupt handler will see it through to completion.

void queue_refresh(void){
    i2c_refresh_queued = 1;
    if (i2c_in_transfer == 0){
        INTClearFlag(INT_SOURCE_I2C_MASTER(CHAN_FUNC()));
        i2c_in_transfer = 1;
        i2c_irq_phase = 0;
        CHAN_FUNC(CONbits).SEN = 1;        
    }
}
// Clears the virtual buffer and updates the screen.

void clear_screen(void){
    memset(screen_data, 0, (SCREEN_WIDTH * SCREEN_HEIGHT) >> 3);
    queue_refresh();
}

// Sets a pixel at a particular location on the screen.
// 0 = black, 1 = white for colour.

void set_pixel(uint8_t x, uint8_t y, uint8_t colour){
    uint8_t bit_offset = y & 7;
    uint8_t row_offset = y >> 3;
    uint8_t column_offset = x;
    if (x >= SCREEN_WIDTH)
        return;
    if (y >= SCREEN_HEIGHT)
        return;
    
    if (colour == 0){
        screen_data[SCREEN_WIDTH * row_offset + column_offset] &= ~(1 << bit_offset); 
    } else {
        screen_data[SCREEN_WIDTH * row_offset + column_offset] |= (1 << bit_offset); 
    }
}

// Our interrupt handler to drive updating of the screen

void __ISR(CHAN_FUNC_PREFIXED(_, _VECTOR), IPL1SOFT) i2c_irq_handler(void){
    INTClearFlag(INT_SOURCE_I2C_MASTER(CHAN_FUNC()));
    
    // Every I2C transaction follows the pattern of
    // SEN -> Address -> Command/Data Selection -> Command/Data* -> PEN
    // We assign a number for each of those and track which state we're in.
    
    switch (i2c_irq_phase) {
      // SSD1306 Data
        // Blast out the 1024 bytes of screen data

        case 0: CHAN_FUNC(TRN) = SSD1306_I2C_ADDR << 1; i2c_irq_phase++; break;
        case 1: CHAN_FUNC(TRN) = 0b01000000; i2c_data_count = 0; i2c_irq_phase++; i2c_refresh_queued = 0; break;
        case 2: CHAN_FUNC(TRN) = screen_data[i2c_data_count]; i2c_data_count++; if (i2c_data_count >= ((SCREEN_WIDTH * SCREEN_HEIGHT) >> 3)) i2c_irq_phase++; break;
        case 3: CHAN_FUNC(CONbits).PEN = 1; i2c_irq_phase++; break;
        
        // If we have another transfer queued, begin that.
        // Otherwise we're done with I2C for now. 
        case 4: if (i2c_refresh_queued) {i2c_irq_phase = 0; CHAN_FUNC(CONbits).SEN = 1; } else {i2c_irq_phase++; i2c_in_transfer = 0; }; break;
    }
}

static void i2c_send_command(uint8_t data){
    // Every I2C transaction follows the pattern of
    // SEN -> Address -> Command/Data Selection -> (Command/Data)* -> PEN    
    CHAN_FUNC(CONbits).SEN = 1;
    while (CHAN_FUNC(CONbits).SEN);
    // Send the address
    CHAN_FUNC(TRN) = SSD1306_I2C_ADDR << 1;
    while (CHAN_FUNC(STATbits).TRSTAT);
    // Tell it a command is coming
    CHAN_FUNC(TRN) = 0b00000000;
    while (CHAN_FUNC(STATbits).TRSTAT);
    // Send the command
    CHAN_FUNC(TRN) = data;
    while (CHAN_FUNC(STATbits).TRSTAT);
    // End the transaction
    CHAN_FUNC(CONbits).PEN = 1;
    while (CHAN_FUNC(CONbits).PEN);
}

#define GetSystemClock() (40000000ul)

void ssd1306_initialize(void){
    INTConfigureSystem(INT_SYSTEM_CONFIG_MULT_VECTOR);
    INTEnableSystemMultiVectoredInt();
    SYSTEMConfigPerformance(GetSystemClock());
    INTEnableInterrupts();
    // Setup the interrupts and interrupt handlers
    INTSetVectorPriority(INT_VECTOR_I2C(CHAN_FUNC()), INT_PRIORITY_LEVEL_1);
    INTSetVectorSubPriority(INT_VECTOR_I2C(CHAN_FUNC()), INT_SUB_PRIORITY_LEVEL_3);
    INTEnable(INT_SOURCE_I2C_MASTER(CHAN_FUNC()), INT_DISABLED);
    
    // Set the I2C baud rate
    CHAN_FUNC(BRG) = SSD1306_I2C_BAUD_RATE_DIVIDER;
    
    // Enable the I2C bus
    CHAN_FUNC(CONbits).ON = 1;
    
    i2c_irq_phase = 0;
    
    // This is the initialisation code needed for the SSD1306. Some of these
    // can vary from module to module depending on the physical setup!
    
    // This is pretty much a direct copy of the flowchart found in the
    // SSD1306 datasheet near the end titled:
    // "Software initialization flow chart"
    
    // Display Off
    i2c_send_command(0xAE);

    // Set Osc Frequency
    i2c_send_command(0xD5);
    i2c_send_command(0x80);

    // Set MUX Ratio
    i2c_send_command(0xA8);
    i2c_send_command(0x3F);

    // Set Display Offset
    i2c_send_command(0xD3);
    i2c_send_command(0x00);
    
    // Set Display Start Line
    i2c_send_command(0x40);
    
    // Enable charge pump regulator
    i2c_send_command(0x8D);
    i2c_send_command(0x14);

    // Set horizontal addressing mode
    i2c_send_command(0x20);
    i2c_send_command(0x00);
    
    // Set Segment re-map (if things are reversed you can try change this to 0xA0)
    i2c_send_command(0xA1);
    
    // Set COM Output Scan Direction
    // (if things are reversed you can try change this to 0xC0)
    i2c_send_command(0xC8);
    
    // Set COM Pins hardware configuration
    // (if rows are missing or duplicated you can try 0xDA/0x02)
    i2c_send_command(0xDA);
    i2c_send_command(0x12);
    
    // Set Contrast Control
    i2c_send_command(0x81);
    i2c_send_command(0xCF);
    
    // Set Precharge
    i2c_send_command(0xD9);
    i2c_send_command(0xF1);
    
    // Set VCOM Detect
    i2c_send_command(0xDB);
    i2c_send_command(0x40);
    
    // Disable Entire Display On
    // (if you just are trying to get ANYTHING to show on the screen
    // it can help when testing to set 0xA5 to get the whole screen white)
    i2c_send_command(0xA4);
    
    // Set Normal Display (instead of reversed)
    i2c_send_command(0xA6);
    i2c_send_command(0x2E);
    
    // Display On
    i2c_send_command(0xAF);

    int i = 100000;
    while (i)
    { i -= 1; }
    clear_screen();

    // Enable the interrupt handler
    INTClearFlag(INT_SOURCE_I2C_MASTER(CHAN_FUNC()));
    INTEnable(INT_SOURCE_I2C_MASTER(CHAN_FUNC()), INT_ENABLED);

    queue_refresh();    
}

