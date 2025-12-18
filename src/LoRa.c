#include "../include/LoRa.h"

extern lora_rx_msg_t last_rx;
extern volatile bool has_rx;

void initialize_lora(void)
{
    // Initialization code for LoRa module
    init_sx1272_cmd(0,NULL);
    lora_setup_cmd(4,(char*[]){"setup","125","12","5"});
    channel_cmd(3,(char*[]){"channel","set","868000000"});
}

void decompose_message(const char* message, uint8_t* coup_recu)
{
    // Example message format: "X_init,Y_init,X_final,Y_final"
    sscanf(message, "%hhd,%hhd,%hhd,%hhd", &coup_recu[0], &coup_recu[1], &coup_recu[2], &coup_recu[3]);
}

void get_message_details(uint8_t* coup_recu)
{
    while (1) {
        if (has_rx) {
            has_rx = false;
            decompose_message(last_rx.payload, coup_recu);
            return;
        }
        xtimer_sleep(1);
    }
}

uint8_t* listen_for_message(void)
{
    uint8_t* coup_recu = malloc(MESSAGE_LENGTH * sizeof(uint8_t));
    if (coup_recu == NULL) {
        puts("Memory allocation failed");
        return NULL;
    }

    listen_cmd(1,(char*[]){"listen"});

    get_message_details(coup_recu);
    return coup_recu;
}

void send_lora_message(uint8_t* coup_a_envoyer)
{
    char message[LORA_MESSAGE_BUFFER_SIZE];
    snprintf(message, LORA_MESSAGE_BUFFER_SIZE, "%d,%d,%d,%d", 
             coup_a_envoyer[0], coup_a_envoyer[1], 
             coup_a_envoyer[2], coup_a_envoyer[3]);
    send_cmd(2, (char*[]){"send", message});
}