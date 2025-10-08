#ifndef PIECE_H
#define PIECE_H

#include "Game.h"
#include <iostream>

using namespace std;

class Piece {

  private:

  public:
    Game* game;
    string nom;
    int x, y;
    int appartenancePlayer;

    Piece(Game* game, string n, int posX, int posY, int appartenancePlayer);

    void deplacer(int newX, int newY);
    virtual CoupleList* availableMoves(Plateau board);
    void afficher();
};

#endif
