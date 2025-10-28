#include "../../include/pieces/Dame.h"
#include "../../include/Game.h"

Dame::Dame (Game* game, Couple pos, int appartenancePlayer) :
    Piece(game, "Dame", pos, appartenancePlayer) {}

void Dame::afficher() {
  cout << "D" << appartenancePlayer;
}

CoupleList* Dame::availableMoves(Plateau* board) {
    
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
        posCurrent++;
    }

    // Verticale -- Direction : Bas

    limit = (pos.x >= 3 && pos.x <= 10) ? -1 : 2;
    posCurrent = pos.y - 1;

    while(posCurrent > limit) {
        newPos = Couple(pos.x, posCurrent);
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
        posCurrent--;
    }

    // Horizontal -- Direction : Droite

    limit = (pos.y >= 3 && pos.y <= 10) ? 14 : 11;
    posCurrent = pos.x + 1;

    while(posCurrent < limit){
        newPos = Couple(posCurrent, pos.y);
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
        posCurrent++;
    }

    // Horizontal -- Direction : Gauche

    limit = (pos.y >= 3 && pos.y <= 10) ? -1 : 2;
    posCurrent = pos.x - 1;
    while(posCurrent > limit) {
        newPos = Couple(posCurrent, pos.y); 
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
        posCurrent--;
    }

    /*
    // Diagonales

    // Direction : Haut-Gauche
    int i = x - 1, j = y - 1;
    while (i >= 0 && j >= 0) {
        cout << "(" << i << ", " << j << ") ";
        i--; j--;
    }
    cout << endl;

    // Direction : Haut-Droite
    i = x + 1; j = y - 1;
    while (i < TAILLE && j >= 0) {
        cout << "(" << i << ", " << j << ") ";
        i++; j--;
    }
    cout << endl;

    // Direction : Bas-Gauche
    i = x - 1; j = y + 1;
    while (i >= 0 && j < TAILLE) {
        cout << "(" << i << ", " << j << ") ";
        i--; j++;
    }
    cout << endl;

    // Direction : Bas-Droite
    i = x + 1; j = y + 1;
    while (i < TAILLE && j < TAILLE) {
        cout << "(" << i << ", " << j << ") ";
        i++; j++;
    }
    cout << endl;
    */
   return coups;
}
