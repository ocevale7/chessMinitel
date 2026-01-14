#include <stdio.h>
#include <string.h>
#include "board.h"
#include "periph/uart.h"
#include "stdio_uart.h"
#include "xtimer.h"
#include "include/Game.h"
#include "include/tools/Minitel.h"
#include "include/tools/LoRa.h"

#if RECORD

static const int partie[][4] = {
    {12, 6, 10, 6},
    {6, 12, 6, 10},
    {1, 6, 3, 6},
    {6, 1, 6, 3}
};

int nb_coups = sizeof(partie) / sizeof(partie[0]);
int current_coup = 0;
#endif

#define MINITEL_UART  UART_DEV(0)
#define MINITEL_BAUD  1200U


#define MAIN_QUEUE_SIZE     (8)
static msg_t _main_msg_queue[MAIN_QUEUE_SIZE]; 

static kernel_pid_t main_pid;

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
    msg_send(&msg, main_pid);
}

void launch_game()
{
    uart_write(MINITEL_UART, (uint8_t *)"\x0C", 1); 

    int players[4] = {0, 1, 2, 3};
    int currentPlayer = 0;
    int nbActivePlayers = 4;

    Game* game = new Game();
    game->start();

    game->board->printBackground();
    game->board->printGuide();
    game->board->afficherMinitel();
    game->board->updateCorners(game, currentPlayer);
    game->board->printBottom();
    game->board->printCurrentPlayer(currentPlayer);

    Couple from(0,0);
    Couple to(0,0);

    while (nbActivePlayers > 1) {
        if (players[currentPlayer] != -1) {
            if(isMyTurn(currentPlayer)) {
#if RECORD
                if(current_coup >= nb_coups) {
                    xtimer_sleep(5);
                    break;
                }
                from.x = partie[current_coup][0];
                from.y = partie[current_coup][1];
                to.x = partie[current_coup][2];
                to.y = partie[current_coup][3];
                current_coup = current_coup + 1;
                game->play(from, to, currentPlayer);
                xtimer_sleep(2);
#else
                do {
                    recupInputMinitel(from, to);
                } while (!game->play(from, to, currentPlayer));

                int coup_a_envoyer[4] = {from.x, from.y, to.x, to.y};
                send_lora_message(coup_a_envoyer);
#endif
            } else {
                int* coup_recu = (int*)malloc(MESSAGE_LENGTH * sizeof(int));
                listen_for_message(coup_recu);
                from.x = coup_recu[0];
                from.y = coup_recu[1];
                to.x = coup_recu[2];
                to.y = coup_recu[3];
                game->play(from, to, currentPlayer);
                
                free(coup_recu);
            }
            game->board->updateDeplacementMinitel(from, to);
            nbActivePlayers -= game->checkMatAndPat(currentPlayer, players);

            
            
        }
        currentPlayer = (currentPlayer + 1) % 4;
        game->board->updateCorners(game, currentPlayer);
        game->board->printCurrentPlayer(currentPlayer);
    }

    /////////////////////////////////////////////////////////
    //  Affichage écran de fin de partie
    //   .
    //   .
    //   .
    /////////////////////////////////////////////////////////

    delete game;
}

int main(void)
{
    main_pid = thread_getpid();
    msg_init_queue(_main_msg_queue, MAIN_QUEUE_SIZE);

    // INITILIZATION OF THE UART FOR THE MINITEL
    if (uart_init(MINITEL_UART, MINITEL_BAUD, rx_cb, (void *)MINITEL_UART) < 0) {
        return 1;
    }
    // if (false){
    //     uart_init(MINITEL_UART, MINITEL_BAUD, rx_cb, (void *)MINITEL_UART);
    // }
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

    do {
        launch_game();
    } while(askIntMinitel("Replay ? 1=Yes 0=No", 2, 1, 22, 1, 1) != 0);
    
    return 0;
}