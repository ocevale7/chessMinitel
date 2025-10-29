#pragma once

#include "../Piece.h"

using namespace std;

class Cavalier : public Piece {
  public:
    Cavalier(Game* game, Couple pos, int appartenancePlayer);
    
    void afficher() override;
    CoupleList* availableMoves(Plateau* board) override;

    int getPoints() const override { return 3; }
};