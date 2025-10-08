#pragma once

#include "../Piece.h"

using namespace std;

class Dame : public Piece {
  public:
    Couple* availableMoves(Plateau board) override;
};