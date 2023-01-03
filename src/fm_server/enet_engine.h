/*
        Wrapper for the Enet library.
*/

#ifndef ENET_ENGINE_H
#define ENET_ENGINE_H

int enet_close();
int enet_listen();

int enet_accept();
int enet_connect();

int enet_sendbytes();
int enet_recvbytes();

int enet_block();

#endif
