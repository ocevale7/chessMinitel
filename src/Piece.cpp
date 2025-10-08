#include "../include/Piece.h"

Piece::Piece(Game* game, string n, int posX, int posY, int player) {
  game = game;
  nom = n;
  x = posX;
  y = posY;
  appartenancePlayer = player;
}

void Piece::deplacer(int newX, int newY) {
  x = newX;
  y = newY;
}

void Piece::afficher() {
// Serial.print("Piece : ");
// Serial.print(nom);
// Serial.print(" à la position : ");
// Serial.print(x);
// Serial.print(", ");
// Serial.println(y);
  cout << "P";
}
