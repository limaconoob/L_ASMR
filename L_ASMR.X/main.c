/*
**    main.c
** 
**    L_ASMR is an embedded systems project. The initial purpose is to build a
**    binaural microphone and some useful features on it, with cheap materials.
**
**    Copyright (C) 2018  {name of author}
**
**    This program is free software: you can redistribute it and/or modify
**    it under the terms of the GNU General Public License as published by
**    the Free Software Foundation, either version 3 of the License, or
**    (at your option) any later version.
**
**    This program is distributed in the hope that it will be useful,
**    but WITHOUT ANY WARRANTY; without even the implied warranty of
**    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
**    GNU General Public License for more details.
**
**    You should have received a copy of the GNU General Public License
**    along with this program.  If not, see <http://www.gnu.org/licenses/>.
**
**    L_ASMR  Copyright (C) 2018  Jérémy Pepin
**    This program comes with ABSOLUTELY NO WARRANTY; for details type `show w'.
**    This is free software, and you are welcome to redistribute it
**    under certain conditions; type `show c' for details.
*/

#include "config_bits.h"

#include <p32xxxx.h>
#include <sys/attribs.h>

#include "outils.h"
#include "..\pic32ssd1306-master\ssd1306.h"

/*
**   a b c
** d 1 2 3
** e 4 5 6
** f 7 8 9
** g * 0 #
**
** Vert:a
** Rouge:b
** Blanc:c
**
** Bleu:g
** Marron:f
** Jaune:e
** Gris:d
*/

// Objects
static unsigned char petite_croix[20] = { 0, 0, 1, 1, 2, 2, 0, 4, 1, 3, 4, 0, 3, 1, 3, 3, 4, 4, 0, 0};
static unsigned char usb_logo[64] = { 3, 0, 2, 1, 3, 1, 4, 1, 3, 2, 3, 3, 5, 3, 6, 3, 0, 4, 1, 4, 3, 4, 5, 4, 6, 4, 0, 5, 1, 5, 3, 5, 6, 5 , 0, 6, 3, 6, 4, 6, 5, 6, 1, 7, 2, 7, 3, 7, 3, 8, 2, 9, 3, 9, 4, 9, 2, 10, 3, 10, 4, 10, 0, 0 };

// Polygons
static unsigned char sd_card[16] = { 0, 6, 0, 6, 0, 6, 0, 6, 0, 6, 1, 6, 2, 6, 0, 0 };
static unsigned char batterie[32] = { 0, 8, 0, 8, 0, 8, 0, 8, 0, 8, 0, 8, 0, 8, 0, 8, 0, 8, 0, 8, 0, 8, 0, 8, 0, 8, 2, 5, 2, 5, 0, 0 };
static unsigned char play[24] = { 0, 20, 1, 19, 2, 18, 3, 17, 4, 16, 5, 15, 6, 14, 7, 13, 8, 12, 9, 11, 10, 10, 0, 0 };
static unsigned char pause[12] = { 0, 20, 0, 20, 0, 20, 0, 20, 0, 20, 0, 0 };
static unsigned char stop[32] = { 0, 14, 0, 14, 0, 14, 0, 14, 0, 14, 0, 14, 0, 14, 0, 14, 0, 14, 0, 14, 0, 14, 0, 14, 0, 14, 0, 14, 0, 0 };
static unsigned char clear_spp[] = { 0, 20, 0, 20, 0, 20, 0, 20, 0, 20, 0, 20, 0, 20, 0, 20, 0, 20, 0, 20, 0, 20, 0, 20, 0, 0 };

// Dessine seulement des lignes verticales.
static void draw_linear(uint8_t y1, uint8_t y2, uint8_t x, uint8_t couleur)
{ while (y1 <= y2)
  { set_pixel(x, y1, couleur);
    y1 += 1; }
  queue_refresh(); }

// dessin[i] = y1;
// dessin[i + 1] = y2;
static void draw_polygon(uint8_t x, uint8_t y, unsigned char *polygone, uint8_t couleur)
{ while (*polygone || *(polygone + 1))
  { draw_linear((*polygone) + y, (*(polygone + 1)) + y, x, couleur);
    x += 1;
    polygone += 2; }}

// dessin[i] = x;
// dessin[i + 1] = y;
static void draw_objects(uint8_t x, uint8_t y, unsigned char *dessin, uint8_t couleur)
{ uint8_t i = 2;
  set_pixel(x + (*dessin), y + (*(dessin + 1)), couleur);
  while (dessin[i] || dessin[i + 1])
  { set_pixel(x + dessin[i], y + dessin[i + 1], couleur);
    i += 2; }
  queue_refresh(); }

// 0: plus de batterie ; 11: batterie pleine
uint8_t battery_level(void)
{ return (6); }

void update_battery(void)
{ draw_polygon(110, 7, batterie, 1);
  uint8_t level = 11 - battery_level();
  while (level)
  { draw_linear(8, 14, 122 - level, 0);
    level -= 1; }}

enum
{ PLAY,
  PAUSE,
  STOP };

void draw_spp(uint8_t flag)
{ draw_polygon(114, 27, clear_spp, 0);
  if (flag == PLAY)
  { draw_polygon(115, 27, play, 1); }
  else if (flag == PAUSE)
  { draw_polygon(114, 27, pause, 1);
    draw_polygon(121, 27, pause, 1); }
  else if (flag == STOP)
  { draw_polygon(114, 30, stop, 1); }}

int main()
{ TRISFbits.TRISF1 = 0;
  TRISDbits.TRISD8 = 1;
  LATFbits.LATF1 = 1;
  
  TRISEbits.TRISE2 = 0; // Blanc
  TRISEbits.TRISE3 = 0; // Rouge
  TRISEbits.TRISE4 = 0; // Vert
  TRISEbits.TRISE5 = 1; // Gris
  TRISEbits.TRISE6 = 1; // Jaune
  TRISEbits.TRISE7 = 1; // Marron
  TRISFbits.TRISF6 = 1; // Bleu
  LATEbits.LATE2 = 0;
  LATEbits.LATE3 = 0;
  LATEbits.LATE4 = 0;

  // OLED LCD Init
  ssd1306_initialize();
  
  // HEADER
  draw_objects(80, 5, usb_logo, 1);
  draw_polygon(95, 9, sd_card, 1);
  
  update_battery();
  
  draw_spp(PLAY);
  
  unsigned char k;
  k = 0;
  while (42)
  { if (PORTFbits.RF6 == 0 && k == 1)
    { LATFbits.LATF1 ^= 1;
      k = 0; }
    else if (PORTFbits.RF6 == 1)
    { k = 1; }}}
