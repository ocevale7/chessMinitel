#ifndef GAME_H
#define GAME_H

#include "tools/CoupleList.h"
#include "Plateau.h"
#include "Piece.h"
#include "pieces/pieces.h"

using namespace std;

#define BONUS_POINTS_MAT            20
#define BONUS_POINTS_SELF_PAT       20
#define BONUS_POINTS_OTHER_PAT      10

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
        bool isPat(int player);

        int checkMatAndPat(int currentPlayer, int players[4]);

        void kill(int player);

        string recupInputMinitel();
};

#endif