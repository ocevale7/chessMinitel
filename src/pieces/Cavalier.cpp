#include "../../include/pieces/Cavalier.h"

Cavalier::Cavalier (Game* game, Couple pos, int appartenancePlayer) :
    Piece(game, "Cavalier", pos, appartenancePlayer) {}

CoupleList* Cavalier::availableMoves(Plateau* board) {

    CoupleList* coups = new CoupleList();
    
    if (x + 2 < 14 && y + 1 < 14) {
        if (game->checkMove({x, y}, {x + 2, y + 1})) {
            coups->add(x + 2, y + 1);
        }
    }

    if (x + 2 < 14 && y - 1 > -1) {
        if (game->checkMove({x, y}, {x + 2, y - 1})) {
            coups->add(x + 2, y - 1);
        }
    }

    if (x - 2 > -1 && y + 1 < 14) {
        if (game->checkMove({x, y}, {x - 2, y + 1})) {
            coups->add(x - 2, y + 1);
        }
    }

    if (x - 2 > -1 && y - 1 > -1) {
        if (game->checkMove({x, y}, {x - 2, y - 1})) {
            coups->add(x - 2, y - 1);
        }
    }

    if (x + 1 < 14 && y + 2 < 14) {
        if (game->checkMove({x, y}, {x + 1, y + 2})) {
            coups->add(x + 1, y + 2);
        }
    }

    if (x + 1 < 14 && y - 2 > 0) {
        if (game->checkMove({x, y}, {x + 1, y - 2})) {
            coups->add(x + 1, y - 2);
        }
    }

    if (x - 1 > 0 && y + 2 < 14) {
        if (game->checkMove({x, y}, {x + 1, y + 2})) {
            coups->add(x + 1, y + 2);
        }
    }

    if (x - 1 > 0 && y - 2 > 0) {
        if (game->checkMove({x, y}, {x - 1, y - 2})) {
            coups->add(x - 1, y - 2);
        }
    }

    return coups;
}
