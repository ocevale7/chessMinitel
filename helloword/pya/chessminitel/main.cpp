#include <stdio.h>
#include <string.h>
#include "board.h"
#include "periph/uart.h"
#include "stdio_uart.h"
#include "xtimer.h"
#include "include/Game.h"


#define MINITEL_UART  UART_DEV(0)
#define MINITEL_BAUD  1200U


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

    Game* game = new Game();
    game->start();

    game->board->afficherMinitel();
    
    while (1) {
        //uart_write(MINITEL_UART, (uint8_t *)".", 1);
        LED_GREEN_ON;
        xtimer_sleep(1);
        LED_GREEN_OFF;
        xtimer_sleep(1);
    }
    return 0;
}