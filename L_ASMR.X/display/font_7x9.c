/*
**    font_7x9.c
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

/// This font is the alphanumeric part of the "CP437" font which was created by
/// IBM for the original IBM PC. No typography designer was mentionned.
/// Check out https://en.wikipedia.org/wiki/Code_page_437 for more infos
/// This product is under the Creative Commons Attribution-ShareAlike License :
/// https://en.wikipedia.org/wiki/Wikipedia:Text_of_Creative_Commons_Attribution-ShareAlike_3.0_Unported_License
/// I do not directly share it, I'm only using it in my project.

#include "display.h"

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
