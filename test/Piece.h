#ifndef PIECE_H
#define PIECE_H

#include <Arduino.h>  // Nécessaire pour utiliser String, etc.

class Piece {
  public:
    String nom;
    int x, y;

    Piece(String n, int posX, int posY);
    void deplacer(int newX, int newY);
    void afficher();
};

#endif
