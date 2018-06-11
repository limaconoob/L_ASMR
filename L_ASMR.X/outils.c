/*
**    outils.c
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

#ifndef strlen
  int strlen(char *str)
  { int i = 0;
    while (*(str + i))
    { i += 1; }
    return (i); }
#endif

#ifndef memdel
  void memdel(void** data)
  { *data = (void*)0; }
#endif

#ifndef memset
  void *memset(void *b, int c, unsigned long len)
  { char *str;
    str = (char*)b;
    while (len > 0)
    { *str = c;
     str += 1;
     len -= 1; }}
#endif










