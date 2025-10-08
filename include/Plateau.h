#pragma once

using namespace std;

#include "Piece.h"

class Plateau {
    /*
                        R_T R_C R_F R_D R_R R_F R_C R_T            
                        R_P R_P R_P R_P R_P R_P R_P R_P            
                        .   .   .   .   .   .   .   .              
            G_T G_P .   .   .   .   .   .   .   .   .   .   B_P B_T
            G_C G_P .   .   .   .   .   .   .   .   .   .   B_P B_C
            G_F G_P .   .   .   .   .   .   .   .   .   .   B_P B_F
            G_D G_P .   .   .   .   .   .   .   .   .   .   B_P B_D
            G_R G_P .   .   .   .   .   .   .   .   .   .   B_P B_R
            G_F G_P .   .   .   .   .   .   .   .   .   .   B_P B_F
            G_C G_P .   .   .   .   .   .   .   .   .   .   B_P B_C
            G_T G_P .   .   .   .   .   .   .   .   .   .   B_P B_T
                        .   .   .   .   .   .   .   .              
                        Y_P Y_P Y_P Y_P Y_P Y_P Y_P Y_P            
                        Y_T Y_C Y_F Y_D Y_R Y_F Y_C Y_T            
                
    */
    public :
        static const unsigned int width = 14;
        static const unsigned int height = 14;
        Piece* plateau[height][width];

        Plateau();
        void afficher();
};  