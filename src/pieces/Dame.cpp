#include "../../include/pieces/Dame.h"

Dame::Dame (Game* game, Couple pos, int appartenancePlayer) :
    Piece(game, "Dame", pos, appartenancePlayer) {}

CoupleList* Dame::availableMoves(Plateau* board) {
    CoupleList* coups = new CoupleList();

    return coups;
}
