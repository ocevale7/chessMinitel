#ifndef GAME_H
#define GAME_H

#include "tools/CoupleList.h"
#include "Plateau.h"
#include "Piece.h"
#include "pieces/pieces.h"

class Game {
    private:

    public:

        Plateau* board;

        Game();

        void start();
        bool checkMove(Couple old, Couple young);
};

#endif