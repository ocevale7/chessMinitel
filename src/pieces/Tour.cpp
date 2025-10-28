#include "../../include/pieces/Tour.h"

Tour::Tour (Game* game, Couple pos, int appartenancePlayer) :
    Piece(game, "Tour", pos, appartenancePlayer) {}

void Tour::afficher() {
  cout << "T" << appartenancePlayer;
}

CoupleList* Tour::availableMoves(Plateau* /*board*/) {
    CoupleList* coups = new CoupleList();

    return coups;
}