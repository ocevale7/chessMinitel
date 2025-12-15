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
    // for (unsigned int y=0; y<height; y++){
    //     for (unsigned int x=0; x<width; x++){
    //         //les coins
    //         if ((x<3 || x>=width-3) && (y<3 || y>=height-3)){
    //             //cout<<"##";
    //             uart_write(MINITEL_UART, (uint8_t *)"\x0C", 1);
    //         }else{
    //             if (plateau[y][x]){
    //                 plateau[y][x]->afficher();
    //             }else{
    //                 if ((x+y)%2){
    //                     cout << "XX";
    //                 }else{
    //                     cout << "OO";
    //                 }
    //             }
    //         }
    //         cout << " | ";
    //     }
    //     cout << "\n";
    //     for (unsigned int x=0; x<width; x++){
    //         cout << "--" << " | ";
    //     }
    //     cout << "\n";
    // }
    char pion[3] = "\x78\x30";
    //flush
    flush_minitel();
    graphic_mode();
    //affiche un pion noir sur fond noir
    for (int i=0; i<50; i++){
        set_fg_color(CARACTERE_NOIR);
        set_bg_color(FOND_VERT);
        write_bytes((uint8_t *)&pion, 2);

        //affiche un pion noir sur fond blanc
        set_fg_color(CARACTERE_NOIR);
        set_bg_color(FOND_MAGENTA);
        write_bytes((uint8_t *)&pion, 2);

        //affiche un pion blanc sur fond noir
        set_fg_color(CARACTERE_BLANC);
        set_bg_color(FOND_VERT);
        write_bytes((uint8_t *)&pion, 2);

        //affiche un pion blanc sur fond blanc
        set_fg_color(CARACTERE_BLANC);
        set_bg_color(FOND_MAGENTA);
        write_bytes((uint8_t *)&pion, 2);

        
    }
    text_mode();
    
}