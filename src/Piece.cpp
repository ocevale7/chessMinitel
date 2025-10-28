#include "../include/Piece.h"

Piece::Piece(Game* game, string n, Couple pos, int player)
  : game(game), nom(n), pos(pos), appartenancePlayer(player){}

void Piece::deplacer(Couple newPos) {
  pos = newPos;
}

Piece::~Piece() {}

