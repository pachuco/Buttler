/*
        Server/lobby for handling socket connections.
*/

#ifndef SERVER_H
#define SERVER_H

#include "protocol.h"

#include "thread.h"
#include "enet_engine.h"
#include "client.h"
#include "logger.h"
#include "config.h"

#include "cipher.h"
#include "util.h"

typedef struct SERVER {
	ENET_ENGINE* engine;
	int connected_clients;
	char *ip_address;
	short port;
} SERVER;

// Primary interface.

int init_server(SERVER* server, char * ipaddr, short port);
void start_server();
void stop_server();
int destructor();

/////////////////////////////////

//fold these into a single function later when you have time.

int bind_on_client_join_lobby(int (*callback)(void*), int protocol_event);
int bind_on_client_details(int (*callback)(void*), int protocol_event);

int bind_on_client_opt_in(int (*callback)(void*), int protocol_event);
int bind_on_client_opt_out(int (*callback)(void*), int protocol_event);

int bind_on_client_fm_command(int (*callback)(void*), int protocol_event);

int bind_on_client_ready_stream(int (*callback)(void*), int protocol_event);

#endif
