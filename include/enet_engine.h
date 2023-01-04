/*
        Wrapper for the Enet library.
*/

#ifndef ENET_ENGINE_H
#define ENET_ENGINE_H

#include <enet/enet.h>

#define BUFFER_SIZE 4096

enum CONNECTION_STATE = { CONNECTED = 0, DISCONNECTED = 1, UNRESPONSIVE = 2, POLLED = 3 };
enum PACKET_STATE = { DELIVERED = 0, UNDELIVERED = 1, DELIVERING = 2 };

typedef struct ENET_SERVER {
	ENetAddress * addr,
	ENetHost * host_server,

	long bytes_written,
	long bytes_read,

	char send_buffer[BUFFER_SIZE],
	char recv_buffer[BUFFER_SIZE],

	int connection_state,
	long last_response
} ENET_INFO;

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

typedef struct ENET_PACKET {
	ENetPacket packet,

	int packet_state,
	long packet_size
} ENET_PACKET;

// the main io service.
int enet_poll_run();





int enet_close();
int enet_listen();

int enet_accept();
int enet_connect();

int enet_create_packet();

int enet_sendbytes();
int enet_recvbytes();

int enet_block();

#endif
