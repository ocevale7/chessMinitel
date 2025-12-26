#ifndef PIECE_H
#define PIECE_H

#include <iostream>
#include "tools/CoupleList.h"
#include "Minitel.h"

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
    int points;

    Piece(Game* game, string n, Couple pos, int appartenancePlayer);
    virtual ~Piece();

    void deplacer(Couple newPos);
    virtual CoupleList* availableMoves(Plateau* board) = 0;
    virtual void afficher() = 0;
    virtual void afficherMinitel() = 0;

    virtual void action() = 0;
};

#endif
