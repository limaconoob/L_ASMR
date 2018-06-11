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


#include <p32xxxx.h>
#include <sys/attribs.h>
#include "ssd1306.h"

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
  I2C1CONbits.ON = 1;
  ssd1306_initialize();
  clear_screen();

  // LCD First test
  output_str("Bonjour\n");

  unsigned char k;
  k = 0;
  while (42)
  { I2C1CONbits.ON = 1;
    if (PORTFbits.RF6 == 0 && k == 1)
    { LATFbits.LATF1 ^= 1;
      k = 0; }
    else if (PORTFbits.RF6 == 1)
    { k = 1; }}}
