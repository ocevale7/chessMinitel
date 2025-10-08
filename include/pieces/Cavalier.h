#pragma once

#include "../Piece.h"

using namespace std;

class Cavalier : public Piece {
  public:
    CoupleList* availableMoves(Plateau board) override;
};