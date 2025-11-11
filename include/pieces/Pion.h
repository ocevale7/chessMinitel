#pragma once

#include "../Piece.h"

using namespace std;

class Pion : public Piece {
  private:
    Couple coordPromotion;
  public:
    Pion(Game* game, Couple pos, int appartenancePlayer);

    void afficher() override;
    CoupleList* availableMoves(Plateau* board) override;

    void action() override;
};