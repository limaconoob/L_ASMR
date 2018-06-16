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
**    L_ASMR  Copyright (C) 2018  Jérémy Pepin
**    This program comes with ABSOLUTELY NO WARRANTY; for details type `show w'.
**    This is free software, and you are welcome to redistribute it
**    under certain conditions; type `show c' for details.
*/

#include "drawing.h"

void draw_object7x9(uint8_t x, uint8_t y, draw k, uint8_t flag)
{ uint8_t i = 0, j = 0;
  k >>= 1;
  draw_polygon(x + 1, y, space, !flag ? 1 : 0);
  while (j < 9)
  { while (i < 7)
    { if (k & (1 << i))
      { set_pixel(x + (7 - i), y + (9 - j), flag); }
      i += 1; }
    i = 0;
    k >>= 7;
    j += 1; }
  queue_refresh(); }

void draw_number(uint8_t x, uint8_t y, uint8_t nb)
{ if (nb > 9) return;
  uint8_t i = 0, j = 0, cur_trunc = 0;
  draw shift = nombres[(nb * 5) + 4];
  while (j < 20)
  { while (i < 16)
    { if (shift & (1 << i))
      { set_pixel(x + (16 - i), y + (20 - j), 1); }
      i += 1; }
    i = 0;
    shift >>= 16;
    j += 1;
    if (!(j % 4))
    { cur_trunc += 1;
      shift = nombres[(nb * 5) + (4 - cur_trunc)]; }}
  queue_refresh(); }


void outc(uint8_t x, uint8_t y, char c, uint8_t flag)
{ if (c > 64 && c < 91)                               //if_upper
  { c -= 65; 
    draw_object7x9(x, y, font7x9[c], flag); }
  else if (c > 96 && c < 123)                         //if_lower
  { c -= 71;
    draw_object7x9(x, y, font7x9[c], flag); }
  else if (c > 47 && c < 58)                          //if_digit
  { c += 6; 
    draw_object7x9(x, y, font7x9[c], flag); }
  else if (c == 32)                                   //if_space
  { draw_polygon(x, y, space, 0); }
  else if (c == 45)                                   // tiret -
  { draw_object7x9(x, y, font7x9[52], flag); }
  else if (c == 95)                                   // underscore _
  { draw_object7x9(x, y, font7x9[53], flag); }
  else                                                // non supporté
  { draw_object7x9(x, y, lil_square, flag); }}

void putstr_7x9(uint8_t x, uint8_t y, char *str, uint8_t flag)
{ while (*str)
  { outc(x, y, *str, flag);
    x += 8;
    str += 1; }}

// Dessine seulement des lignes verticales.
void draw_linear(point y1, point y2, point x, uint8_t flag)
{ while (y1 <= y2)
  { set_pixel(x, y1, flag);
    y1 += 1; }
  queue_refresh(); }

// dessin[i] = y1;
// dessin[i + 1] = y2;
void draw_polygon(uint8_t x, uint8_t y, point *polygone, uint8_t flag)
{ while (*polygone || *(polygone + 1))
  { draw_linear((*polygone) + y, (*(polygone + 1)) + y, x, flag);
    x += 1;
    polygone += 2; }
  queue_refresh(); }

// Dessine le bouton Stop/Play/Pause
void draw_spp(uint8_t flag)
{ draw_polygon(114, 35, clear_spp, 0);
  if (flag == PLAY)
  { draw_polygon(115, 35, play, 1); }
  else if (flag == PAUSE)
  { draw_polygon(114, 35, pause, 1);
    draw_polygon(121, 35, pause, 1); }
  else if (flag == STOP)
  { draw_polygon(114, 38, stop, 1); }
  else if (flag == RECORD)
  { draw_polygon(114, 38, record, 1); }}

void init_timer(void)
{ draw_number(0, 34, 0);
  draw_number(17, 34, 0);
  draw_polygon(35, 40, dot, 1);
  draw_polygon(35, 47, dot, 1);
  draw_number(37, 34, 0);
  draw_number(54, 34, 0);
  draw_polygon(72, 40, dot, 1);
  draw_polygon(72, 47, dot, 1);
  draw_number(74, 34, 0);
  draw_number(91, 34, 0); }

void draw_timer(void)
{ draw_number(0, 34, 0);
  draw_number(17, 34, 5);
  draw_number(37, 34, 3);
  draw_number(54, 34, 8);
  draw_number(74, 34, 5);
  draw_number(91, 34, 6); }
