#include "Piece.h"

void setup() {
  Serial.begin(9600);

  Piece roi("Roi", 4, 0);
  roi.afficher();
  roi.deplacer(4, 1);
  roi.afficher();
}

void loop() {
  // Rien ici pour l'instant
}
