/*
**    drawing.c
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
**    L_ASMR  Copyright (C) 2018  J�r�my Pepin
**    This program comes with ABSOLUTELY NO WARRANTY; for details type `show w'.
**    This is free software, and you are welcome to redistribute it
**    under certain conditions; type `show c' for details.
*/

#include "drawing.h"
/*
void draw_object3x5(uint8_t x, uint8_t y, tiny_draw k)
{ uint8_t i = 0, j = 0;
  k >>= 1;
  draw_polygon(x, y, space, 0); // Nettoie la cellule o� on va �crire le char
  while (j < 8)
  { while (i < 3)
    { if (k & (1 << i))
      { set_pixel(x + (7 - i), y + (9 - j), 1); }
      i += 1; }
    i = 0;
    k >>= 7;
    j += 1; }
  queue_refresh(); }
*/
void draw_object7x9(uint8_t x, uint8_t y, draw k)
{ uint8_t i = 0, j = 0;
  draw_polygon(x, y, space, 0); // Nettoie la cellule o� on va �crire le char
  while (j < 9)
  { while (i < 7)
    { if (k & (1 << i))
      { set_pixel(x + (7 - i), y + (9 - j), 1); }
      i += 1; }
    i = 0;
    k >>= 7;
    j += 1; }
  queue_refresh(); }

void draw_number(uint8_t x, uint8_t y, uint8_t nb)
{ uint8_t i = 0, j = 0, shift = 0, cur_trunc = 0;
  while (j < 16)
  { while (i < 24)
    { if ((nombres[cur_trunc]) & (draw)((draw)1 << ((draw)((draw)63 - (draw)shift))))
      { set_pixel(x + (24 - i), y + (16 - j), 1); }
      shift += 1;
      if (shift == 64)
      { cur_trunc += 1;
        shift = 0; }
      i += 1; }
    i = 0;
    j += 1; }
  queue_refresh(); }


void outc(uint8_t x, uint8_t y, char c)
{ if (c > 32)
  { c -= 95;//33; 
    draw_object7x9(x, y, font7x9[c] >> 1); }
  else if (c == 32)
  { draw_polygon(x, y, space, 0); }}

void putstr_7x9(uint8_t x, uint8_t y, char *str)
{ while (*str)
  { outc(x, y, *str);
    x += 8;
    str += 1; }}

// Dessine seulement des lignes verticales.
void draw_linear(point y1, point y2, point x, point couleur)
{ while (y1 <= y2)
  { set_pixel(x, y1, couleur);
    y1 += 1; }
  queue_refresh(); }

// dessin[i] = y1;
// dessin[i + 1] = y2;
void draw_polygon(uint8_t x, uint8_t y, point *polygone, uint8_t couleur)
{ while (*polygone || *(polygone + 1))
  { draw_linear((*polygone) + y, (*(polygone + 1)) + y, x, couleur);
    x += 1;
    polygone += 2; }}

// Dessine le bouton Stop/Play/Pause
void draw_spp(uint8_t flag)
{ draw_polygon(114, 27, clear_spp, 0);
  if (flag == PLAY)
  { draw_polygon(115, 27, play, 1); }
  else if (flag == PAUSE)
  { draw_polygon(114, 27, pause, 1);
    draw_polygon(121, 27, pause, 1); }
  else if (flag == STOP)
  { draw_polygon(114, 30, stop, 1); }}