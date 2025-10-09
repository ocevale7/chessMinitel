#include "../include/Piece.h"

Piece::Piece(Game* game, string n, Couple pos, int player)
  : game(game), nom(n), pos(pos), appartenancePlayer(player){}

void Piece::deplacer(Couple newPos) {
  pos = newPos;
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

Piece::~Piece() {}

