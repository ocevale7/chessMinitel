#include "../../include/pieces/Fou.h"
#include "../../include/Game.h"

Fou::Fou (Game* game, Couple pos, int appartenancePlayer) :
    Piece(game, "Fou", pos, appartenancePlayer) {}

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
            limit = 11;
            posCurrent = (13 - pos.x) + 1;
        } else {
            limit = 14;
            posCurrent = pos.y + 1;
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
    
    //int buffer;
    
    cout << "Hello World !" << endl;
}