#include "../include/Plateau.h"
#include "../include/tools/Minitel.h"

#include <stdio.h>
#include <string.h>

#include "../include/pieces/pieces.h"

#include <sstream>
#include <iomanip>

#include "../include/Game.h"

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
    //flush_minitel();

    moveCursorXY(4, 4);

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
        moveCursorXY(4,5+y);
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
                set_bg_color(FOND_BLEU);
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

    moveCursorXY(4, 19);
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
    graphic_mode();
    if ((x<3 || x>=width-3) && (y<3 || y>=height-3)){
        set_bg_color(FOND_BLEU);
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
    graphic_mode();
    // affichage d'un pion droit
    set_bg_black();
    set_fg_white(true);
    write_bytes(Pion::getMinitel(false),2);
    // affichage d'un pion sur le cote
    set_bg_white();
    set_fg_black(true);
    write_bytes(Pion::getMinitel(true),2);
    // affichage d'un fou droit
    set_bg_black();
    set_fg_white(true);
    write_bytes(Fou::getMinitel(false),2);
    // affichage d'un fou sur le cote
    set_bg_white();
    set_fg_black(true);
    write_bytes(Fou::getMinitel(true),2);
    // affichage d'une tour droite
    set_bg_black();
    set_fg_white(true);
    write_bytes(Tour::getMinitel(false),2);
    // affichage d'une tour sur le cote
    set_bg_white();
    set_fg_black(true);
    write_bytes(Tour::getMinitel(true),2);
    // affichage d'un cavalier droit
    set_bg_black();
    set_fg_white(true);
    write_bytes(Cavalier::getMinitel(false),2);
    // affichage d'un cavalier sur le cote
    set_bg_white();
    set_fg_black(true);
    write_bytes(Cavalier::getMinitel(true),2);
    // affichage d'une dame droite
    set_bg_black();
    set_fg_white(true);
    write_bytes(Dame::getMinitel(false),2);
    // affichage d'une dame sur le cote
    set_bg_white();
    set_fg_black(true);
    write_bytes(Dame::getMinitel(true),2);
    // affichage d'un roi droit
    set_bg_black();
    set_fg_white(true);
    write_bytes(Roi::getMinitel(false),2);
    // affichage d'un roi sur le cote
    set_bg_white();
    set_fg_black(true);
    write_bytes(Roi::getMinitel(true),2);

    // affichage nom des pieces
    text_mode();
    set_fg_white(true);
    moveCursorXY(9,3);
    write_bytes((uint8_t*)" P.  F.  T.  C.  D.  R. ",24);
}


void Plateau::updateCorners(Game *game){
    
    uint8_t* arrowplayer0 = (uint8_t*)"\x22\x27";
    uint8_t* arrowplayer1 = (uint8_t*)"\x28\x35";
    uint8_t* arrowplayer2 = (uint8_t*)"\x78\x30";
    uint8_t* arrowplayer3 = (uint8_t*)"\x6A\x24";
    
    
    // corner player 3
    graphic_mode();
    moveCursorXY(11, 5);
    graphic_mode();
    set_bg_color(FOND_BLEU);
    set_fg_white(true);
    write_bytes((uint8_t*)arrowplayer3,2);
    moveCursorXY(8,7);
    std::ostringstream ossp3;
    ossp3 << "3:" << std::setw(3) << std::setfill('0') << game->points[3];
    std::string scorep3 = ossp3.str();
    text_mode();
    write_bytes((uint8_t*)scorep3.c_str(),strlen(scorep3.c_str()));

    // corner player 0

    moveCursorXY(33, 7);
    graphic_mode();
    set_bg_color(FOND_BLEU);
    write_bytes((uint8_t*)arrowplayer0,2);
    moveCursorXY(30,5);
    std::ostringstream ossp0;
    ossp0 << "0:" << std::setw(3) << std::setfill('0') << game->points[0];
    std::string scorep0 = ossp0.str();
    text_mode();
    write_bytes((uint8_t*)scorep0.c_str(),strlen(scorep0.c_str()));
    

    // corner player 2

    moveCursorXY(7, 16);
    graphic_mode();
    set_bg_color(FOND_BLEU);
    write_bytes((uint8_t*)arrowplayer2,2);
    moveCursorXY(8,18);
    std::ostringstream ossp2;
    ossp2 << "2:" << std::setw(3) << std::setfill('0') << game->points[2];
    std::string scorep2 = ossp2.str();
    text_mode();
    write_bytes((uint8_t*)scorep2.c_str(),strlen(scorep2.c_str()));

    // corner player 1

    moveCursorXY(29, 18);
    graphic_mode();
    set_bg_color(FOND_BLEU);
    write_bytes((uint8_t*)arrowplayer1,2);
    moveCursorXY(30,16);
    std::ostringstream ossp1;
    ossp1 << "1:" << std::setw(3) << std::setfill('0') << game->points[1];
    std::string scorep1 = ossp1.str();
    text_mode();
    write_bytes((uint8_t*)scorep1.c_str(),strlen(scorep1.c_str()));
    
    
    text_mode();
}

void Plateau::printBackground(){
    graphic_mode();
    uint8_t* casevide=(uint8_t*)"\x20";
    for (unsigned int y=1; y<=20; y++){
        moveCursorXY(1,y);
        graphic_mode();
        if (y == 2){
            for (unsigned int x=0; x<8; x++){
                write_bytes((uint8_t*)casevide,1);
            }
            moveCursorXY(33,y);
            graphic_mode();
            for (unsigned int x=33; x<=40; x++){
                write_bytes((uint8_t*)casevide,1);
            }
        }else if (y<=3 || y>=20){
            set_bg_color(FOND_BLEU);
            for (unsigned int x=0; x<40; x++){
                write_bytes((uint8_t*)casevide,1);
            }
        }else if (y>=4 && y<=19){
            set_bg_color(FOND_BLEU);
            for (unsigned int x=0; x<3; x++){
                write_bytes((uint8_t*)casevide,1);
            }
            moveCursorXY(38,y);
            graphic_mode();
            for (unsigned int x=38; x<=40; x++){
                write_bytes((uint8_t*)casevide,1);
            }
        }
    }
}