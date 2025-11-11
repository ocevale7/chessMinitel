#include "Game.h"
#include <limits>

Couple getCase() {
    Couple input;
    do {
        cout << "Entrez la coordonnée en abcisse : ";
        while(!(cin >> input.x) || input.x < 0 || input.x > 13) {
            cout << "Coordonnée invalide. Entrez une coordonnée en abcisse entre 0 et 13 : ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        cout << "Entrez la coordonnée en ordonnée : ";
        while(!(cin >> input.y) || input.y < 0 || input.y > 13) {
            cout << "Coordonnée invalide. Entrez une coordonnée en ordonnée entre 0 et 13 : ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    } while ((input.x<3 || input.x>=11) && (input.y<3 || input.y>=11));
    
    return input;
}

int main()
{
    Game* game = new Game();
    game->start();

    int players[4] = {0, 1, 2, 3};
    int currentPlayer = 0;
    int nbActivePlayers = 4;

    while (nbActivePlayers > 1) {
        if (players[currentPlayer] != -1) {
            if (game->isEchecEtMat(currentPlayer)) {
                cout << "Échec et mat pour le joueur " << currentPlayer << endl;
                players[currentPlayer] = -1;
                nbActivePlayers--;
                game->kill(currentPlayer);
            } else {

                Couple from;
                Couple to;

                do {
                    cout << "Tour du joueur " << currentPlayer << " | Nombre de points : " << game->points[currentPlayer] << endl << endl;

                    cout << "Plateau actuel : " << endl;
                    game->board->afficher();

                    cout << "Sélectionnez une pièce à déplacer :" << endl;
                    from = getCase();

                    cout << "Sélectionnez la case de destination :" << endl;
                    to = getCase();

                    cout << "\033[2J\033[1;1H"; // Clear console

                } while (!game->play(from, to, currentPlayer));

            }
        }
        currentPlayer = (currentPlayer + 1) % 4;
    }

    cout << "Partie terminée!" << endl << endl;
    cout << "Points des joueurs :" << endl;
    for (int i = 0; i < 4; i++) {
        cout << "Joueur " << i << " : " << game->points[i] << " points" << endl;
    }
    delete game;
    return 0;
}