#ifndef GAME_H
#define GAME_H

#include "Plateau.h"
#include "tools/CoupleList.h"

class Game {
    private:

    public:

        Game();

        void start();
        bool checkMove(Plateau p, Couple old, Couple young);
};

#endif