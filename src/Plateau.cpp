#include "../include/Plateau.h"

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
    cout << "     ";
    for (unsigned int x=0; x<width; x++){
        if (x < 10) cout << " ";
        cout << x << " | ";
    }
    cout << "\n";
    cout << "     ";
    for (unsigned int x=0; x<width; x++){
        cout << "--" << " | ";
    }
    cout << "\n";

    for (unsigned int y=0; y<height; y++){
        if (y < 10) cout << " ";
        cout << y << " | ";
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
        if (y < 10) cout << " ";
        cout << y << " | ";
        cout << "\n     ";
        for (unsigned int x=0; x<width; x++){
            cout << "--" << " | ";
        }
        cout << "\n";
    }
    cout << "     ";
    for (unsigned int x=0; x<width; x++){
        if (x < 10) cout << " ";
        cout << x << " | ";
    }
    cout << "\n";
}