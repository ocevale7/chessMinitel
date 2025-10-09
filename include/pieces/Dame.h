#pragma once

#include "../Piece.h"

using namespace std;

class Dame : public Piece {
  public:
    Dame(Game* game, Couple pos, int appartenancePlayer);

    CoupleList* availableMoves(Plateau* board) override;
};