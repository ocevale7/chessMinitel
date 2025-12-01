#include <stdio.h>
#include <string.h>
#include "board.h"
#include "periph/uart.h"
#include "xtimer.h"

/* 
 * Configuration pour le Minitel 
 * UART_DEV(1) est généralement sur les pins PA2 (TX) et PA3 (RX) 
 * ou PA9 (TX) et PA10 (RX) selon la version de la Wyres.
 */
#define MINITEL_UART  UART_DEV(0)
#define MINITEL_BAUD  1200

int main(void)
{
    // 1. Initialisation de la sortie standard (pour le debug sur PC via USB)
    puts("Démarrage du programme Minitel...");

    // 2. Initialisation du port Minitel à 1200 bauds
    // On tente d'initialiser. Si ça échoue (ex: pas de 2ème UART), on l'affiche sur le PC.
    if (uart_init(MINITEL_UART, MINITEL_BAUD, NULL, NULL) < 0) {
        printf("ERREUR: Impossible d'initialiser UART_DEV(1) !\n");
        printf("Vérifiez que la carte possède bien un second UART accessible.\n");
        return 1;
    }

    printf("UART Minitel initialisé. Connectez le Minitel maintenant.\n");

    LED_RED_TOGGLE;
    // Petite pause pour laisser le temps au Minitel de s'allumer si besoin
    xtimer_sleep(1);
    LED_RED_TOGGLE;
    // 3. Commandes Minitel (Code ASCII)
    // \x0C = Effacer l'écran (Form Feed)
    uart_write(MINITEL_UART, (uint8_t *)"\x0C", 1); 
    //LED_RED_ON;
    xtimer_sleep(1);

    // 4. Envoi du texte
    char message[] = "\r\nHello Minitel !\r\nDe la part de RIOT OS.\r\n";
    uart_write(MINITEL_UART, (uint8_t *)message, strlen(message));

    // Boucle infinie pour envoyer un point toutes les secondes
    while (1) {
        uart_write(MINITEL_UART, (uint8_t *)".", 1);
        LED_GREEN_ON;
        xtimer_sleep(1);
        LED_GREEN_OFF;
        xtimer_sleep(1);
    }

    return 0;
}