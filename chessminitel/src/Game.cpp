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

    board->plateau[7][13]  = new Dame(this,Couple(13, 7) , 0);
    board->plateau[6][13]  = new Roi(this, Couple(13, 6), 0);
}

bool Game::isEchec(int player) {
    Couple kingPos(-1, -1);
    // Trouver la position du roi du joueur donné
    outMinitel("Recherche du roi...\n");
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
    outMinitel("Roi trouve.\n");
    // Vérifier si une pièce adverse peut attaquer le roi
    for(int y = 0; y < 14; y++) {
        for(int x = 0; x < 14; x++) {
            Piece* piece = board->plateau[y][x];
            if(piece != nullptr && piece->appartenancePlayer != player) {
                Couple pos(x, y);
                std::string s_piece = std::string("piece trouvee: ") + piece->nom + std::string(" en ") + std::to_string(x) + std::string(", ") + std::to_string(y) + std::string("\n");
                outMinitel(s_piece.c_str());
                CoupleList* moves = piece->availableMoves(board);
                if(moves->isInside(kingPos)) {
                    delete moves;
                    return true;
                }
                delete moves;
            }
        }
    }
    outMinitel("Aucune menace detectee.\n");
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

    outMinitel("Deplacement de la piece...");
    board->plateau[from.y][from.x]->deplacer(to);
    board->deplacer(from, to);
    outMinitel("Verification de l'echec...");
    if (isEchec(currentPlayer)) {
        board->plateau[from.y][from.x] = pieceFrom;
        board->plateau[to.y][to.x] = pieceTo;
        return false;
    } else {
        outMinitel("Pas echec.\n");
        if (pieceTo != nullptr) {
            points[currentPlayer] += pieceTo->points;
            delete pieceTo;
        }
        pieceFrom->action();
        outMinitel("action effectuée\n");
        currentPlayer = (currentPlayer + 1) % 4;
    }
    outMinitel("Deplacement effectue.");
    return true;
}

bool Game::play(Couple from, Couple to, int currentPlayer) {
    outMinitel("Verification du coup...\n");
    if(board->plateau[from.y][from.x] != nullptr) {
        outMinitel("Piece trouvee a la position.\n");
        if (board->plateau[from.y][from.x]->appartenancePlayer == currentPlayer) {
            outMinitel("Piece appartient au joueur courant.\n");
            if(board->plateau[from.y][from.x]->availableMoves(board)->isInside(to)) {
                outMinitel("Mouvement valide.\n");
                return move(from, to, currentPlayer);
            } else {
                outMinitel("Mouvement invalide.\n");
            }
        } else {
            outMinitel("Cette piece n'appartient pas au joueur courant !\n\n");
        }
    } else {
        outMinitel("Pas de piece a cette position !\n\n");
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

int askIntMinitel(const char* label, int x, int y) {
    moveCursorXY(0, y);
    write_bytes((uint8_t*)label, strlen(label));
    
    char buffer[3] = {0};
    int i = 0;
    
    // On place le curseur juste après le label (adapté à tes coordonnées 37)
    moveCursorXY(x, y);

    while (i < 2) {
        msg_t msg;
        msg_receive(&msg);
        char c = (char)msg.content.value;

        if (c >= '0' && c <= '9') {
            buffer[i++] = c;
            //write_bytes((uint8_t*)&c, 1); // Écho du caractère saisi
        }
    }
    
    return atoi(buffer);
}

void Game::recupInputMinitel(Couple& from, Couple& to) {
    set_fg_white(false);

    // 1. Récupération du point de départ
    from.x = askIntMinitel("Entrer cord X de la piece a bouger: ..", 37, 23);
    from.y = askIntMinitel("Entrer cord Y de la piece a bouger: ..", 37, 24);

    // on print from
    std::string s_from = std::string("Depart     : (") + std::to_string(from.x) + ", " + std::to_string(from.y) + ")\n";
    outMinitel(s_from.c_str());

    // 2. Récupération de la destination
    to.x = askIntMinitel("Entrer cord X de la case dest     : ..", 37, 23);
    to.y = askIntMinitel("Entrer cord Y de la case dest     : ..", 37, 24);

    // on print to
    std::string s_to = std::string("Destination : (") + std::to_string(to.x) + ", " + std::to_string(to.y) + ")\n";
    outMinitel(s_to.c_str());
}