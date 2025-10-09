#include "../include/Game.h"

Game::Game() {}

void Game::start() {

    // On place les pions

    for(int i = 3; i < 11; i++) {
        board[i][1]  = new Pion(this, Couple(i, 1), 0);
        board[i][12] = new Pion(this, Couple(i, 12), 1);
        board[1][i]  = new Pion(this, Couple(1, i), 2);
        board[12][i] = new Pion(this, Couple(12, 1), 3);
    }

    // On place les tours

    board[3][0]  = new Tour(this, Couple(3, 0), 0);
    board[10][0]  = new Tour(this, Couple(10, 0), 0);

    board[3][12]  = new Tour(this, Couple(3, 12), 0);
    board[10][12]  = new Tour(this, Couple(10, 12), 0);

    board[0][3]  = new Tour(this, Couple(0, 3), 0);
    board[0][10]  = new Tour(this, Couple(0, 10), 0);

    board[12][3]  = new Tour(this, Couple(12, 3), 0);
    board[12][10]  = new Tour(this, Couple(12, 10), 0);

    // On place les cavaliers

    board[4][0]  = new Cavalier(this, Couple(4, 0), 0);
    board[9][0]  = new Cavalier(this, Couple(9, 0), 0);

    board[4][12]  = new Cavalier(this, Couple(4, 12), 0);
    board[9][12]  = new Cavalier(this, Couple(9, 12), 0);

    board[0][4]  = new Cavalier(this, Couple(0, 4), 0);
    board[0][9]  = new Cavalier(this, Couple(0, 9), 0);

    board[12][4]  = new Cavalier(this, Couple(12, 4), 0);
    board[12][9]  = new Cavalier(this, Couple(12, 9), 0);

    // On place les fous

    board[5][0]  = new Fou(this, Couple(5, 0), 0);
    board[8][0]  = new Fou(this, Couple(8, 0), 0);

    board[5][12]  = new Fou(this, Couple(5, 12), 0);
    board[8][12]  = new Fou(this, Couple(8, 12), 0);

    board[0][5]  = new Fou(this, Couple(0, 5), 0);
    board[0][8]  = new Fou(this, Couple(0, 8), 0);

    board[12][5]  = new Fou(this, Couple(12, 5), 0);
    board[12][8]  = new Fou(this, Couple(12, 8), 0);

    // On place les dames et rois

    board[6][0]  = new Roi(this, Couple(6, 0), 0);
    board[7][0]  = new Dame(this, Couple(7, 0), 0);

    board[6][12]  = new Dame(this, Couple(6, 12), 0);
    board[7][12]  = new Roi(this, Couple(7, 12), 0);

    board[0][6]  = new Roi(this, Couple(0, 6), 0);
    board[0][7]  = new Dame(this, Couple(0, 7), 0);

    board[12][6]  = new Dame(this, Couple(12, 6), 0);
    board[12][7]  = new Roi(this, Couple(12, 7), 0);


}