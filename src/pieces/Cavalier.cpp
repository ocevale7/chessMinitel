#include "../../include/pieces/Cavalier.h"
#include "../../include/Game.h"

Cavalier::Cavalier (Game* game, Couple pos, int appartenancePlayer) :
    Piece(game, "Cavalier", pos, appartenancePlayer) {}

CoupleList* Cavalier::availableMoves(Plateau* board) {

    CoupleList* coups = new CoupleList();

    Couple newPos = pos + Couple(2, 1);
    bool ok = true;

    if (newPos.x < 14 && newPos.y < 14) {
        if (board->plateau[newPos.y][newPos.x] != nullptr) {
            ok = board->plateau[newPos.y][newPos.x]->appartenancePlayer != appartenancePlayer;
        }
        if (ok && game->checkMove(pos, newPos)) {
            coups->add(newPos);
        }
    }
    
    newPos = pos + Couple(2, -1);
    ok = true;

    if (newPos.x < 14 && newPos.y > -1) {
        if (board->plateau[newPos.y][newPos.x] != nullptr) {
            ok = board->plateau[newPos.y][newPos.x]->appartenancePlayer != appartenancePlayer;
        }
        if (ok && game->checkMove(pos, newPos)) {
            coups->add(newPos);
        }
    }
    
    
    newPos = pos + Couple(-2, 1);
    ok = true;

    if (newPos.x > -1 && newPos.y < 14) {
        if (board->plateau[newPos.y][newPos.x] != nullptr) {
            ok = board->plateau[newPos.y][newPos.x]->appartenancePlayer != appartenancePlayer;
        }
        if (ok && game->checkMove(pos, newPos)) {
            coups->add(newPos);
        }
    }

    newPos = pos + Couple(-2, -1);
    ok = true;

    if (newPos.x > -1 && newPos.y > -1) {
        if (board->plateau[newPos.y][newPos.x] != nullptr) {
            ok = board->plateau[newPos.y][newPos.x]->appartenancePlayer != appartenancePlayer;
        }
        if (ok && game->checkMove(pos, newPos)) {
            coups->add(newPos);
        }
    }

    newPos = pos + Couple(1, 2);
    ok = true;

    if (newPos.x < 14 && newPos.y < 14) {
        if (board->plateau[newPos.y][newPos.x] != nullptr) {
            ok = board->plateau[newPos.y][newPos.x]->appartenancePlayer != appartenancePlayer;
        }
        if (ok && game->checkMove(pos, newPos)) {
            coups->add(newPos);
        }
    }

    newPos = pos + Couple(1, -2);
    ok = true;

    if (newPos.x < 14 && newPos.y > 0) {
        if (board->plateau[newPos.y][newPos.x] != nullptr) {
            ok = board->plateau[newPos.y][newPos.x]->appartenancePlayer != appartenancePlayer;
        }
        if (ok && game->checkMove(pos, newPos)) {
            coups->add(newPos);
        }
    }

    newPos = pos + Couple(-1, 2);
    ok = true;

    if (newPos.x > 0 && newPos.y < 14) {
        if (board->plateau[newPos.y][newPos.x] != nullptr) {
            ok = board->plateau[newPos.y][newPos.x]->appartenancePlayer != appartenancePlayer;
        }
        if (ok && game->checkMove(pos, newPos)) {
            coups->add(newPos);
        }
    }

    newPos = pos + Couple(- 1, -2);
    ok = true;

    if (newPos.x > 0 && newPos.y > 0) {
        if (board->plateau[newPos.y][newPos.x] != nullptr) {
            ok = board->plateau[newPos.y][newPos.x]->appartenancePlayer != appartenancePlayer;
        }
        if (ok && game->checkMove(pos, newPos)) {
            coups->add(newPos);
        }
    }

    return coups;
}
