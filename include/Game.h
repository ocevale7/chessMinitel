#ifndef GAME_H
#define GAME_H

#include "tools/CoupleList.h"
#include "Plateau.h"
#include "Piece.h"
#include "pieces/pieces.h"

using namespace std;

class Game {
    private:
        int currentPlayer;

    public:
        Plateau* board;

        Game();

        void start();
        void play(Couple from, Couple to);
        bool checkMove(Couple old, Couple young);
};

#endif