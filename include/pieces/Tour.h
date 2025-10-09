#pragma once

#include "../Piece.h"

using namespace std;

class Tour : public Piece {
  public:
    Tour(Game* game, Couple pos, int appartenancePlayer);

    CoupleList* availableMoves(Plateau* board) override;
};