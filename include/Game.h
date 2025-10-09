#ifndef GAME_H
#define GAME_H

#include "tools/CoupleList.h"

class Plateau;
class Piece;

class Game {
    private:

    public:

        Game();

        void start();
        bool checkMove(Plateau* p, Couple old, Couple young);
};

#endif