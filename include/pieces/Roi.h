#pragma once

#include "../Piece.h"

using namespace std;

class Roi : public Piece {
  public:
    Roi(Game* game, Couple pos, int appartenancePlayer);

    void afficher() override;
    CoupleList* availableMoves(Plateau* board) override;
    
    void action() override;
};