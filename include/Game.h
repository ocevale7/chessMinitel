#ifndef GAME_H
#define GAME_H

#include "tools/CoupleList.h"
#include "Plateau.h"
#include "Piece.h"
#include "pieces/pieces.h"

using namespace std;

class Game {
    private:
        bool move(Couple from, Couple to, int currentPlayer);
    public:
        Plateau* board;
        int points[4] = {0, 0, 0, 0};

        Game();

        void start();
        bool play(Couple from, Couple to, int currentPlayer);
        bool isEchec(int player);
        bool isEchecEtMat(int player);

        void kill(int player);
};

#endif