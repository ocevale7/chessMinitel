#include "../../include/pieces/Tour.h"
#include "../../include/Game.h"

Tour::Tour (Game* game, Couple pos, int appartenancePlayer) :
    Piece(game, "Tour", pos, appartenancePlayer) {}

void Tour::afficher() {
  cout << "\033[3" << appartenancePlayer + 1 << "m" << "T" << appartenancePlayer << "\033[0m";
}

CoupleList* Tour::availableMoves(Plateau* board) {
    CoupleList* coups = new CoupleList();

    Couple newPos;
    int posCurrent;

    // Verticale -- Direction : Haut

    int limit = (pos.x >= 3 && pos.x <= 10) ? 14 : 11;
    posCurrent = pos.y + 1;

    while(posCurrent < limit) {
        newPos = Couple(pos.x, posCurrent);
        if (board->plateau[newPos.y][newPos.x] != nullptr) {
            if (board->plateau[newPos.y][newPos.x]->appartenancePlayer != appartenancePlayer) {
                coups->add(newPos);
            }
            break;
        } else {
            coups->add(newPos);
        }
        posCurrent++;
    }

    // Verticale -- Direction : Bas

    limit = (pos.x >= 3 && pos.x <= 10) ? -1 : 2;
    posCurrent = pos.y - 1;

    while(posCurrent > limit) {
        newPos = Couple(pos.x, posCurrent);
        if (board->plateau[newPos.y][newPos.x] != nullptr) {
            if (board->plateau[newPos.y][newPos.x]->appartenancePlayer != appartenancePlayer) {
                coups->add(newPos);
            }
             break;
        } else {
            coups->add(newPos);
        }
        posCurrent--;
    }

    // Horizontal -- Direction : Droite

    limit = (pos.y >= 3 && pos.y <= 10) ? 14 : 11;
    posCurrent = pos.x + 1;

    while(posCurrent < limit){
        newPos = Couple(posCurrent, pos.y);
        if (board->plateau[newPos.y][newPos.x] != nullptr) {
            if (board->plateau[newPos.y][newPos.x]->appartenancePlayer != appartenancePlayer) {
                coups->add(newPos);
            }
            break;
        } else {
            coups->add(newPos);
        }
        posCurrent++;
    }

    // Horizontal -- Direction : Gauche

    limit = (pos.y >= 3 && pos.y <= 10) ? -1 : 2;
    posCurrent = pos.x - 1;
    while(posCurrent > limit) {
        newPos = Couple(posCurrent, pos.y); 
        if (board->plateau[newPos.y][newPos.x] != nullptr) {
            if (board->plateau[newPos.y][newPos.x]->appartenancePlayer != appartenancePlayer) {
                coups->add(newPos);
            }
             break;
        } else {
            coups->add(newPos);
        }
        posCurrent--;
    }

    return coups;
}

void Tour::afficherMinitel(){
    
    //int buffer;
    
    cout << "Hello World !" << endl;
}