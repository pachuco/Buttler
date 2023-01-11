/*
        Wrapper for the Enet library.
*/

#ifndef ENET_ENGINE_H
#define ENET_ENGINE_H

#include <stdio.h>
#include <stdlib.h>

#include <enet/enet.h>

#include "logger.h"

#define BUFFER_SIZE 4096

extern const unsigned int CONN_STATE_CONNECTED;
extern const unsigned int CONN_STATE_DISCONNECTED;
extern const unsigned int CONN_STATE_UNRESPONSIVE;
extern const unsigned int CONN_STATE_POLLED;

typedef struct ENET_ENGINE {
	ENetAddress * addr;
	ENetHost * host_server;
	ENetHost * host_client;

	ENetEvent * host_event;

	long bytes_written;
	long bytes_read;

	char send_buffer[BUFFER_SIZE];
	char recv_buffer[BUFFER_SIZE];

	int connection_state;
	long last_response;
} ENET_ENGINE;

ENET_ENGINE* create_enet_engine();

// the main io service.
int enet_init(ENET_ENGINE* engine, char * ip_address, short port);
int enet_cleanup(ENET_ENGINE* engine);

int enet_start_engine(ENET_ENGINE* engine);
int enet_manage_hosts(ENET_ENGINE* engine, int (*on_connected_callback)(void*),
                      int (*on_received_cacllback)(void*), int (*on_disconnected_callback)(void*));

int enet_destruct();

// Propagators

int enet_on_connect();
int enet_on_receive();
int enet_on_disconnect();

//int enet_create_packet();

#endif
