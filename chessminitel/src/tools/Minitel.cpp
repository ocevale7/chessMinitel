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

#include "../include/tools/Minitel.h"
#include <string.h>

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
  set_bg_color((uint8_t*)FOND_MAGENTA);
}
void set_bg_white(){
  set_bg_color((uint8_t*)FOND_VERT);
}

void set_fg_white(bool darker){
  if (!darker) set_fg_color((uint8_t*)CARACTERE_BLANC);
  else set_fg_color((uint8_t*)CARACTERE_CYAN);
}
void set_fg_black(bool lighter){
  if (!lighter) set_fg_color((uint8_t*)CARACTERE_NOIR);
  else set_fg_color((uint8_t*)CARACTERE_ROUGE);
}

void retour_ligne(){
  uint8_t* new_line = (uint8_t*)"\x0D\x0A";
  write_bytes(new_line,2);
}

void writeBytesP(int n) {
  // Pn, Pr, Pc : Voir remarques p.95 et 96
  if (n<=9) {
    char n1 = '\x30' + n;
    write_bytes((uint8_t*)&n1,1);
  }
  else {
    char n1 = '\x30' + n/10;
    char n2 = '\x30' + n%10;
    write_bytes((uint8_t*)&n1,1);
    write_bytes((uint8_t*)&n2,1);
  }
}

void cursor() {
  uint8_t con= CON;
  write_bytes(&con, 1);
}

void moveCursorXY(int x, int y) {
  cursor();
  uint8_t* CSI_ = (uint8_t*)"\x1B\x5B";
  write_bytes(CSI_,2);   
  writeBytesP(y);   // Pr : Voir section Private ci-dessous
  write_bytes((uint8_t*)"\x3B",1);
  writeBytesP(x);   // Pc : Voir section Private ci-dessous
  write_bytes((uint8_t*)"\x48",1);
  text_mode();
}

void outMinitel(const char* str) {
  moveCursorXY(0,0);
  uint8_t cleanCode = 0x18;
  write_bytes(&cleanCode, 1);
  
  write_bytes((uint8_t*)str, strlen(str));
}

/*
 Code fait par PY Antonin pour le cours d'objet connecté de 3A ENSIMAG 2025-2026
*/

int askIntMinitel(const char* label, int x, int y) {
    moveCursorXY(0, y);
    write_bytes((uint8_t*)label, strlen(label));
    
    char buffer[3] = {0};
    int i = 0;
    
    // On place le curseur juste après le label (adapté à tes coordonnées 37)
    moveCursorXY(x, y);

    while (i < 2) {
        msg_t msg;
        msg_receive(&msg);
        char c = (char)msg.content.value;

        if (c >= '0' && c <= '9') {
            buffer[i++] = c;
            //write_bytes((uint8_t*)&c, 1); // Écho du caractère saisi
        }
    }
    
    return atoi(buffer);
}

void recupInputMinitel(Couple& from, Couple& to) {
    set_fg_white(false);

    // 1. Récupération du point de départ
    from.x = askIntMinitel("Entrer cord X de la piece a bouger: ..", 37, 23);
    from.y = askIntMinitel("Entrer cord Y de la piece a bouger: ..", 37, 24);

    // on print from
    std::string s_from = std::string("Depart     : (") + std::to_string(from.x) + ", " + std::to_string(from.y) + ")\n";
    outMinitel(s_from.c_str());

    // 2. Récupération de la destination
    to.x = askIntMinitel("Entrer cord X de la case dest     : ..", 37, 23);
    to.y = askIntMinitel("Entrer cord Y de la case dest     : ..", 37, 24);

    // on print to
    std::string s_to = std::string("Destination : (") + std::to_string(to.x) + ", " + std::to_string(to.y) + ")\n";
    outMinitel(s_to.c_str());
}