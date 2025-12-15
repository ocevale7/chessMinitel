#pragma once

#include "../Piece.h"

using namespace std;

class Pion : public Piece {
  public:
    Pion(Game* game, Couple pos, int appartenancePlayer);

    void afficher() override;
    void afficherMinitel() override;
    CoupleList* availableMoves(Plateau* board) override;

    int getPoints() const override { return 1; }
};