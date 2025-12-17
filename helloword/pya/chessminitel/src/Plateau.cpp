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
    graphic_mode();
    uint8_t* casevide=(uint8_t*)"\x20\x20";

    moveCursorXY(3, 4);
    for (unsigned int x= 0; x<16; x++){
        if ((x+y)%2){
            set_bg_black();
        }else{
            set_bg_white();
        }
        write_bytes((uint8_t*)casevide,2);
    }
    retour_ligne();
    for (unsigned int y=0; y<height; y++){
        moveCursorXY(3,5+y);
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
        retour_ligne();
        
    }
    text_mode();
    
}