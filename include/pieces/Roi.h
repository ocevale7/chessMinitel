#pragma once

#include "../Piece.h"

using namespace std;

class Roi : public Piece {
  public:
    Couple* availableMoves(Plateau board) override;
};