/*
        Server/lobby for handling socket connections.
*/

#ifndef SERVER_H
#define SERVER_H

#include "protocol.h"

#include "thread.h"
#include "enet_engine.h"
#include "logger.h"
#include "config.h"

#include "cipher.h"
#include "util.h"

typedef int (*callback)(void*);

typedef struct SERVER {
	ENET_ENGINE* engine;
	int connected_clients;
	char *ip_address;
	short port;
	int is_listening;
	THREAD* host_thread;
	unsigned int events[64];
    callback function_pointer_table [64];

} SERVER;

// Primary interface.

int init_server(SERVER* server, char * ipaddr, short port);
int destructor();
SERVER* factory_create_server();

void start_server();
void stop_server();

/////////////////////////////////

int io_callback_on_connected_client();
int io_callback_on_receive_data();
int io_callback_on_disconnected_client();

/////////////////////////////////

int bind_protocol_event(int (*callback)(void*), int protocol_event);

#endif
