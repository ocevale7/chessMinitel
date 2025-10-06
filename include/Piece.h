#ifndef PIECE_H
#define PIECE_H

//#include <Arduino.h>  // Nécessaire pour utiliser String, etc.
using namespace std;

#include <iostream>




class Piece {
  public:
    string nom;
    int x, y;

    Piece(string n, int posX, int posY);
    void deplacer(int newX, int newY);
    void afficher();
};

#endif
