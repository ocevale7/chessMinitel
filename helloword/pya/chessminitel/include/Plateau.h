#pragma once

using namespace std;

#include "Piece.h"

class Plateau {
    /*
              0   1   2   3   4   5   6   7   8   9   10  11  12  13
              
    0         X   X   X   R_T R_C R_F R_D R_R R_F R_C R_T X   X   X     
    1         X   X   X   R_P R_P R_P R_P R_P R_P R_P R_P X   X   X     
    2         X   X   X   .   .   .   .   .   .   .   .   X   X   X     
    3         G_T G_P .   .   .   .   .   .   .   .   .   .   B_P B_T
    4         G_C G_P .   .   .   .   .   .   .   .   .   .   B_P B_C
    5         G_F G_P .   .   .   .   .   .   .   .   .   .   B_P B_F
    6         G_D G_P .   .   .   .   .   .   .   .   .   .   B_P B_D
    7         G_R G_P .   .   .   .   .   .   .   .   .   .   B_P B_R
    8         G_F G_P .   .   .   .   .   .   .   .   .   .   B_P B_F
    9         G_C G_P .   .   .   .   .   .   .   .   .   .   B_P B_C
    10        G_T G_P .   .   .   .   .   .   .   .   .   .   B_P B_T
    11        X   X   X   .   .   .   .   .   .   .   .   X   X   X     
    12        X   X   X   Y_P Y_P Y_P Y_P Y_P Y_P Y_P Y_P X   X   X     
    13        X   X   X   Y_T Y_C Y_F Y_D Y_R Y_F Y_C Y_T X   X   X     
                
    */
    public :
        static const unsigned int width = 14;
        static const unsigned int height = 14;
        Piece* plateau[height][width];

        Plateau();
        ~Plateau();

        void afficher();
        void afficherMinitel();
        
        void swap(Couple pos1, Couple pos2);

};  