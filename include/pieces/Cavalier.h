#pragma once

#include "../Piece.h"

using namespace std;

class Cavalier : public Piece {
  public:
    Cavalier(Game* game, Couple pos, int appartenancePlayer);

    CoupleList* availableMoves(Plateau* board) override;
};