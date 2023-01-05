/*
        Client host wrapper of enet_engine.
*/

#ifndef CLIENT_H
#define CLIENT_H

#include "protocol.h"
#include "logger.h"
#include "cipher.h"

#include "enet_engine.h"

typedef struct ENET_CLIENT {
        ENetAddress * addr,
        ENetHost * host_client,

        long bytes_written,
        long bytes_read,

        char send_buffer[BUFFER_SIZE],
        char recv_buffer[BUFFER_SIZE],

        int connection_state,
        long last_response
} ENET_CLIENT;

int send_bytes();
int recv_bytes();

int close();
int connect();

int block();

int pack(); //common..

#endif
