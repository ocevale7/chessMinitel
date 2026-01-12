// Testing file for LoRa communication module
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "xtimer.h"
#include "../include/tools/utils_LoRa.h"

extern lora_rx_msg_t last_rx;
extern volatile bool has_rx;

#ifdef TEST_LORA_UTILS
int main(void) {

    //init_sx1272_cmd(0,NULL);

    /* start the shell */
    puts("Initialization successful - starting the shell now");
    //char line_buf[SHELL_DEFAULT_BUFSIZE];

    //shell_run(shell_commands, line_buf, SHELL_DEFAULT_BUFSIZE);

    init_sx1272_cmd(0,NULL);

    puts("Starting LoRa test application\n");
    lora_setup_cmd(4,(char*[]){"setup","125","12","5"});
    puts("Setting channel to 868000000");
    channel_cmd(3,(char*[]){"channel","set","868000000"});
    puts("Listening...");
    listen_cmd(1,(char*[]){"listen"});

    while (1) {
        if (has_rx) {
            has_rx = false;

            printf("RX: \"%s\" (%u bytes), RSSI=%i, SNR=%i\n",
                last_rx.payload,
                (unsigned)last_rx.len,
                last_rx.info.rssi,
                (int)last_rx.info.snr);
        }
        xtimer_sleep(1);
    }

    return 0;
}
#endif // TEST_LORA_UTILS

#ifdef TEST_LORA_COMM
#include "../include/LoRa.h"

void main_sender(void)
{
    initialize_lora();

    uint8_t coup_a_envoyer[4] = {0, 1, 2, 3};
    send_lora_message(coup_a_envoyer);
}

void main_receiver(void)
{
    initialize_lora();

    uint8_t* coup_recu = malloc(MESSAGE_LENGTH * sizeof(uint8_t));
    if (coup_recu == NULL) {
        puts("Memory allocation failed");
        return;
    }
    listen_for_message(coup_recu);

    printf("Received move: %d, %d, %d, %d\n",
           coup_recu[0], coup_recu[1], coup_recu[2], coup_recu[3]);
    free(coup_recu);
}

int main(void) {
    #ifdef MODE_SENDER
        main_sender();
    #elif defined(MODE_RECEIVER)
        main_receiver();
    #else
        puts("ERROR: No mode selected. Define MODE_SENDER or MODE_RECEIVER.");
        return -1;
    #endif

    return 0;
}

#endif // TEST_LORA_COMM