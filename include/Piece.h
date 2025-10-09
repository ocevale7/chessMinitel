#ifndef PIECE_H
#define PIECE_H

#include <iostream>
#include "tools/CoupleList.h"

using namespace std;

class Game;
class Plateau;

class Piece {

  private:

  public:
    Game* game;
    string nom;
    int x, y;
    int appartenancePlayer;

    Piece(Game* game, string n, int posX, int posY, int appartenancePlayer);
    virtual ~Piece();

    void deplacer(int newX, int newY);
    virtual CoupleList* availableMoves(Plateau board) = 0;
    void afficher();
};

#endif
