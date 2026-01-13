#include "../include/Plateau.h"
#include "../include/tools/Minitel.h"

#include <stdio.h>
#include <string.h>

#include "../include/pieces/pieces.h"

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

void Plateau::deplacer(Couple from, Couple to){
    plateau[to.y][to.x] = plateau[from.y][from.x];
    plateau[from.y][from.x] = nullptr;
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

    moveCursorXY(4, 3);

    graphic_mode();
    uint8_t* casevide=(uint8_t*)"\x20\x20";

    // affichage indices 
    set_bg_color(FOND_JAUNE);
    write_bytes((uint8_t*)casevide,1);
    for (unsigned int x= 0; x<16; x++){
        if (x>=1 && x<=14){
            text_mode();
            char x_char[3] = {(char)('0' + (x-1) / 10), (char)('0' + (x-1) % 10), '\0'};
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
    write_bytes((uint8_t*)casevide,1);
    text_mode();
    retour_ligne();
    for (unsigned int y=0; y<height; y++){
        text_mode();
        moveCursorXY(4,4+y);
        graphic_mode();
        set_bg_color(FOND_JAUNE);
        write_bytes((uint8_t*)casevide,1);
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
        write_bytes((uint8_t*)casevide,1);
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

    moveCursorXY(4, 18);
    set_bg_color(FOND_JAUNE);
    write_bytes((uint8_t*)casevide,1);
    for (unsigned int x= 0; x<16; x++){
        if (x>=1 && x<=14){
            text_mode();
            char x_char[3] = {(char)('0' + (x-1) / 10), (char)('0' + (x-1) % 10), '\0'};
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
    write_bytes((uint8_t*)casevide,1);
    text_mode();
    
}

void Plateau::updateMinitelCase(Couple pos){
    graphic_mode();
    uint8_t* casevide=(uint8_t*)"\x20\x20";
    unsigned int x = pos.x;
    unsigned int y = pos.y;
    moveCursorXY(7 + x * 2, 5 + y);
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

void Plateau::updateDeplacementMinitel(Couple pos1, Couple pos2){
    updateMinitelCase(pos1);
    updateMinitelCase(pos2);
}

void Plateau::printGuide(){
    graphic_mode();
    moveCursorXY(9,2);
    // affichage d'un pion droit
    set_bg_black();
    set_fg_white(false);
    write_bytes(Pion::getMinitel(false),2);
    // affichage d'un pion sur le cote
    set_bg_white();
    set_fg_black(false);
    write_bytes(Pion::getMinitel(true),2);
    // affichage d'un fou droit
    set_bg_black();
    set_fg_white(false);
    write_bytes(Fou::getMinitel(false),2);
    // affichage d'un fou sur le cote
    set_bg_white();
    set_fg_black(false);
    write_bytes(Fou::getMinitel(true),2);
    // affichage d'une tour droite
    set_bg_black();
    set_fg_white(false);
    write_bytes(Tour::getMinitel(false),2);
    // affichage d'une tour sur le cote
    set_bg_white();
    set_fg_black(false);
    write_bytes(Tour::getMinitel(true),2);
    // affichage d'un cavalier droit
    set_bg_black();
    set_fg_white(false);
    write_bytes(Cavalier::getMinitel(false),2);
    // affichage d'un cavalier sur le cote
    set_bg_white();
    set_fg_black(false);
    write_bytes(Cavalier::getMinitel(true),2);
    // affichage d'une dame droite
    set_bg_black();
    set_fg_white(false);
    write_bytes(Dame::getMinitel(false),2);
    // affichage d'une dame sur le cote
    set_bg_white();
    set_fg_black(false);
    write_bytes(Dame::getMinitel(true),2);
    // affichage d'un roi droit
    set_bg_black();
    set_fg_white(false);
    write_bytes(Roi::getMinitel(false),2);
    // affichage d'un roi sur le cote
    set_bg_white();
    set_fg_black(false);
    write_bytes(Roi::getMinitel(true),2);

    // affichage nom des pieces
    text_mode();
    set_fg_white(true);
    moveCursorXY(9,3);
    write_bytes((uint8_t*)" P.  F.  T.  C.  D.  R. ",24);
}
