#include "../../include/tools/LoRa.h"

extern lora_rx_msg_t last_rx;
extern volatile bool has_rx;

void initialize_lora(void)
{
    // Initialization code for LoRa module
    xtimer_sleep(2); // Wait for module to power up
    init_sx1272_cmd(0,NULL);
    lora_setup_cmd(4,(char*[]){"setup","125","12","5"});
    channel_cmd(3,(char*[]){"channel","set","868000000"});
}

void decompose_message(const char* message, uint8_t* coup_recu)
{
    // Example message format: "X_init,Y_init,X_final,Y_final"
    int x_init, y_init, x_final, y_final;
    sscanf(message, "%d,%d,%d,%d", &x_init, &y_init, &x_final, &y_final);
    coup_recu[0] = (uint8_t)x_init;
    coup_recu[1] = (uint8_t)y_init;
    coup_recu[2] = (uint8_t)x_final;
    coup_recu[3] = (uint8_t)y_final;
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

void listen_for_message(uint8_t* coup_recu)
{
    if (coup_recu == NULL) {
        puts("Memory allocation failed");
        return;
    }

    listen_cmd(1,(char*[]){"listen"});

    get_message_details(coup_recu);
}

void send_lora_message(uint8_t* coup_a_envoyer)
{
    char message[LORA_MESSAGE_BUFFER_SIZE];
    snprintf(message, LORA_MESSAGE_BUFFER_SIZE, "%d,%d,%d,%d", 
             coup_a_envoyer[0], coup_a_envoyer[1], 
             coup_a_envoyer[2], coup_a_envoyer[3]);
    printf("Sending message: %s\n", message);
    send_cmd(2, (char*[]){"send", message});
}