/*
        Server/lobby for handling socket connections.
*/

#ifndef SERVER_H
#define SERVER_H

typedef struct BUTTLER_SERVER BUTTLER_SERVER;

extern BUTTLER_SERVER* global_server;

#include "protocol.h"

#include "thread.h"
#include "enet_engine.h"
#include "logger.h"
#include "config.h"

#include "cipher.h"
#include "util.h"

#include "globals.h"

typedef int (*callback)(void*);

typedef struct BUTTLER_SERVER {
        ENET_ENGINE* __engine;
        int __connected_clients;
        char* __ip_address;
        short __port;
        int __is_listening;
        THREAD* __host_thread;
        unsigned int __events[64];
        callback __function_pointer_table [64];
} BUTTLER_SERVER;

// Primary interface.
BUTTLER_SERVER* buttler_factory_create_server();

int buttler_init_server(BUTTLER_SERVER* server, char * ipaddr, short port);
int buttler_server_destructor(BUTTLER_SERVER * this_server);

void buttler_start_server(BUTTLER_SERVER * this_server);
void buttler_stop_server(BUTTLER_SERVER * this_server);

unsigned long handle_io_requests(void* param); //(SERVER* server, int HOST_TYPE);

/////////////////////////////////

int io_callback_on_connected_client();
int io_callback_on_receive_data();
int io_callback_on_disconnected_client();

/////////////////////////////////

int bind_protocol_event(int (*callback)(void*), int protocol_event);

#endif
