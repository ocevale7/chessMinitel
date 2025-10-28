#include "Game.h"


Couple getCase() {
    Couple input;
    do {
        cout << "Entrez la coordonnée en abcisse : ";
        while(!(cin >> input.x) || input.x < 0 || input.x > 13) {
            cout << "Coordonnée invalide. Entrez une coordonnée en abcisse entre 0 et 13 : ";
            cin.clear();
            cin >> input.x;
        }
        cout << "Entrez la coordonnée en ordonnée : ";
        while(!(cin >> input.y) || input.y < 0 || input.y > 13) {
            cout << "Coordonnée invalide. Entrez une coordonnée en ordonnée entre 0 et 13 : ";
            cin.clear();
            cin >> input.y;
        }
    } while ((input.x<3 || input.x>=11) && (input.y<3 || input.y>=11));
    
    return input;
}

int main()
{
    Game* game = new Game();
    game->start();

    while (true) {
        cout << "Plateau actuel : " << endl;
        game->board->afficher();

        cout << "Sélectionnez une pièce à déplacer :" << endl;
        Couple from = getCase();

        cout << "Sélectionnez la case de destination :" << endl;
        Couple to = getCase();

        game->play(from, to);
    }
}