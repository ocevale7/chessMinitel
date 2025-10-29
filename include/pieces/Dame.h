#pragma once

#include "../Piece.h"

using namespace std;

class Dame : public Piece {
  public:
    Dame(Game* game, Couple pos, int appartenancePlayer);

    void afficher() override;
    CoupleList* availableMoves(Plateau* board) override;

    int getPoints() const override { return 9; }
};