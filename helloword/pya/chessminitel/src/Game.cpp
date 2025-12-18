#include "../include/Game.h"


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

void Game::move(Couple from, Couple to) {

    Piece* pieceFrom = board->plateau[from.y][from.x];
    Piece* pieceTo = board->plateau[to.y][to.x];

    board->plateau[from.y][from.x]->deplacer(to);
    board->swap(from, to);

    if (isEchec(currentPlayer)) {
        cout << "Mouvement mettant en échec votre roi ! Annulation du mouvement." << endl;
        board->plateau[from.y][from.x] = pieceFrom;
        board->plateau[to.y][to.x] = pieceTo;
    } else {
        if (pieceTo != nullptr) {
            points[currentPlayer] += pieceTo->getPoints();
            delete pieceTo;
        }
        if (pieceFrom->nom == "Pion" && (
            (currentPlayer == 1 && to.y == 3)  || 
            (currentPlayer == 3 && to.y == 10) || 
            (currentPlayer == 0 && to.x == 3)  || 
            (currentPlayer == 2 && to.x == 10))) {
            cout << "Promotion du pion !" << endl;
            board->plateau[to.y][to.x] = new Dame(this, to, currentPlayer);
            delete pieceFrom;
        }
        currentPlayer = (currentPlayer + 1) % 4;
    }
}

void Game::play(Couple from, Couple to) {
    if(board->plateau[from.y][from.x] != nullptr) {
        if (board->plateau[from.y][from.x]->appartenancePlayer == currentPlayer) {
            if(board->plateau[from.y][from.x]->availableMoves(board)->isInside(to)) {
                move(from, to);
            } else {
                cout << "Mouvement invalide !" << endl;
            }
        } else {
            cout << "Ce n'est pas votre tour !" << endl;
        }
    } else {
        cout << "Pas de pièce à cette position !" << endl;
    }
}

string Game::recupInputMinitel(){
    
    char position1_X[] = "Entrer cord X de la piece a bouger: ..";
    char position1_Y[] = "Entrer cord Y de la piece a bouger: ..";
    set_fg_white(false);
    moveCursorXY(0,23);
    write_bytes((uint8_t*)position1_X, 40);
    moveCursorXY(0,24);
    write_bytes((uint8_t*)position1_Y, 40);

    bool input1_X_valid = false;
    while (!input1_X_valid){
        moveCursorXY(37,23);
    }

    bool input1_Y_valid = false;
    while (!input1_Y_valid){
        moveCursorXY(37,24);
    }

    return "";
}
