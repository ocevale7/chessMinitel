////////////////////////////////////////////////////////////////////////
/*
   Minitel1B_Hard - Fichier source - Version du 12 mars 2023 à 04h55
   Copyright 2016-2023 - Eric Sérandour
   https://entropie.org/3615/
   
   Remerciements à :
   BorisFR, iodeo

   Documentation utilisée :
   Spécifications Techniques d'Utilisation du Minitel 1B
   http://543210.free.fr/TV/stum1b.pdf

////////////////////////////////////////////////////////////////////////

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program. If not, see <http://www.gnu.org/licenses/>.
*/
////////////////////////////////////////////////////////////////////////

#include "../include/Minitel.h"

void graphic_mode(){
  uart_write(MINITEL_UART, (uint8_t *)SO, 1);
}

void text_mode(){
  uart_write(MINITEL_UART, (uint8_t *)SI, 1);
}

void flush_minitel(){
  uart_write(MINITEL_UART, (uint8_t *)"\x0C", 1);
}

void write_bytes(uint8_t* b, size_t len){
  uart_write(MINITEL_UART, b, len);
}

void set_fg_color(uint8_t* c){
  write_bytes((uint8_t*)ESC,1);
  write_bytes((uint8_t*)c, 1);
}
void set_bg_color(uint8_t* c){
  write_bytes((uint8_t*)ESC,1);
  write_bytes((uint8_t*)c, 1);
}

void set_bg_black(){
  set_bg_color((uint8_t*)FOND_VERT);
}
void set_bg_white(){
  set_bg_color((uint8_t*)FOND_MAGENTA);
}

void set_fg_white(){
  set_fg_color((uint8_t*)CARACTERE_BLANC);
}
void set_fg_black(){
  set_fg_color((uint8_t*)CARACTERE_NOIR);
}