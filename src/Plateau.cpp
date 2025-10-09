#include "../include/Plateau.h"

Plateau::Plateau(){

    
}

void Plateau::afficher(){
    for (unsigned int y=0; y<height; y++){
        for (unsigned int x=0; x<width; x++){
            //les coins
            if ((x<3 || x>=width-3) && (y<3 || y>=height-3)){
                cout<<"#";
            }else{
                if (plateau[y][x]){
                    plateau[y][x]->afficher();
                }else{
                    if ((x+y)%2){
                        cout << "■";
                    }else{
                        cout << "□";
                    }
                }
            }
        }
        cout << "\n";
    }
}