#pragma once

#include "../Piece.h"

using namespace std;

class Fou : public Piece {
  public:
    Couple* availableMoves(Plateau board) override;
};