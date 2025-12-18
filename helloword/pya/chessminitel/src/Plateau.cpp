#include "../include/Plateau.h"
#include "../include/Minitel.h"

#include <stdio.h>
#include <string.h>


Plateau::Plateau(){
    for(unsigned int i = 0; i < width; i++) {
        for(unsigned int j = 0; j < height; j++) {
            plateau[i][j] = nullptr;
        }
    }
}

Plateau::~Plateau(){
    for(unsigned int y = 0; y < height; y++){
        for(unsigned int x = 0; x < width; x++){
            if(plateau[y][x] != nullptr){
                delete plateau[y][x];
            }
        }
    }
}

void Plateau::swap(Couple pos1, Couple pos2){
    Piece* temp = plateau[pos1.y][pos1.x];
    plateau[pos1.y][pos1.x] = plateau[pos2.y][pos2.x];
    plateau[pos2.y][pos2.x] = temp;
}

void Plateau::afficher(){
    for (unsigned int y=0; y<height; y++){
        for (unsigned int x=0; x<width; x++){
            //les coins
            if ((x<3 || x>=width-3) && (y<3 || y>=height-3)){
                cout<<"##";
            }else{
                if (plateau[y][x]){
                    plateau[y][x]->afficher();
                }else{
                    if ((x+y)%2){
                        cout << "XX";
                    }else{
                        cout << "OO";
                    }
                }
            }
            cout << " | ";
        }
        cout << "\n";
        for (unsigned int x=0; x<width; x++){
            cout << "--" << " | ";
        }
        cout << "\n";
    }
}

void Plateau::afficherMinitel(){
    flush_minitel();

    moveCursorXY(5, 4);

    graphic_mode();
    uint8_t* casevide=(uint8_t*)"\x20\x20";

    set_bg_color(FOND_JAUNE);
    for (unsigned int x= 0; x<16; x++){
        if (x>=1 && x<=14){
            text_mode();
            char x_char[3] = {(char)('0' + x / 10), (char)('0' + x % 10), '\0'};
            if (x%2==0){
                set_fg_color(CARACTERE_ROUGE); 
            }else{
                set_fg_color(CARACTERE_MAGENTA);
            }
            write_bytes((uint8_t*)x_char, 2);
        }else{
            graphic_mode();
            write_bytes((uint8_t*)casevide,2);
        }
        
    }
    text_mode();
    retour_ligne();
    for (unsigned int y=0; y<height; y++){
        text_mode();
        moveCursorXY(5,5+y);
        graphic_mode();
        set_bg_color(FOND_JAUNE);
        char y_char[3] = {(char)('0' + y / 10), (char)('0' + y % 10), '\0'};
        if (y%2==0){
            set_fg_color(CARACTERE_ROUGE); 
        }else{
            set_fg_color(CARACTERE_MAGENTA);
        }
        text_mode();
        write_bytes((uint8_t*)y_char, 2);
        graphic_mode();
        // write_bytes((uint8_t*)casevide,2);
        for (unsigned int x=0; x<width; x++){
            //les coins
            
            if ((x<3 || x>=width-3) && (y<3 || y>=height-3)){
                set_bg_color(FOND_ROUGE);
                write_bytes((uint8_t*)casevide,2);
            }else{
                if ((x+y)%2){
                    set_bg_black();
                }else{
                    set_bg_white();
                }
                if (plateau[y][x]){
                    plateau[y][x]->afficherMinitel();
                }else{
                    write_bytes((uint8_t*)casevide,2);
                }
            }
        }
        set_bg_color(FOND_JAUNE);
        if (y%2==0){
            set_fg_color(CARACTERE_ROUGE); 
        }else{
            set_fg_color(CARACTERE_MAGENTA);
        }
        text_mode();
        write_bytes((uint8_t*)y_char, 2);
        graphic_mode();

        retour_ligne();
        
    }

    moveCursorXY(5, 19);
    set_bg_color(FOND_JAUNE);
    for (unsigned int x= 0; x<16; x++){
        if (x>=1 && x<=14){
            text_mode();
            char x_char[3] = {(char)('0' + x / 10), (char)('0' + x % 10), '\0'};
            if (x%2==0){
                set_fg_color(CARACTERE_ROUGE); 
            }else{
                set_fg_color(CARACTERE_MAGENTA);
            }
            write_bytes((uint8_t*)x_char, 2);
        }else{
            graphic_mode();
            write_bytes((uint8_t*)casevide,2);
        }
        
    }
    text_mode();
    
}