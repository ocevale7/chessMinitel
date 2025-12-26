#include <stdio.h>
#include <string.h>
#include "board.h"
#include "periph/uart.h"
#include "stdio_uart.h"
#include "xtimer.h"
#include "include/Game.h"
#include "include/tools/LoRa.h"

#define MINITEL_UART  UART_DEV(0)
#define MINITEL_BAUD  1200U

#ifndef JOUEUR
#define JOUEUR ""
#endif

bool isMyTurn(int currentPlayer) {
    for (size_t i = 0; i < strlen(JOUEUR); i++) {
        if (JOUEUR[i] - '0' == currentPlayer) {
            return true;
        }
    }
    return false;
}

static void rx_cb(void *uart, uint8_t c);

static void rx_cb(void *uart, uint8_t c)
{
    msg_t msg;
    msg.type = (int)uart;
    msg.content.value = (uint32_t)c;
    msg_send(&msg, 1);
}

int main(void)
{

    // INITILIZATION OF THE UART FOR THE MINITEL
    if (uart_init(MINITEL_UART, MINITEL_BAUD, rx_cb, (void *)MINITEL_UART) < 0) {
        return 1;
    }

    uart_mode(MINITEL_UART, UART_DATA_BITS_7, UART_PARITY_EVEN, UART_STOP_BITS_1);

    LED_RED_TOGGLE;

    xtimer_sleep(1);
    LED_RED_TOGGLE;

    // Clear screen
    uart_write(MINITEL_UART, (uint8_t *)"\x0C", 1); 

    xtimer_sleep(1);

    // INITILIZATION OF THE LORA MODULE

    initialize_lora();

    // START OF THE CHESS GAME

    int players[4] = {0, 1, 2, 3};
    int currentPlayer = 0;
    int nbActivePlayers = 4;

    Game* game = new Game();
    game->start();

    game->board->afficherMinitel();
    
    while (nbActivePlayers > 1) {
        if (players[currentPlayer] != -1) {
            if (game->isEchecEtMat(currentPlayer)) {
                players[currentPlayer] = -1;
                nbActivePlayers--;
                game->kill(currentPlayer);
            } else {

                if(isMyTurn(currentPlayer)) {
                    Couple from = Couple(0,0);
                    Couple to = Couple(0,0);

                    do {
                        string move = game->recupInputMinitel();

                    } while (!game->play(from, to, currentPlayer));
                } else {
                    int* coup_recu = (int*)malloc(MESSAGE_LENGTH * sizeof(int));
                    listen_for_message(coup_recu);
                    Couple from(coup_recu[0], coup_recu[1]);
                    Couple to(coup_recu[2], coup_recu[3]);
                    game->play(from, to, currentPlayer);
                    free(coup_recu);
                }
            }
        }
        currentPlayer = (currentPlayer + 1) % 4;
    }

    // cout << "Partie terminée!" << endl << endl;
    // cout << "Points des joueurs :" << endl;
    // for (int i = 0; i < 4; i++) {
    //     cout << "Joueur " << i << " : " << game->points[i] << " points" << endl;
    // }
    delete game;
    
    return 0;
}