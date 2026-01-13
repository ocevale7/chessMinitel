#include "../../include/pieces/Fou.h"
#include "../../include/Game.h"

Fou::Fou (Game* game, Couple pos, int appartenancePlayer) :
    Piece(game, "Fou", pos, appartenancePlayer) {
    points = 5;
}

void Fou::action() {
    // Le fou n'a pas d'action spéciale pour le moment
}

void Fou::afficher() {
  cout << "\033[3" << appartenancePlayer + 1 << "m" << "F" << appartenancePlayer << "\033[0m";
}

CoupleList* Fou::availableMoves(Plateau* board) {
    CoupleList* coups = new CoupleList();

    Couple newPos;
    int posCurrent;
    int limit;

    // Diagonale -- Direction : Haut-Gauche

    if (pos.x  >= pos.y) {
        if(pos.x - 3 >= pos.y) {
            limit = -1;
            posCurrent = pos.y - 1;
        } else {
            limit = 2;
            posCurrent = pos.x - 1;
        }
    } else {
        if(pos.y - 3 >= pos.x) {
            limit = -1;
            posCurrent = pos.x - 1;
        } else {
            limit = 2;
            posCurrent = pos.y - 1;
        }
    }

    int posCurrentX = pos.x - 1;
    int posCurrentY = pos.y - 1;

    while(posCurrent > limit) {
        newPos = Couple(posCurrentX, posCurrentY);
        if (board->plateau[newPos.y][newPos.x] != nullptr) {
            if (board->plateau[newPos.y][newPos.x]->appartenancePlayer != appartenancePlayer) {
                coups->add(newPos);
            }
             break;
        } else {
            coups->add(newPos);
        }
        posCurrentX--;
        posCurrentY--;
        posCurrent--;
    }

    // Diagonale -- Direction : Bas-Droite

    if (pos.x  >= pos.y) {
        if(pos.x - 3 >= pos.y) {
            limit = 14;
            posCurrent = pos.x + 1;
        } else {
            limit = 11;
            posCurrent = pos.y + 1;
        }
    } else {
        if(pos.y - 3 >= pos.x) {
            limit = 14;
            posCurrent = pos.y + 1;
        } else {
            limit = 11;
            posCurrent = pos.x + 1;
        }
    }

    posCurrentX = pos.x + 1;
    posCurrentY = pos.y + 1;

    while(posCurrent < limit) {
        newPos = Couple(posCurrentX, posCurrentY);
        if (board->plateau[newPos.y][newPos.x] != nullptr) {
            if (board->plateau[newPos.y][newPos.x]->appartenancePlayer != appartenancePlayer) {
                coups->add(newPos);
            }
             break;
        } else {
            coups->add(newPos);
        }
        posCurrentX++;
        posCurrentY++;
        posCurrent++;
    }

    // Diagonale -- Direction : Haut-Droite

    if (pos.x  >= 13 - pos.y) {
        if(pos.x - 3 >= 13 - pos.y) {
            limit = 14;
            posCurrent = pos.x + 1;
        } else {
            limit = 11;
            posCurrent = (13 - pos.y) + 1;
        }
    } else {
        if(10 - pos.y >= pos.x) {
            limit = 14;
            posCurrent = (13 - pos.y) + 1;
        } else {
            limit = 11;
            posCurrent = pos.x + 1;
        }
    }

    posCurrentX = pos.x + 1;
    posCurrentY = pos.y - 1;

    while(posCurrent < limit) {
        newPos = Couple(posCurrentX, posCurrentY);
        if (board->plateau[newPos.y][newPos.x] != nullptr) {
            if (board->plateau[newPos.y][newPos.x]->appartenancePlayer != appartenancePlayer) {
                coups->add(newPos);
            }
             break;
        } else {
            coups->add(newPos);
        }
        posCurrentX++;
        posCurrentY--;
        posCurrent++;
    }

    // Diagonale -- Direction : Bas-Gauche

    if (13 - pos.x  >= pos.y) {
        if(10 - pos.x >= pos.y) {
            limit = 14;
            posCurrent = (13 - pos.x) + 1;
        } else {
            limit = 11;
            posCurrent = pos.y + 1;
        }
    } else {
        if(pos.y - 3 >= 13 - pos.x) {
            limit = 14;
            posCurrent = pos.y + 1;
        } else {
            limit = 11;
            posCurrent = (13 - pos.x) + 1;
        }
    }

    posCurrentX = pos.x - 1;
    posCurrentY = pos.y + 1;

    while(posCurrent < limit) {
        newPos = Couple(posCurrentX, posCurrentY);
        if (board->plateau[newPos.y][newPos.x] != nullptr) {
            if (board->plateau[newPos.y][newPos.x]->appartenancePlayer != appartenancePlayer) {
                coups->add(newPos);
            }
             break;
        } else {
            coups->add(newPos);
        }
        posCurrentX--;
        posCurrentY++;
        posCurrent++;
    }

    return coups;
}

void Fou::afficherMinitel(){
    uint8_t* pieceDroite = (uint8_t*)"\x7E\x30";
    uint8_t* pieceCote = (uint8_t*)"\x3F\x24";
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

uint8_t* Fou::getMinitel(bool side){
    if (!side){
        return (uint8_t*)"\x7E\x30";
    }else{
        return (uint8_t*)"\x3F\x24";
    }
}