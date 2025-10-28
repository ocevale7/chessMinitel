#include "../../include/pieces/Fou.h"

Fou::Fou (Game* game, Couple pos, int appartenancePlayer) :
    Piece(game, "Fou", pos, appartenancePlayer) {}

void Fou::afficher() {
  cout << "F" << appartenancePlayer;
}

CoupleList* Fou::availableMoves(Plateau* /*board*/) {
    CoupleList* coups = new CoupleList();

    return coups;
}