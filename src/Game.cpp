#include "../include/Game.h"

Game::Game() {
    board = new Plateau();
    this->start();
}

void Game::start() {

    // On place les pions

    for(int i = 3; i < 11; i++) {
        board->plateau[1][i]  = new Pion(this, Couple(i, 1), 0);
        board->plateau[12][i] = new Pion(this, Couple(i, 12), 1);
        board->plateau[i][1]  = new Pion(this, Couple(1, i), 2);
        board->plateau[i][12] = new Pion(this, Couple(12, i), 3);
    }

    // On place les tours

    board->plateau[0][3]  = new Tour(this, Couple(3, 0), 0);
    board->plateau[0][10]  = new Tour(this, Couple(10, 0), 0);

    board->plateau[13][3]  = new Tour(this, Couple(3, 13), 1);
    board->plateau[13][10]  = new Tour(this, Couple(10, 13), 1);

    board->plateau[3][0]  = new Tour(this, Couple(0, 3), 2);
    board->plateau[10][0]  = new Tour(this, Couple(0, 10), 2);

    board->plateau[3][13]  = new Tour(this, Couple(13, 3), 3);
    board->plateau[10][13]  = new Tour(this, Couple(13, 10), 3);

    // On place les cavaliers

    board->plateau[0][4]  = new Cavalier(this, Couple(4, 0), 0);
    board->plateau[0][9]  = new Cavalier(this, Couple(9, 0), 0);

    board->plateau[13][4]  = new Cavalier(this, Couple(4, 13), 1);
    board->plateau[13][9]  = new Cavalier(this, Couple(9, 13), 1);

    board->plateau[4][0]  = new Cavalier(this, Couple(0, 4), 2);
    board->plateau[9][0]  = new Cavalier(this, Couple(0, 9), 2);

    board->plateau[4][13]  = new Cavalier(this, Couple(13, 4), 3);
    board->plateau[9][13]  = new Cavalier(this, Couple(13, 9), 3);

    // On place les fous

    board->plateau[0][5]  = new Fou(this, Couple(5, 0), 0);
    board->plateau[0][8]  = new Fou(this, Couple(8, 0), 0);

    board->plateau[13][5]  = new Fou(this, Couple(5, 13), 1);
    board->plateau[13][8]  = new Fou(this, Couple(8, 13), 1);

    board->plateau[5][0]  = new Fou(this, Couple(0, 5), 2);
    board->plateau[8][0]  = new Fou(this, Couple(0, 8), 2);

    board->plateau[5][13]  = new Fou(this, Couple(13, 5), 3);
    board->plateau[8][13]  = new Fou(this, Couple(13, 8), 3);

    // On place les dames et rois

    board->plateau[0][6]  = new Roi(this, Couple(6, 0), 0);
    board->plateau[0][7]  = new Dame(this, Couple(7, 0), 0);

    board->plateau[13][6]  = new Dame(this, Couple(6, 13), 1);
    board->plateau[13][7]  = new Roi(this, Couple(7, 13), 1);

    board->plateau[6][0]  = new Roi(this, Couple(0, 6), 2);
    board->plateau[7][0]  = new Dame(this, Couple(0, 7), 2);

    board->plateau[6][13]  = new Dame(this, Couple(13, 6), 3);
    board->plateau[7][13]  = new Roi(this, Couple(13, 7), 3);


}

bool Game::checkMove(Couple /*old*/, Couple /*young*/) {
    return true;
}
