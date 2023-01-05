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
	ENET_ENGINE* engine,
	..
} SERVER;

// Primary interface.

int init();
void start_server();
void stop_server();
int destructor();

int handle_io_requests();
int bind_callback(function pointers);

// Dispatchers

int on_io_request_received(IO_CONTEXT* context);
int on_io_request_sent(IO_CONTEXT* context);
int on_io_request_connected(IO_CONTEXT* context);
int on_io_request_disconnected(IO_CONTEXT* context);

// Protocol handlers

int on_handshake_exchange();
int on_terminate();
int on_heartbeat();

int serialize_packet();
int deserialize_packet();

void close();

int handle_user_opt_in();
int handle_user_opt_out();

int broadcast();
int broadcast_packet();

#endif
