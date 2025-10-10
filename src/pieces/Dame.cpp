#include "../../include/pieces/Dame.h"
#include "../../include/Game.h"

Dame::Dame (Game* game, Couple pos, int appartenancePlayer) :
    Piece(game, "Dame", pos, appartenancePlayer) {}

CoupleList* Dame::availableMoves(Plateau* board) {
    CoupleList* coups = new CoupleList();

    Couple newPos = pos;


    // Parcous verticale de la pos vers le 14
    int limit = (pos.x >= 3 && pos.x <= 10) ? 14 - pos.y: 11 - pos.y;
    for(int i = 1; i < limit; i++) {
        newPos = pos + Couple(0, i);
        if (board->plateau[newPos.y][newPos.x] != nullptr) {
            if (board->plateau[newPos.y][newPos.x]->appartenancePlayer != appartenancePlayer) {
                if (game->checkMove(pos, newPos)) {
                    cout<<"1. Coup ajouté (entré dans le if): ("<<newPos.x<<", "<<newPos.y<<")\n";
                    coups->add(newPos);
                }
            }
            break;
        } else {
            if (game->checkMove(pos, newPos)) {
                cout<<"1. Coup ajouté : ("<<newPos.x<<", "<<newPos.y<<")\n";
                coups->add(newPos);
            }
        }
    }

    // Parcous verticale de la pos vers le 0
    limit = (pos.x >= 3 && pos.x <= 10) ? pos.y + 1 : pos.y - 2;
    for(int i = 1; i < limit ; i++) {
        newPos = pos + Couple(0, -i);
        if (board->plateau[newPos.y][newPos.x] != nullptr) {
            if (board->plateau[newPos.y][newPos.x]->appartenancePlayer != appartenancePlayer) {
                if (game->checkMove(pos, newPos)) {
                    cout<<"2. Coup ajouté (entré dans le if): ("<<newPos.x<<", "<<newPos.y<<")\n";
                    coups->add(newPos);
                }
            }
             break;
        } else {
            if (game->checkMove(pos, newPos)) {
                cout<<"2. Coup ajouté : ("<<newPos.x<<", "<<newPos.y<<")\n";
                coups->add(newPos);
            }
        }
    }

    // Parcous horizontal de la pos vers le 14

    limit = (pos.y >= 3 && pos.y <= 10) ? 14 - pos.x: 11 - pos.x;
    for(int i = 1; i < limit; i++) {
        newPos = pos + Couple(i, 0);
        if (board->plateau[newPos.y][newPos.x] != nullptr) {
            if (board->plateau[newPos.y][newPos.x]->appartenancePlayer != appartenancePlayer) {
                if (game->checkMove(pos, newPos)) {
                    coups->add(newPos);
                }
            }
            break;
        } else {
            if (game->checkMove(pos, newPos)) {
                coups->add(newPos);
            }
        }
    }

    // Parcous horizontal de la pos vers le 0

    limit = (pos.y >= 3 && pos.y <= 10) ? pos.x + 1 : pos.x - 2;
    for(int i = 1; i < limit ; i++) {
        newPos = pos + Couple(-i, 0);
        if (board->plateau[newPos.y][newPos.x] != nullptr) {
            if (board->plateau[newPos.y][newPos.x]->appartenancePlayer != appartenancePlayer) {
                if (game->checkMove(pos, newPos)) {
                    coups->add(newPos);
                }
            }
             break;
        } else {
            if (game->checkMove(pos, newPos)) {
                coups->add(newPos);
            }
        }
    }

    // Diagonales

    return coups;
}
