#include "../../include/pieces/Roi.h"
#include "../../include/Game.h"

Roi::Roi (Game* game, Couple pos, int appartenancePlayer) :
    Piece(game, "Roi", pos, appartenancePlayer) {
    points = 0;
}

void Roi::action() {
    // Le roi n'a pas d'action spéciale pour le moment
}

void Roi::afficher() {
  cout << "\033[3" << appartenancePlayer + 1 << "m" << "R" << appartenancePlayer << "\033[0m";
}

CoupleList* Roi::availableMoves(Plateau* board) {
    CoupleList* coups = new CoupleList();

    // Droite

    if (pos.x < 10 || (pos.y > 2 && pos.y < 11 && pos.x < 13)) {
      if (board->plateau[pos.y][pos.x + 1] != nullptr) {
        if(board->plateau[pos.y][pos.x + 1]->appartenancePlayer != appartenancePlayer) {
          coups->add(Couple(pos.x + 1, pos.y));
        }
      } else {
        coups->add(Couple(pos.x + 1, pos.y));
      }
    }

    // Gauche

    if (pos.x > 3 || (pos.y > 2 && pos.y < 11 && pos.x > 0)) {
      if (board->plateau[pos.y][pos.x - 1] != nullptr) {
        if(board->plateau[pos.y][pos.x - 1]->appartenancePlayer != appartenancePlayer) {
          coups->add(Couple(pos.x - 1, pos.y));
        }
      } else {
        coups->add(Couple(pos.x - 1, pos.y));
      }
    }

    // Haut

    if (pos.y > 3 || (pos.x > 2 && pos.x < 11 && pos.y > 0)) {
      if (board->plateau[pos.y - 1][pos.x] != nullptr) {
        if(board->plateau[pos.y - 1][pos.x]->appartenancePlayer != appartenancePlayer) {
          coups->add(Couple(pos.x, pos.y - 1));
        }
      } else {
        coups->add(Couple(pos.x, pos.y - 1));
      }
    }

    // Bas

    if (pos.y < 10 || (pos.x > 2 && pos.x < 11 && pos.y < 13)) {
      if (board->plateau[pos.y + 1][pos.x] != nullptr) {
        if(board->plateau[pos.y + 1][pos.x]->appartenancePlayer != appartenancePlayer) {
          coups->add(Couple(pos.x, pos.y + 1));
        }
      } else {
        coups->add(Couple(pos.x, pos.y + 1));
      }
    }

    // Haut Droite

    if ((pos.x < 10 || (pos.y > 2 && pos.y < 11 && pos.x < 13)) &&
        (pos.y > 3 || (pos.x > 2 && pos.x < 11 && pos.y > 0))) {
      if (board->plateau[pos.y - 1][pos.x + 1] != nullptr) {
        if(board->plateau[pos.y - 1][pos.x + 1]->appartenancePlayer != appartenancePlayer) {
          coups->add(Couple(pos.x + 1, pos.y - 1));
        }
      } else {
        coups->add(Couple(pos.x + 1, pos.y - 1));
      }
    }

    // Haut Gauche

    if ((pos.x > 3 || (pos.y > 2 && pos.y < 11 && pos.x > 0)) &&
        (pos.y > 3 || (pos.x > 2 && pos.x < 11 && pos.y > 0))) {
      if (board->plateau[pos.y - 1][pos.x - 1] != nullptr) {
        if(board->plateau[pos.y - 1][pos.x - 1]->appartenancePlayer != appartenancePlayer) {
          coups->add(Couple(pos.x - 1, pos.y - 1));
        }
      } else {
        coups->add(Couple(pos.x - 1, pos.y - 1));
      }
    }

    // Bas Droite

    if ((pos.x < 10 || (pos.y > 2 && pos.y < 11 && pos.x < 13)) &&
        (pos.y < 10 || (pos.x > 2 && pos.x < 11 && pos.y < 13))) {
      if (board->plateau[pos.y + 1][pos.x + 1] != nullptr) {
        if(board->plateau[pos.y + 1][pos.x + 1]->appartenancePlayer != appartenancePlayer) {
          coups->add(Couple(pos.x + 1, pos.y + 1));
        }
      } else {
        coups->add(Couple(pos.x + 1, pos.y + 1));
      }
    }

    // Bas Gauche

    if ((pos.x > 3 || (pos.y > 2 && pos.y < 11 && pos.x > 0)) &&
        (pos.y < 10 || (pos.x > 2 && pos.x < 11 && pos.y < 13))) {
      if (board->plateau[pos.y + 1][pos.x - 1] != nullptr) {
        if(board->plateau[pos.y + 1][pos.x - 1]->appartenancePlayer != appartenancePlayer) {
          coups->add(Couple(pos.x - 1, pos.y + 1));
        }
      } else {
        coups->add(Couple(pos.x - 1, pos.y + 1));
      }
    }

    // Roque

    

    return coups;
}

void Roi::afficherMinitel(){
    
    //int buffer;
    
    cout << "Hello World !" << endl;
}