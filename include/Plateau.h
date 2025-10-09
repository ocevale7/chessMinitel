#pragma once

using namespace std;

#include "Piece.h"

class Plateau {
    /*
              0   1   2   3   4   5   6   7   8   9   10  11  12  13
              
    0                     R_T R_C R_F R_D R_R R_F R_C R_T            
    1                     R_P R_P R_P R_P R_P R_P R_P R_P            
    2                     .   .   .   .   .   .   .   .              
    3         G_T G_P .   .   .   .   .   .   .   .   .   .   B_P B_T
    4         G_C G_P .   .   .   .   .   .   .   .   .   .   B_P B_C
    5         G_F G_P .   .   .   .   .   .   .   .   .   .   B_P B_F
    6         G_D G_P .   .   .   .   .   .   .   .   .   .   B_P B_D
    7         G_R G_P .   .   .   .   .   .   .   .   .   .   B_P B_R
    8         G_F G_P .   .   .   .   .   .   .   .   .   .   B_P B_F
    9         G_C G_P .   .   .   .   .   .   .   .   .   .   B_P B_C
    10        G_T G_P .   .   .   .   .   .   .   .   .   .   B_P B_T
    11                    .   .   .   .   .   .   .   .              
    12                    Y_P Y_P Y_P Y_P Y_P Y_P Y_P Y_P            
    13                    Y_T Y_C Y_F Y_D Y_R Y_F Y_C Y_T            
                
    */
    public :
        static const unsigned int width = 14;
        static const unsigned int height = 14;
        Piece* plateau[height][width];

        Plateau();
        void afficher();
};  