#include "../include/Game.h"
#include <string.h>

Game::Game() {
    board = new Plateau();
}

void Game::start() {

    // On place les pions

    for(int i = 3; i < 11; i++) {
        board->plateau[1][i]  = new Pion(this, Couple(i, 1), 3);
        board->plateau[12][i] = new Pion(this, Couple(i, 12), 1);
        board->plateau[i][1]  = new Pion(this, Couple(1, i), 2);
        board->plateau[i][12] = new Pion(this, Couple(12, i), 0);
    }

    // On place les tours

    board->plateau[0][3]  = new Tour(this, Couple(3, 0), 3);
    board->plateau[0][10]  = new Tour(this, Couple(10, 0), 3);

    board->plateau[13][3]  = new Tour(this, Couple(3, 13), 1);
    board->plateau[13][10]  = new Tour(this, Couple(10, 13), 1);

    board->plateau[3][0]  = new Tour(this, Couple(0, 3), 2);
    board->plateau[10][0]  = new Tour(this, Couple(0, 10), 2);

    board->plateau[3][13]  = new Tour(this, Couple(13, 3), 0);
    board->plateau[10][13]  = new Tour(this, Couple(13, 10), 0);

    // On place les cavaliers

    board->plateau[0][4]  = new Cavalier(this, Couple(4, 0), 3);
    board->plateau[0][9]  = new Cavalier(this, Couple(9, 0), 3);

    board->plateau[13][4]  = new Cavalier(this, Couple(4, 13), 1);
    board->plateau[13][9]  = new Cavalier(this, Couple(9, 13), 1);

    board->plateau[4][0]  = new Cavalier(this, Couple(0, 4), 2);
    board->plateau[9][0]  = new Cavalier(this, Couple(0, 9), 2);

    board->plateau[4][13]  = new Cavalier(this, Couple(13, 4), 0);
    board->plateau[9][13]  = new Cavalier(this, Couple(13, 9), 0);

    // On place les fous

    board->plateau[0][5]  = new Fou(this, Couple(5, 0), 3);
    board->plateau[0][8]  = new Fou(this, Couple(8, 0), 3);

    board->plateau[13][5]  = new Fou(this, Couple(5, 13), 1);
    board->plateau[13][8]  = new Fou(this, Couple(8, 13), 1);

    board->plateau[5][0]  = new Fou(this, Couple(0, 5), 2);
    board->plateau[8][0]  = new Fou(this, Couple(0, 8), 2);

    board->plateau[5][13]  = new Fou(this, Couple(13, 5), 0);
    board->plateau[8][13]  = new Fou(this, Couple(13, 8), 0);

    // On place les dames et rois

    board->plateau[0][6]  = new Roi(this, Couple(6, 0), 3);
    board->plateau[0][7]  = new Dame(this, Couple(7, 0), 3);

    board->plateau[13][6]  = new Dame(this, Couple(6, 13), 1);
    board->plateau[13][7]  = new Roi(this, Couple(7, 13), 1);

    board->plateau[6][0]  = new Roi(this, Couple(0, 6), 2);
    board->plateau[7][0]  = new Dame(this, Couple(0, 7), 2);

    board->plateau[6][13]  = new Dame(this,Couple(13, 6) , 0);
    board->plateau[7][13]  = new Roi(this, Couple(13, 7), 0);
}

bool Game::isEchec(int player) {
    Couple kingPos(-1, -1);
    // Trouver la position du roi du joueur donné
    for(int y = 0; y < 14; y++) {
        for(int x = 0; x < 14; x++) {
            Piece* piece = board->plateau[y][x];
            if(piece != nullptr && piece->appartenancePlayer == player && piece->nom == "Roi") {
                kingPos = Couple(x, y);
                break;
            }
        }
        if(kingPos.x != -1) break;
    }
    // Vérifier si une pièce adverse peut attaquer le roi
    for(int y = 0; y < 14; y++) {
        for(int x = 0; x < 14; x++) {
            Piece* piece = board->plateau[y][x];
            if(piece != nullptr && piece->appartenancePlayer != player) {
                Couple pos(x, y);
                CoupleList* moves = piece->availableMoves(board);
                if(moves->isInside(kingPos)) {
                    delete moves;
                    return true;
                }
                delete moves;
            }
        }
    }
    return false;
}

