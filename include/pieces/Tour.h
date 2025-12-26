#pragma once

#include "../Piece.h"

using namespace std;

class Tour : public Piece {
  public:
    Tour(Game* game, Couple pos, int appartenancePlayer);

    void afficher() override;
    void afficherMinitel() override;
    CoupleList* availableMoves(Plateau* board) override;
    
    void action() override;
};