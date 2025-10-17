#include "../../include/pieces/Cavalier.h"
#include "../../include/Game.h"

Cavalier::Cavalier (Game* game, Couple pos, int appartenancePlayer) :
    Piece(game, "Cavalier", pos, appartenancePlayer) {}

CoupleList* Cavalier::availableMoves(Plateau* board) {

    CoupleList* coups = new CoupleList();

    Couple newPos = pos + Couple(2, 1);
    bool canMoveOnThisCase = true;

    if ((newPos.x < 14 && newPos.x > 0 && newPos.y < 11 && newPos.y > 2) || (newPos.x < 11 && newPos.x > 2 && ((newPos.y < 3 && newPos.y > -1) || (newPos.y < 14 && newPos.y > 10)))) {
        if (board->plateau[newPos.y][newPos.x] != nullptr) {
            canMoveOnThisCase = board->plateau[newPos.y][newPos.x]->appartenancePlayer != appartenancePlayer;
        }
        if (canMoveOnThisCase && game->checkMove(pos, newPos)) {
            coups->add(newPos);
        }
    }
    
    newPos = pos + Couple(2, -1);
    canMoveOnThisCase = true;

    if ((newPos.x < 14 && newPos.x > 0 && newPos.y < 11 && newPos.y > 2) || (newPos.x < 11 && newPos.x > 2 && ((newPos.y < 3 && newPos.y > -1) || (newPos.y < 14 && newPos.y > 10)))) {
        if (board->plateau[newPos.y][newPos.x] != nullptr) {
            canMoveOnThisCase = board->plateau[newPos.y][newPos.x]->appartenancePlayer != appartenancePlayer;
        }
        if (canMoveOnThisCase && game->checkMove(pos, newPos)) {
            coups->add(newPos);
        }
    }
    
    
    newPos = pos + Couple(-2, 1);
    canMoveOnThisCase = true;

    if ((newPos.x < 14 && newPos.x > 0 && newPos.y < 11 && newPos.y > 2) || (newPos.x < 11 && newPos.x > 2 && ((newPos.y < 3 && newPos.y > -1) || (newPos.y < 14 && newPos.y > 10)))) {
        if (board->plateau[newPos.y][newPos.x] != nullptr) {
            canMoveOnThisCase = board->plateau[newPos.y][newPos.x]->appartenancePlayer != appartenancePlayer;
        }
        if (canMoveOnThisCase && game->checkMove(pos, newPos)) {
            coups->add(newPos);
        }
    }

    newPos = pos + Couple(-2, -1);
    canMoveOnThisCase = true;

    if ((newPos.x < 14 && newPos.x > 0 && newPos.y < 11 && newPos.y > 2) || (newPos.x < 11 && newPos.x > 2 && ((newPos.y < 3 && newPos.y > -1) || (newPos.y < 14 && newPos.y > 10)))) {
        if (board->plateau[newPos.y][newPos.x] != nullptr) {
            canMoveOnThisCase = board->plateau[newPos.y][newPos.x]->appartenancePlayer != appartenancePlayer;
        }
        if (canMoveOnThisCase && game->checkMove(pos, newPos)) {
            coups->add(newPos);
        }
    }

    newPos = pos + Couple(1, 2);
    canMoveOnThisCase = true;

    if ((newPos.x < 14 && newPos.x > 0 && newPos.y < 11 && newPos.y > 2) || (newPos.x < 11 && newPos.x > 2 && ((newPos.y < 3 && newPos.y > -1) || (newPos.y < 14 && newPos.y > 10)))) {
        if (board->plateau[newPos.y][newPos.x] != nullptr) {
            canMoveOnThisCase = board->plateau[newPos.y][newPos.x]->appartenancePlayer != appartenancePlayer;
        }
        if (canMoveOnThisCase && game->checkMove(pos, newPos)) {
            coups->add(newPos);
        }
    }

    newPos = pos + Couple(1, -2);
    canMoveOnThisCase = true;

    if ((newPos.x < 14 && newPos.x > 0 && newPos.y < 11 && newPos.y > 2) || (newPos.x < 11 && newPos.x > 2 && ((newPos.y < 3 && newPos.y > -1) || (newPos.y < 14 && newPos.y > 10)))) {
        if (board->plateau[newPos.y][newPos.x] != nullptr) {
            canMoveOnThisCase = board->plateau[newPos.y][newPos.x]->appartenancePlayer != appartenancePlayer;
        }
        if (canMoveOnThisCase && game->checkMove(pos, newPos)) {
            coups->add(newPos);
        }
    }

    newPos = pos + Couple(-1, 2);
    canMoveOnThisCase = true;

    if ((newPos.x < 14 && newPos.x > 0 && newPos.y < 11 && newPos.y > 2) || (newPos.x < 11 && newPos.x > 2 && ((newPos.y < 3 && newPos.y > -1) || (newPos.y < 14 && newPos.y > 10)))) {
        if (board->plateau[newPos.y][newPos.x] != nullptr) {
            canMoveOnThisCase = board->plateau[newPos.y][newPos.x]->appartenancePlayer != appartenancePlayer;
        }
        if (canMoveOnThisCase && game->checkMove(pos, newPos)) {
            coups->add(newPos);
        }
    }

    newPos = pos + Couple(- 1, -2);
    canMoveOnThisCase = true;

    if ((newPos.x < 14 && newPos.x > 0 && newPos.y < 11 && newPos.y > 2) || (newPos.x < 11 && newPos.x > 2 && ((newPos.y < 3 && newPos.y > -1) || (newPos.y < 14 && newPos.y > 10)))) {
        if (board->plateau[newPos.y][newPos.x] != nullptr) {
            canMoveOnThisCase = board->plateau[newPos.y][newPos.x]->appartenancePlayer != appartenancePlayer;
        }
        if (canMoveOnThisCase && game->checkMove(pos, newPos)) {
            coups->add(newPos);
        }
    }

    CoupleList* tmp = coups;

    while(tmp->head != nullptr) {
        cout<<"("<<tmp->head->data.x<<", "<<tmp->head->data.y<<")";
        tmp->head = tmp->head->next;
    }
    cout<<"\n";

    return coups;
}
