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
        void move(Couple from, Couple to);
    public:
        Plateau* board;
        int points[4] = {0, 0, 0, 0};

        Game();

        void start();
        void play(Couple from, Couple to);
        bool isEchec(int player);
        bool isEchecEtMat(int player);
        string recupInputMinitel();
};

#endif