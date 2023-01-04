/*
        Wrapper for the Enet library.
*/

#ifndef ENET_ENGINE_H
#define ENET_ENGINE_H

#include <enet/enet.h>

#define BUFFER_SIZE 4096

enum CONNECTION_STATE = { CONNECTED = 0, DISCONNECTED = 1, UNRESPONSIVE = 2, POLLED = 3 };

typedef struct ENET_SERVER {
	ENetAddress * addr,
	ENetHost * host_server,

	int bytes_written,
	int bytes_read,

	char send_buffer[BUFFER_SIZE],
	char recv_buffer[BUFFER_SIZE],

	int state,
	int last_response
} ENET_INFO;

typedef struct ENET_CLIENT {
	ENetAddress * addr,
	ENetHost * host_client,

	int bytes_written,
	int bytes_read,

	char send_buffer[BUFFER_SIZE],
	char recv_buffer[BUFFER_SIZE],

	int state,
	int last_response
} ENET_CLIENT;

int enet_close();
int enet_listen();

int enet_accept();
int enet_connect();

int enet_create_packet();

int enet_sendbytes();
int enet_recvbytes();

int enet_block();

#endif
