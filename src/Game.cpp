#include "../include/Game.h"

Game::Game() {
    board = new Plateau();
    this->start();
    cout<<board->plateau[0][4]->appartenancePlayer<<"\n";
    cout<<board->plateau[0][4]->nom<<"\n";
    cout<<board->plateau[0][4]->pos.x<<",";
    cout<<board->plateau[0][4]->pos.y<<"\n";
    board->plateau[0][4]->availableMoves(board);
}

void Game::start() {

    // On place les pions

    for(int i = 3; i < 11; i++) {
        board->plateau[1][i]  = new Pion(this, Couple(i, 1), 0);
        board->plateau[12][i] = new Pion(this, Couple(i, 12), 1);
        board->plateau[i][1]  = new Pion(this, Couple(1, i), 2);
        board->plateau[i][12] = new Pion(this, Couple(12, 1), 3);
    }

    // On place les tours

    board->plateau[0][3]  = new Tour(this, Couple(3, 0), 0);
    board->plateau[0][10]  = new Tour(this, Couple(10, 0), 0);

    board->plateau[12][3]  = new Tour(this, Couple(3, 12), 1);
    board->plateau[12][10]  = new Tour(this, Couple(10, 12), 1);

    board->plateau[3][0]  = new Tour(this, Couple(0, 3), 2);
    board->plateau[10][0]  = new Tour(this, Couple(0, 10), 2);

    board->plateau[3][12]  = new Tour(this, Couple(12, 3), 3);
    board->plateau[10][12]  = new Tour(this, Couple(12, 10), 3);

    // On place les cavaliers

    board->plateau[0][4]  = new Cavalier(this, Couple(4, 0), 0);
    board->plateau[0][9]  = new Cavalier(this, Couple(9, 0), 0);

    board->plateau[12][4]  = new Cavalier(this, Couple(4, 12), 1);
    board->plateau[12][9]  = new Cavalier(this, Couple(9, 12), 1);

    board->plateau[4][0]  = new Cavalier(this, Couple(0, 4), 2);
    board->plateau[9][0]  = new Cavalier(this, Couple(0, 9), 2);

    board->plateau[4][12]  = new Cavalier(this, Couple(12, 4), 3);
    board->plateau[9][12]  = new Cavalier(this, Couple(12, 9), 3);

    // On place les fous

    board->plateau[0][5]  = new Fou(this, Couple(5, 0), 0);
    board->plateau[0][8]  = new Fou(this, Couple(8, 0), 0);

    board->plateau[12][5]  = new Fou(this, Couple(5, 12), 1);
    board->plateau[12][8]  = new Fou(this, Couple(8, 12), 1);

    board->plateau[5][0]  = new Fou(this, Couple(0, 5), 2);
    board->plateau[8][0]  = new Fou(this, Couple(0, 8), 2);

    board->plateau[5][12]  = new Fou(this, Couple(12, 5), 3);
    board->plateau[8][12]  = new Fou(this, Couple(12, 8), 3);

    // On place les dames et rois

    board->plateau[0][6]  = new Roi(this, Couple(6, 0), 0);
    board->plateau[0][7]  = new Dame(this, Couple(7, 0), 0);

    board->plateau[12][6]  = new Dame(this, Couple(6, 12), 1);
    board->plateau[12][7]  = new Roi(this, Couple(7, 12), 1);

    board->plateau[6][0]  = new Roi(this, Couple(0, 6), 2);
    board->plateau[7][0]  = new Dame(this, Couple(0, 7), 2);

    board->plateau[6][12]  = new Dame(this, Couple(12, 6), 3);
    board->plateau[7][12]  = new Roi(this, Couple(12, 7), 3);


}

bool Game::checkMove(Couple /*old*/, Couple /*young*/) {
    return true;
}
