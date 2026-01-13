#include "../../include/pieces/Tour.h"
#include "../../include/Game.h"

Tour::Tour (Game* game, Couple pos, int appartenancePlayer) :
    Piece(game, "Tour", pos, appartenancePlayer) {
    points = 5;
}
void Tour::action() {
    // La tour n'a pas d'action spéciale pour le moment
}

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
    uint8_t* tourDroite = (uint8_t*)"\x7D\x35";
    uint8_t* tourCote = (uint8_t*)"\x5F\x31";
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
        write_bytes((uint8_t*)tourCote,2);
    }else{
        write_bytes((uint8_t*)tourDroite,2);
    }
    

}

uint8_t* Tour::getMinitel(bool side){
    if (!side){
        return (uint8_t*)"\x7D\x35";
    }else{
        return (uint8_t*)"\x5F\x31";
    }
}