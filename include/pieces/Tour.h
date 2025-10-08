#pragma once

#include "../Piece.h"

using namespace std;

class Tour : public Piece {
  public:
    Couple* availableMoves(Plateau board) override;
};