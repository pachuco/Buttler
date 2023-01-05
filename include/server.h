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

int start_server();
int handle_io_request();
int on_connected();
int on_handshake_exchange();
int on_disconnect();
int on_terminate();
int on_heartbeat();

int serialize_packet();
int deserialize_packet();


void close();
int listen();
int accept();
void on_accept();
void on_receive();
int handle_user_opt_in();
int handle_user_opt_out();
int broadcast();
int broadcast_packet();
int on_receive_packet();
int on_sent();
int on_sent_packet();

#endif
