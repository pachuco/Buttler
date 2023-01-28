/*
        Server/lobby for handling socket connections.
*/

#ifndef SERVER_H
#define SERVER_H

typedef struct SERVER SERVER;

extern SERVER* global_server;

#include "protocol.h"

#include "thread.h"
#include "enet_engine.h"
#include "logger.h"
#include "config.h"

#include "cipher.h"
#include "util.h"

#include "globals.h"

typedef int (*callback)(void*);

typedef struct SERVER {
        ENET_ENGINE* __engine;
        int __connected_clients;
        char* __ip_address;
        short __port;
        int __is_listening;
        THREAD* __host_thread;
        unsigned int __events[64];
        callback __function_pointer_table [64];
} SERVER;

// Primary interface.

int init_server(SERVER* server, char * ipaddr, short port);
int destructor(SERVER * this_server);
SERVER* factory_create_server();

void start_server(SERVER * this_server);
void stop_server(SERVER * this_server);

unsigned long handle_io_requests(void* param); //(SERVER* server, int HOST_TYPE);

/////////////////////////////////

int io_callback_on_connected_client();
int io_callback_on_receive_data();
int io_callback_on_disconnected_client();

/////////////////////////////////

int bind_protocol_event(int (*callback)(void*), int protocol_event);

#endif
