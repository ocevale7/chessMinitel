#pragma once

#include "../Piece.h"

using namespace std;

class Roi : public Piece {
  public:
    Roi(Game* game, Couple pos, int appartenancePlayer);

    CoupleList* availableMoves(Plateau* board) override;
};