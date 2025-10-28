#pragma once

#include "../Piece.h"

using namespace std;

class Fou : public Piece {
  public:
    Fou(Game* game, Couple pos, int appartenancePlayer);

    void afficher() override;
    CoupleList* availableMoves(Plateau* board) override;
};