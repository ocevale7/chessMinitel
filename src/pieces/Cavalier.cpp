#include "../../include/pieces/Cavalier.h"
#include "../../include/Game.h"

Cavalier::Cavalier (Game* game, Couple pos, int appartenancePlayer) :
    Piece(game, "Cavalier", pos, appartenancePlayer) {}

CoupleList* Cavalier::availableMoves(Plateau*) {

    CoupleList* coups = new CoupleList();

    Couple newPos = pos + Couple(2, 1);
    if (newPos.x < 14 && newPos.y < 14) {
        if (game->checkMove(pos, newPos)) {
            coups->add(newPos);
        }
    }

    newPos = pos + Couple(2, -1);
    if (pos.x + 2 < 14 && pos.y - 1 > -1) {
        if (game->checkMove(pos, newPos)) {
            coups->add(newPos);
        }
    }
    
    newPos = pos + Couple(-2, 1);
    if (pos.x - 2 > -1 && pos.y + 1 < 14) {
        if (game->checkMove(pos, newPos)) {
            coups->add(newPos);
        }
    }

    newPos = pos + Couple(-2, -1);
    if (pos.x - 2 > -1 && pos.y - 1 > -1) {
        if (game->checkMove(pos, newPos)) {
            coups->add(newPos);
        }
    }

    newPos = pos + pos + Couple(1, 2);
    if (pos.x + 1 < 14 && pos.y + 2 < 14) {
        if (game->checkMove(pos, newPos)) {
            coups->add(newPos);
        }
    }

    newPos = pos + Couple(1, -2);
    if (pos.x + 1 < 14 && pos.y - 2 > 0) {
        if (game->checkMove(pos, newPos)) {
            coups->add(newPos);
        }
    }

    newPos = pos + Couple(-1, 2);
    if (pos.x - 1 > 0 && pos.y + 2 < 14) {
        if (game->checkMove(pos, newPos)) {
            coups->add(newPos);
        }
    }

    newPos = pos + Couple(- 1, -2);
    if (pos.x - 1 > 0 && pos.y - 2 > 0) {
        if (game->checkMove(pos, newPos)) {
            coups->add(newPos);
        }
    }

    return coups;
}
