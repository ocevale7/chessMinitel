#pragma once

#include "../Piece.h"

using namespace std;

class Dame : public Piece {
  public:
    Dame(Game* game, Couple pos, int appartenancePlayer);

    void afficher() override;
    void afficherMinitel() override;
    CoupleList* availableMoves(Plateau* board) override;
    
    void action() override;
};