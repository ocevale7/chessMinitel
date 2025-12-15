#include "../../include/pieces/Pion.h"
#include "../../include/Game.h"

Pion::Pion (Game* game, Couple pos, int appartenancePlayer) :
    Piece(game, "Pion", pos, appartenancePlayer) {}

void Pion::afficher() {
  cout << "\033[3" << appartenancePlayer + 1 << "m" << "P" << appartenancePlayer << "\033[0m";
}

CoupleList* Pion::availableMoves(Plateau* board) {
    CoupleList* coups = new CoupleList();

    // Pour les prises en diagonales des pions aux extrémités, pas besoin d'en faire des cas
    // particuliers car il y a toujours des cases sur leur coté (qui ne sont pas occupées si
    // se sont des cases invalides)

    // La prise en passant n'existe pas

    if (appartenancePlayer == 0) {
      if (board->plateau[pos.y][pos.x - 1] == nullptr) {
        coups->add(Couple(pos.x - 1, pos.y));
        if (pos.x == 12 && board->plateau[pos.y][pos.x - 2] == nullptr) {
          coups->add(Couple(pos.x - 2, pos.y));
        }
      }

      if (board->plateau[pos.y + 1][pos.x - 1] != nullptr) {
        if (board->plateau[pos.y + 1][pos.x - 1]->appartenancePlayer != appartenancePlayer) {
          coups->add(Couple(pos.x - 1, pos.y + 1));
        }
      }
      if (board->plateau[pos.y - 1][pos.x - 1] != nullptr) {
        if (board->plateau[pos.y - 1][pos.x - 1]->appartenancePlayer != appartenancePlayer) {
          coups->add(Couple(pos.x - 1, pos.y - 1));
        }
      }
    } else if (appartenancePlayer == 1) {
      if (board->plateau[pos.y - 1][pos.x] == nullptr) {
        coups->add(Couple(pos.x, pos.y - 1));
        if (pos.y == 12 && board->plateau[pos.y - 2][pos.x] == nullptr) {
          coups->add(Couple(pos.x, pos.y - 2));
        }
      }

      if (board->plateau[pos.y - 1][pos.x - 1] != nullptr) {
        if (board->plateau[pos.y - 1][pos.x - 1]->appartenancePlayer != appartenancePlayer) {
          coups->add(Couple(pos.x - 1, pos.y - 1));
        }
      }
      if (board->plateau[pos.y - 1][pos.x + 1] != nullptr) {
        if (board->plateau[pos.y - 1][pos.x + 1]->appartenancePlayer != appartenancePlayer) {
          coups->add(Couple(pos.x + 1, pos.y - 1));
        }
      }
    } else if (appartenancePlayer == 2) {
      if (board->plateau[pos.y][pos.x + 1] == nullptr) {
        coups->add(Couple(pos.x + 1, pos.y));
        if (pos.x == 1 && board->plateau[pos.y][pos.x + 2] == nullptr) {
          coups->add(Couple(pos.x + 2, pos.y));
        }
      }

      if (board->plateau[pos.y - 1][pos.x + 1] != nullptr) {
        if (board->plateau[pos.y - 1][pos.x + 1]->appartenancePlayer != appartenancePlayer) {
          coups->add(Couple(pos.x + 1, pos.y - 1));
        }
      }
      if (board->plateau[pos.y + 1][pos.x + 1] != nullptr) {
        if (board->plateau[pos.y + 1][pos.x + 1]->appartenancePlayer != appartenancePlayer) {
          coups->add(Couple(pos.x + 1, pos.y + 1));
        }
      }
    } else if (appartenancePlayer == 3) {
      if (board->plateau[pos.y + 1][pos.x] == nullptr) {
        coups->add(Couple(pos.x, pos.y + 1));
        if (pos.y == 1 && board->plateau[pos.y + 2][pos.x] == nullptr) {
          coups->add(Couple(pos.x, pos.y + 2));
        }
      }

      if (board->plateau[pos.y + 1][pos.x - 1] != nullptr) {
        if (board->plateau[pos.y + 1][pos.x - 1]->appartenancePlayer != appartenancePlayer) {
          coups->add(Couple(pos.x - 1, pos.y + 1));
        }
      }
      if (board->plateau[pos.y + 1][pos.x + 1] != nullptr) {
        if (board->plateau[pos.y + 1][pos.x + 1]->appartenancePlayer != appartenancePlayer) {
          coups->add(Couple(pos.x + 1, pos.y + 1));
        }
      }
    }

    return coups;
}

void Pion::afficherMinitel(){
    
    //int buffer;
    
    cout << "Hello World !" << endl;
}