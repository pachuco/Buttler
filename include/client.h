/*
        Client for handling communication.
*/

#ifndef CLIENT_H
#define CLIENT_H

typedef struct CLIENT CLIENT;

extern CLIENT* global_client;

#include "protocol.h"

#include "thread.h"
#include "enet_engine.h"
#include "logger.h"
#include "config.h"

#include "cipher.h"
#include "util.h"

typedef int (*callback)(void*);

typedef struct CLIENT {
	ENET_ENGINE* engine;
	THREAD* host_thread;

	int is_connected;

	char *ip_address;
	short port;

	unsigned int events[64];
    callback function_pointer_table [64];

} CLIENT;

// Primary interface.

int init_client(CLIENT* client, char * ipaddr, short port);
int destructor(CLIENT * this_client);
CLIENT* factory_create_client();

int host_connect_client(CLIENT * this_client);
int host_disconnect_client(CLIENT * this_client);

/////////////////////////////////

int io_callback_on_connected_client();
int io_callback_on_receive_data();
int io_callback_on_disconnected_client();

/////////////////////////////////

int bind_protocol_event(int (*callback)(void*), int protocol_event);

#endif
