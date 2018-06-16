/*
**    timer_display.c
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

#include "display.h"

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
