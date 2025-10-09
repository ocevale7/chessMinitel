#pragma once

#include "../Piece.h"

using namespace std;

class Pion : public Piece {
  public:
    Pion(Game* game, Couple pos, int appartenancePlayer);

    CoupleList* availableMoves(Plateau* board) override;
};