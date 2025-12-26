#ifndef LORA_H
#define LORA_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>

#include "../include/utils_LoRa.h"

#define MESSAGE_LENGTH 4
#define LORA_MESSAGE_BUFFER_SIZE 64

void initialize_lora(void);
void listen_for_message(uint8_t* coup_recu);
void send_lora_message(uint8_t* coup_a_envoyer);

#ifdef __cplusplus
}
#endif

#endif // LORA_H
