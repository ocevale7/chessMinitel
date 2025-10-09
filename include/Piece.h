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
    Couple pos;
    int appartenancePlayer;

    Piece(Game* game, string n, Couple pos, int appartenancePlayer);
    virtual ~Piece();

    void deplacer(Couple newPos);
    virtual CoupleList* availableMoves(Plateau* board) = 0;
    void afficher();
};

#endif