bool Game::isEchecEtMat(int player) {
    // Vérifier si le joueur est en échec
    if(!isEchec(player)) {
        return false;
    }

    // Vérifier si le joueur a des mouvements légaux pour sortir de l'échec
    for(int y = 0; y < 14; y++) {
        for(int x = 0; x < 14; x++) {
            Piece* piece = board->plateau[y][x];
            if(piece != nullptr && piece->appartenancePlayer == player) {
                Couple from(x, y);
                CoupleList* moves = piece->availableMoves(board);
                Node* current = moves->head;
                while (current){

                    Couple to = current->data;

                    // Simuler le mouvement
                    Piece* pieceFrom = board->plateau[from.y][from.x];
                    Piece* pieceTo = board->plateau[to.y][to.x];

                    board->plateau[from.y][from.x]->deplacer(to);
                    board->deplacer(from, to);

                    bool stillInCheck = isEchec(player);

                    // Annuler le mouvement
                    board->plateau[from.y][from.x] = pieceFrom;
                    board->plateau[to.y][to.x] = pieceTo;

                    if(!stillInCheck) {
                        delete moves;
                        return false;
                    }

                    current = current->next;
                }
                delete moves;
            }
        }
    }
    return true;
}

bool Game::isPat(int player) {
    // Vérifier si le joueur a des mouvements légaux
    for(int y = 0; y < 14; y++) {
        for(int x = 0; x < 14; x++) {
            Piece* piece = board->plateau[y][x];
            if(piece != nullptr && piece->appartenancePlayer == player) {
                Couple from(x, y);
                CoupleList* moves = piece->availableMoves(board);
                if(moves->head != nullptr) {
                    delete moves;
                    return false;
                }
                delete moves;
            }
        }
    }
    return true;
}

int Game::checkMatAndPat(int currentPlayer, int players[4]) {
    int count_elimination = 0;
    for(int player = 0; player < 4; player++) {
        if(players[player] != -1) {
            if (player != currentPlayer && isEchecEtMat(player)) {
                kill(player);
                players[player] = -1;
                count_elimination++;
                points[currentPlayer] += BONUS_POINTS_MAT;
            } else if (isPat(player)) {
                kill(player);
                players[player] = -1;
                count_elimination++;
                if (player == currentPlayer) {
                    points[currentPlayer] += BONUS_POINTS_SELF_PAT;
                } else {
                    points[currentPlayer] += BONUS_POINTS_OTHER_PAT;
                }
            }
        }
    }
    return count_elimination;
}

bool Game::move(Couple from, Couple to, int currentPlayer) {

    Piece* pieceFrom = board->plateau[from.y][from.x];
    Piece* pieceTo = board->plateau[to.y][to.x];

    board->plateau[from.y][from.x]->deplacer(to);
    board->deplacer(from, to);
    if (isEchec(currentPlayer)) {
        board->plateau[from.y][from.x] = pieceFrom;
        board->plateau[to.y][to.x] = pieceTo;
        outMinitel("Mouvement invalide.");
        return false;
    } else {
        if (pieceTo != nullptr) {
            points[currentPlayer] += pieceTo->points;
            delete pieceTo;
        }
        pieceFrom->action();
        currentPlayer = (currentPlayer + 1) % 4;
    }
    return true;
}

bool verifPosition(Couple pos) {
    if (pos.x >= 0 && pos.x <= 13) {
        if (pos.x >= 11 || pos.x <= 2) {
            return (pos.y >= 3 && pos.y <= 10);
        } else {
            return (pos.y >= 0 && pos.y <= 13);
        }
    }
    return false;
}

bool Game::play(Couple from, Couple to, int currentPlayer) {
    if (!verifPosition(from) || !verifPosition(to)) {
        outMinitel("Position hors du plateau.");
        return false;
    }
    if(board->plateau[from.y][from.x] != nullptr) {
        if (board->plateau[from.y][from.x]->appartenancePlayer == currentPlayer) {
            if(board->plateau[from.y][from.x]->availableMoves(board)->isInside(to)) {
                return move(from, to, currentPlayer);
            } else {
                outMinitel("Mouvement invalide.");
            }
        } else {
            outMinitel("Mauvais joueur.");
        }
    } else {
        outMinitel("Pas de piece a cette position !");
    }
    return false;
}

void Game::kill(int player) {
    for(int y = 0; y < 14; y++) {
        for(int x = 0; x < 14; x++) {
            Piece* piece = board->plateau[y][x];
            if(piece != nullptr && piece->appartenancePlayer == player) {
                piece->points = 0;
            }
        }
    }
}