#ifndef UTILS_LoRa_H
#define UTILS_LoRa_H
#ifdef __cplusplus
extern "C" {
#endif

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>

#include "thread.h"

#include "net/netdev.h"
#include "net/netdev/lora.h"
#include "net/lora.h"

#include "board.h"

#include "sx127x_internal.h"
#include "sx127x_params.h"
#include "sx127x_netdev.h"

#include "fmt.h"

#include "xtimer.h"

#define LORA_MAX_PAYLOAD 64

typedef struct {
    size_t len;
    char payload[LORA_MAX_PAYLOAD];
    netdev_lora_rx_info_t info;
} lora_rx_msg_t;

int init_sx1272_cmd(int argc, char **argv);
int lora_setup_cmd(int argc, char **argv);
int listen_cmd(int argc, char **argv);
int channel_cmd(int argc, char **argv);
int send_cmd(int argc, char **argv);

#ifdef __cplusplus
}
#endif
#endif // UTILS_LoRa_H