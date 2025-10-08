#pragma once

#include "../Piece.h"

using namespace std;

class Pion : public Piece {
  public:
    Couple* availableMoves(Plateau board) override;
};