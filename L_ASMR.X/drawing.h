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
**    L_ASMR  Copyright (C) 2018  J�r�my Pepin
**    This program comes with ABSOLUTELY NO WARRANTY; for details type `show w'.
**    This is free software, and you are welcome to redistribute it
**    under certain conditions; type `show c' for details.
*/

#ifndef DRAWING_H
  #define DRAWING_H

  #include "..\pic32ssd1306-master\ssd1306.h"

  typedef unsigned long long  draw;
  typedef unsigned short      tiny_draw;
  typedef unsigned char       point;

  enum
  { PLAY,
    PAUSE,
    STOP };
  
  void draw_spp(uint8_t flag);
  void draw_object7x9(uint8_t x, uint8_t y, draw k);
  void draw_polygon(uint8_t x, uint8_t y, point *polygone, uint8_t couleur);
  void draw_linear(uint8_t y1, uint8_t y2, uint8_t x, uint8_t couleur);
  void putstr_7x9(uint8_t x, uint8_t y, char *str);

/*
  tiny_draw font3x5[] =
  { 0x00001700,
    0x00030003,
    0x001f0a1f,
    0x00051f0a,
    0x00120409,
    0x001c170f,
    0x00000300,
    0x00110e00,
    0x00000e11,
    0x00050205,
    0x00040e04,
    0x00000810,
    0x00040404,
    0x00001000,
    0x00030418,
    0x000f111e,
    0x00001f02,
    0x00121519,
    0x000a1511,
    0x001f0407,
    0x00091517,
    0x001d151e,
    0x00030519,
    0x001f151f,
    0x000f1517,
    0x00000a00,
    0x00000a10,
    0x00110a04,
    0x000a0a0a,
    0x00040a11,
    0x00031501,
    0x0016150e,
    0x001e051e,
    0x000a151f,
    0x0011110e,
    0x000e111f,
    0x0015151f,
    0x0005051f,
    0x001d150e,
    0x001f041f,
    0x00111f11,
    0x000f1008,
    0x001b041f,
    0x0010101f, 0x1f061f, 0x1f0e1f, 0xe110e, 0x2051f, 0x1e190e, 0x160d1f, 0x91512, 0x11f01, 0x1f100f, 0x71807, 0x1f0c1f, 0x1b041b, 0x31c03, 0x131519, 0x11111f, 0x80402, 0x1f1111, 0x20102, 0x101010, 0x201, 0x1c161a, 0xc121f, 0x12120c, 0x1f120c, 0x161a0c, 0x51e04, 0x1e2a0c, 0x1c021f, 0x1d00, 0x1d2010, 0x120c1f, 0x101f11, 0x1e0e1e, 0x1c021e, 0xc120c, 0xc123e, 0x3e120c, 0x2021c, 0xa1e14, 0x121f02, 0x1e100e, 0xe180e, 0x1e1c1e, 0x120c12, 0x1e2806, 0x161e1a, 0x111b04, 0x1b00, 0x41b11, 0x10302};
*/

  // Font 7x9
  draw font7x9[28] =
  { 0b1100011110001101101100111110001110001111100110110110001111000110,  //X
    0b0001000001110001101101100011110001111111111100011110001111000110,  //A
    0b0000000000000001111000000110011111011001101100110110011001110110,  //a
    0b1110000011000001100000111100011011001100110110011011001111011100,  //b
    0b0000000000000001111101100011110000011000001100000110001101111100,  //c
    0b0001110000011000001100011110011011011001101100110110011001110110,  //d
    0b0000000000000001111101100011111111111000001100000110001101111100,  //e
    0b0011110011001101100010110000111100001100000110000011000011110000,  //f
    0b0000000000000001110111100110110011001111100000110110011001111000,  //g
    0b1110000011000001100000110110011101101100110110011011001111100110,  //h
    0b0011000001100000000000111000001100000110000011000001100001111000,  //i
    0b0000011000001100000000000111000001100000111100011110001101111100,  //j
    0b1110000011000001100110110110011110001111000110110011001111100110,  //k
    0b0111000001100000110000011000001100000110000011000001100001111000,  //l
    0b0000000000000011101101111111110101111010111101011110101111010110,  //m
    0b0000000000000011011100110011011001101100110110011011001111100110,  //n
    0b0000000000000001111101100011110001111000111100011110001101111100,  //o
    0b0000000000000011011100110011011001101111100110000011000011110000,  //p
    0b0000000000000001110111100110110011001111100000110000011000011110,  //q
    0b0000000000000011011100111011011001101100000110000011000011110000,  //r
    0b0000000000000001111101100011011000000111000000110110001101111100,  //s
    0b0001000001100000110001111110001100000110000011000001101100011100,  //t
    0b0000000000000011001111100110110011011001101100110110011001110110,  //u
    0b0000000000000011000111100011110001111000111100011011011000111000,  //v
    0b0000000000000011000111100011110101111010111101011111111101101100,  //w
    0b0000000000000011000110110110001110000111000011100011011011000110,  //x
    0b0000000000000011000111100011110001101111110000011000011011111000,  //y
    0b0000000000000011111111100110000110000110000110000110001111111110   //z
  };

  // Nombres pour le Chrono, font en 24x16
  draw nombres[6] =
  { 0b0000000111111111100000000000000111111111100000000000000111111111, // -,-
    0b1000000000000001111111111000000000011111110000111111100000011111, //  |
    0b1100001111111000000111111100001111111000000111111100001111111000, //  |
    0b0001111111000011111110000001111111000011111110000001111111000011, // Z�ro
    0b1111100000011111110000111111100000000001111111111000000000000001, //  |
    0b1111111110000000000000011111111110000000000000011111111110000000 // -'-
  };
  draw usb_logo = 
    0b0001000001110000010111101011110100110011100111000000100000111000;
  
  // Polygons
  point sd_card[16] = { 0, 7, 0, 7, 0, 7, 0, 7, 0, 7, 1, 7, 2, 7, 0, 0 };
  point batterie[32] = { 0, 8, 0, 8, 0, 8, 0, 8, 0, 8, 0, 8, 0, 8, 0, 8, 0, 8, 0, 8, 0, 8, 0, 8, 0, 8, 2, 5, 2, 5, 0, 0 };
  point play[24] = { 0, 20, 1, 19, 2, 18, 3, 17, 4, 16, 5, 15, 6, 14, 7, 13, 8, 12, 9, 11, 10, 10, 0, 0 };
  point pause[12] = { 0, 20, 0, 20, 0, 20, 0, 20, 0, 20, 0, 0 };
  point stop[32] = { 0, 14, 0, 14, 0, 14, 0, 14, 0, 14, 0, 14, 0, 14, 0, 14, 0, 14, 0, 14, 0, 14, 0, 14, 0, 14, 0, 14, 0, 0 };
  point clear_spp[] = { 0, 20, 0, 20, 0, 20, 0, 20, 0, 20, 0, 20, 0, 20, 0, 20, 0, 20, 0, 20, 0, 20, 0, 20, 0, 0 };
  point space[18] = { 0, 9, 0, 9, 0, 9, 0, 9, 0, 9, 0, 9, 0, 9, 0, 9, 0, 0 };

#endif

/*
0b000000011111111110000000
  000000011111111110000000
  0000000111111111,
0b                10000000
  000000011111111110000000
  000111111100001111111000
  00011111,
0b        1100001111111000
  000111111100001111111000
  000111111100001111111000,
0b000111111100001111111000
  000111111100001111111000
  0001111111000011,
0b                11111000
  000111111100001111111000
  000000011111111110000000
  00000001,
0b        1111111110000000
  000000011111111110000000
  000000011111111110000000,
*/