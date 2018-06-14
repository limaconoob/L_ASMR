/*
**    drawing.h
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

#ifndef DRAWING_H
  #define DRAWING_H

  #include "..\pic32ssd1306-master\ssd1306.h"

  typedef const unsigned char draw;

  enum
  { PLAY,
    PAUSE,
    STOP };
  
  void draw_spp(uint8_t flag);
  void draw_objects(uint8_t x, uint8_t y, draw *dessin, uint8_t couleur);
  void draw_polygon(uint8_t x, uint8_t y, draw *polygone, uint8_t couleur);
  void draw_linear(uint8_t y1, uint8_t y2, uint8_t x, uint8_t couleur);

  // Font

  // Objects
  draw petite_croix[20] = { 0, 0, 1, 1, 2, 2, 0, 4, 1, 3, 4, 0, 3, 1, 3, 3, 4, 4, 0, 0};
  draw usb_logo[64] = { 3, 0, 2, 1, 3, 1, 4, 1, 3, 2, 3, 3, 5, 3, 6, 3, 0, 4, 1, 4, 3, 4, 5, 4, 6, 4, 0, 5, 1, 5, 3, 5, 6, 5 , 0, 6, 3, 6, 4, 6, 5, 6, 1, 7, 2, 7, 3, 7, 3, 8, 2, 9, 3, 9, 4, 9, 2, 10, 3, 10, 4, 10, 0, 0 };

  // Polygons
  draw sd_card[16] = { 0, 6, 0, 6, 0, 6, 0, 6, 0, 6, 1, 6, 2, 6, 0, 0 };
  draw batterie[32] = { 0, 8, 0, 8, 0, 8, 0, 8, 0, 8, 0, 8, 0, 8, 0, 8, 0, 8, 0, 8, 0, 8, 0, 8, 0, 8, 2, 5, 2, 5, 0, 0 };
  draw play[24] = { 0, 20, 1, 19, 2, 18, 3, 17, 4, 16, 5, 15, 6, 14, 7, 13, 8, 12, 9, 11, 10, 10, 0, 0 };
  draw pause[12] = { 0, 20, 0, 20, 0, 20, 0, 20, 0, 20, 0, 0 };
  draw stop[32] = { 0, 14, 0, 14, 0, 14, 0, 14, 0, 14, 0, 14, 0, 14, 0, 14, 0, 14, 0, 14, 0, 14, 0, 14, 0, 14, 0, 14, 0, 0 };
  draw clear_spp[] = { 0, 20, 0, 20, 0, 20, 0, 20, 0, 20, 0, 20, 0, 20, 0, 20, 0, 20, 0, 20, 0, 20, 0, 20, 0, 0 };

#endif

