#include "../../include/pieces/Cavalier.h"
#include "../../include/Game.h"

Cavalier::Cavalier (Game* game, Couple pos, int appartenancePlayer) :
    Piece(game, "Cavalier", pos, appartenancePlayer) {}

void Cavalier::afficher() {
  cout << "\033[3" << appartenancePlayer + 1 << "m" << "C" << appartenancePlayer << "\033[0m";
}

CoupleList* Cavalier::availableMoves(Plateau* board) {

    CoupleList* coups = new CoupleList();

    Couple newPos = pos + Couple(2, 1);

    if ((newPos.x < 14 && newPos.x > 0 && newPos.y < 11 && newPos.y > 2) || (newPos.x < 11 && newPos.x > 2 && ((newPos.y < 3 && newPos.y > -1) || (newPos.y < 14 && newPos.y > 10)))) {
        if (board->plateau[newPos.y][newPos.x] != nullptr) {
            if (board->plateau[newPos.y][newPos.x]->appartenancePlayer != appartenancePlayer) {
                coups->add(newPos);
            }
        } else {
            coups->add(newPos);
        }
    }
    
    newPos = pos + Couple(2, -1);

    if ((newPos.x < 14 && newPos.x > 0 && newPos.y < 11 && newPos.y > 2) || (newPos.x < 11 && newPos.x > 2 && ((newPos.y < 3 && newPos.y > -1) || (newPos.y < 14 && newPos.y > 10)))) {
        if (board->plateau[newPos.y][newPos.x] != nullptr) {
            if (board->plateau[newPos.y][newPos.x]->appartenancePlayer != appartenancePlayer) {
                coups->add(newPos);
            }
        } else {
            coups->add(newPos);
        }
    }
    
    
    newPos = pos + Couple(-2, 1);

    if ((newPos.x < 14 && newPos.x > 0 && newPos.y < 11 && newPos.y > 2) || (newPos.x < 11 && newPos.x > 2 && ((newPos.y < 3 && newPos.y > -1) || (newPos.y < 14 && newPos.y > 10)))) {
        if (board->plateau[newPos.y][newPos.x] != nullptr) {
            if (board->plateau[newPos.y][newPos.x]->appartenancePlayer != appartenancePlayer) {
                coups->add(newPos);
            }
        } else {
            coups->add(newPos);
        }
    }

    newPos = pos + Couple(-2, -1);

    if ((newPos.x < 14 && newPos.x > 0 && newPos.y < 11 && newPos.y > 2) || (newPos.x < 11 && newPos.x > 2 && ((newPos.y < 3 && newPos.y > -1) || (newPos.y < 14 && newPos.y > 10)))) {
        if (board->plateau[newPos.y][newPos.x] != nullptr) {
            if (board->plateau[newPos.y][newPos.x]->appartenancePlayer != appartenancePlayer) {
                coups->add(newPos);
            }
        } else {
            coups->add(newPos);
        }
    }

    newPos = pos + Couple(1, 2);

    if ((newPos.x < 14 && newPos.x > 0 && newPos.y < 11 && newPos.y > 2) || (newPos.x < 11 && newPos.x > 2 && ((newPos.y < 3 && newPos.y > -1) || (newPos.y < 14 && newPos.y > 10)))) {
        if (board->plateau[newPos.y][newPos.x] != nullptr) {
            if (board->plateau[newPos.y][newPos.x]->appartenancePlayer != appartenancePlayer) {
                coups->add(newPos);
            }
        } else {
            coups->add(newPos);
        }
    }

    newPos = pos + Couple(1, -2);

    if ((newPos.x < 14 && newPos.x > 0 && newPos.y < 11 && newPos.y > 2) || (newPos.x < 11 && newPos.x > 2 && ((newPos.y < 3 && newPos.y > -1) || (newPos.y < 14 && newPos.y > 10)))) {
        if (board->plateau[newPos.y][newPos.x] != nullptr) {
            if (board->plateau[newPos.y][newPos.x]->appartenancePlayer != appartenancePlayer) {
                coups->add(newPos);
            }
        } else {
            coups->add(newPos);
        }
    }

    newPos = pos + Couple(-1, 2);

    if ((newPos.x < 14 && newPos.x > 0 && newPos.y < 11 && newPos.y > 2) || (newPos.x < 11 && newPos.x > 2 && ((newPos.y < 3 && newPos.y > -1) || (newPos.y < 14 && newPos.y > 10)))) {
        if (board->plateau[newPos.y][newPos.x] != nullptr) {
            if (board->plateau[newPos.y][newPos.x]->appartenancePlayer != appartenancePlayer) {
                coups->add(newPos);
            }
        } else {
            coups->add(newPos);
        }
    }

    newPos = pos + Couple(- 1, -2);

    if ((newPos.x < 14 && newPos.x > 0 && newPos.y < 11 && newPos.y > 2) || (newPos.x < 11 && newPos.x > 2 && ((newPos.y < 3 && newPos.y > -1) || (newPos.y < 14 && newPos.y > 10)))) {
        if (board->plateau[newPos.y][newPos.x] != nullptr) {
            if (board->plateau[newPos.y][newPos.x]->appartenancePlayer != appartenancePlayer) {
                coups->add(newPos);
            }
        } else {
            coups->add(newPos);
        }
    }

    return coups;
}
