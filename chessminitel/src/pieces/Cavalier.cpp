#include "../../include/pieces/Cavalier.h"
#include "../../include/Game.h"


Cavalier::Cavalier (Game* game, Couple pos, int appartenancePlayer) :
    Piece(game, "Cavalier", pos, appartenancePlayer) {
    points = 3;
}

void Cavalier::action() {
    // Le cavalier n'a pas d'action spéciale pour le moment
}


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

void Cavalier::afficherMinitel(){
    uint8_t* pieceDroite = (uint8_t*)"\x7A\x31";
    uint8_t* pieceCote = (uint8_t*)"\x3D\x34";
    int x = pos.x;
    int y = pos.y;
    if (appartenancePlayer/2){
        bool lighter = (x+y)%2 == 0;
        set_fg_black(lighter);
    }else{
        bool darker = (x+y)%2 == 1;
        set_fg_white(darker);
    }
    if (appartenancePlayer%2==0){
        write_bytes((uint8_t*)pieceCote,2);
    }else{
        write_bytes((uint8_t*)pieceDroite,2);
    }

}

uint8_t* Cavalier::getMinitel(bool side){
    if (!side){
        return (uint8_t*)"\x7A\x31";
    }else{
        return (uint8_t*)"\x3D\x34";
    }
}