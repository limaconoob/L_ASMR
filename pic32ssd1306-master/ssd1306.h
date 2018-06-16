/*
** ssd1306.h
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

#ifndef _SSD1306_H 
#define _SSD1306_H

#include <stdint.h>

// The channel being used for I2C

#define SSD1306_I2C_CHANNEL I2C1

// The I2C address of the OLED screen
// If your OLED screen says something like 0x78 it's probably actually 0x3C
// If it says 0x7A it's probably 0x3D
// Those addresses have already been shifted left by one, we need the
// unshifted value.

#define SSD1306_I2C_ADDR 0x3C

// This is the speed the I2C bus runs it and is a function of the PBCLK
// Check Section 24: Inter-Integrated Circuit of the PIC32 Family Reference
// Manual, and look under the Enabling I2C Operation section for a table
// that has different example Baud Rate Divisions for a selection of PBCLKs
// and the formula to calculate your own.

// 0x0C2 is for 40MHz PBCLK to run the I2C bus at 100KHz
// 0x02C is for 40MHz PBCLK to run the I2C bus at 400KHz

#define SSD1306_I2C_BAUD_RATE_DIVIDER 0x02C

// Clears the virtual buffer and updates the screen

void clear_screen(void);

// Sets a pixel at a particular location on the screen
// 0 = black, 1 = white for colour.

void set_pixel(uint8_t x, uint8_t y, uint8_t colour);

// Required to setup the screen and interrupt handling

void ssd1306_initialize(void);

// Refresh I2C Buffer 
void queue_refresh(void);

#endif
