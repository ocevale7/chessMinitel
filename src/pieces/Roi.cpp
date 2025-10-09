#include "../../include/pieces/Roi.h"

Roi::Roi (Game* game, Couple pos, int appartenancePlayer) :
    Piece(game, "Roi", pos, appartenancePlayer) {}

CoupleList* Roi::availableMoves(Plateau* board) {
    CoupleList* coups = new CoupleList();

    return coups;
}