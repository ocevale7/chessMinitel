#include "Piece.h"

Piece::Piece(String n, int posX, int posY) {
  nom = n;
  x = posX;
  y = posY;
}

void Piece::deplacer(int newX, int newY) {
  x = newX;
  y = newY;
}

void Piece::afficher() {
  Serial.print("Piece : ");
  Serial.print(nom);
  Serial.print(" à la position : ");
  Serial.print(x);
  Serial.print(", ");
  Serial.println(y);
}
