#include "../../include/tools/LoRa.h"

extern lora_rx_msg_t last_rx;
extern volatile bool has_rx;

#define CHESS_PREFIX "CHESS:"

void initialize_lora(void)
{
    // Initialization code for LoRa module
    xtimer_sleep(2); // Wait for module to power up
    init_sx1272_cmd(0,NULL);
    lora_setup_cmd(4,(char*[]){"setup","125","12","5"});
    channel_cmd(3,(char*[]){"channel","set","868000000"});
}

void decompose_message(const char* message, int* coup_recu)
{
    int x_init, y_init, x_final, y_final;
    
    // Vérifier et ignorer le préfixe CHESS:
    const char* data_start = message;
    if (strncmp(message, CHESS_PREFIX, strlen(CHESS_PREFIX)) == 0) {
        data_start = message + strlen(CHESS_PREFIX);
    }
    
    sscanf(data_start, "%d,%d,%d,%d", &x_init, &y_init, &x_final, &y_final);
    coup_recu[0] = x_init;
    coup_recu[1] = y_init;
    coup_recu[2] = x_final;
    coup_recu[3] = y_final;
}

void get_message_details(int* coup_recu)
{
    while (1) {
        if (strncmp(last_rx.payload, CHESS_PREFIX, strlen(CHESS_PREFIX)) == 0) {
            // Message recu commancant par notre prefixe
            decompose_message(last_rx.payload, coup_recu);
            memset(last_rx.payload, 0, sizeof(last_rx.payload));
            has_rx = false; 
            return;
        } else {
            // Autre message recu
            memset(last_rx.payload, 0, sizeof(last_rx.payload));
            has_rx = false;
        }
        xtimer_sleep(1);
    }
}

void listen_for_message(int* coup_recu)
{
    if (coup_recu == NULL) {
        puts("Memory allocation failed");
        return;
    }

    memset(last_rx.payload, 0, sizeof(last_rx.payload));
    has_rx = false; 

    listen_cmd(1,(char*[]){"listen"});

    get_message_details(coup_recu);
}

void send_lora_message(int* coup_a_envoyer)
{
    char message[LORA_MESSAGE_BUFFER_SIZE];
    snprintf(message, LORA_MESSAGE_BUFFER_SIZE, "%d,%d,%d,%d", 
             coup_a_envoyer[0], coup_a_envoyer[1], 
             coup_a_envoyer[2], coup_a_envoyer[3]);
    send_cmd(2, (char*[]){"send", message});
}