/*
**    polygons.c
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

#include "display.h"

// Dessine seulement des lignes verticales.
void draw_linear(point y1, point y2, point x, uint8_t flag)
{ while (y1 <= y2)
  { set_pixel(x, y1, flag);
    y1 += 1; }
  queue_refresh(); }

// (point*)polygone[i] = y1;
// (point*)polygone[i + 1] = y2;
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