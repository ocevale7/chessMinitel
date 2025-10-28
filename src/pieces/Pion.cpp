#include "../../include/pieces/Pion.h"

Pion::Pion (Game* game, Couple pos, int appartenancePlayer) :
    Piece(game, "Pion", pos, appartenancePlayer) {}

void Pion::afficher() {
  cout << "P" << appartenancePlayer;
}

CoupleList* Pion::availableMoves(Plateau* /*board*/) {
    CoupleList* coups = new CoupleList();

    return coups;
}