#pragma once

using namespace std;

#include <iostream>
#include "Piece.h"

class Plateau{
    public :
        static const unsigned int width = 14;
        static const unsigned int height = 14;
        Piece* plateau[height][width];

        Plateau();
        void afficher();
};  