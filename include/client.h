/*
        Client for handling communication.
*/

#ifndef CLIENT_H
#define CLIENT_H

typedef struct BUTTLER_CLIENT BUTTLER_CLIENT;

extern BUTTLER_CLIENT* global_client;

#include "protocol.h"

#include "thread.h"
#include "enet_engine.h"
#include "logger.h"
#include "config.h"

#include "cipher.h"
#include "util.h"

typedef int (*callback)(void*);

typedef struct BUTTLER_CLIENT {
	ENET_ENGINE* __engine;
	THREAD* __host_thread;

	int __is_connected;

	char* __ip_address;
	short __port;

	unsigned int __events[64];
    callback __function_pointer_table [64];

} BUTTLER_CLIENT;

// Primary interface.

BUTTLER_CLIENT* buttler_factory_create_client();

int buttler_init_client(BUTTLER_CLIENT* client, char * ipaddr, short port);
int buttler_client_destructor(BUTTLER_CLIENT * client);

int buttler_host_connect_client(BUTTLER_CLIENT * client);
int buttler_host_disconnect_client(BUTTLER_CLIENT * client);

int buttler_handle_io_requests(BUTTLER_CLIENT* client, int HOST_TYPE);

/////////////////////////////////

int io_callback_on_connected_client();
int io_callback_on_receive_data();
int io_callback_on_disconnected_client();

/////////////////////////////////

int bind_protocol_event(int (*callback)(void*), int protocol_event);

#endif
