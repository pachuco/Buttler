/*
	Enet engine implementation.
*/

#include "enet_engine.h"

const unsigned int CONN_STATE_CONNECTED = 1;
const unsigned int CONN_STATE_DISCONNECTED = 2;
const unsigned int CONN_STATE_UNRESPONSIVE = 3;
const unsigned int CONN_STATE_POLLED = 4;

ENET_ENGINE* create_enet_engine() {
    //return malloc

    return NULL;
}

int enet_init(ENET_ENGINE* engine, char * ip_address, short port) {

    //engine->addr = ...;
    //initialize other structs...

    if (enet_initialize () != 0)
    {
        fprintf (stderr, "An error occurred while initializing ENet.\n");
        atexit (enet_deinitialize);

        return EXIT_FAILURE;
    }

    return 0;
}

int enet_cleanup(ENET_ENGINE* engine) {
	//enet_host_destroy(...);

    atexit(enet_deinitialize);

    return 0;
}

int enet_start_engine(ENET_ENGINE* engine) {
	engine->host_server = enet_host_create(&engine->addr, 32, 2, 0, 0);

	return 0;
}

int enet_manage_hosts(ENET_ENGINE* engine) {
	while (enet_host_service (engine->host_client, &engine->host_event, 1000) > 0)
	{
        switch (engine->host_event->type) //.type?...
        {
            case ENET_EVENT_TYPE_CONNECT:
                enet_on_connect(engine->host_event);
            break;

            case ENET_EVENT_TYPE_RECEIVE:
                enet_on_receive(engine->host_event);
            break;

            case ENET_EVENT_TYPE_DISCONNECT:
                enet_on_disconnect(engine->host_event);
            break;
        }
	}

	return 0;
}

int enet_destruct() {

    //free other structs.

    return 0;
}

// Propagators //////////////////////////

int enet_on_connect() {
    return 0;
}

int enet_on_receive() {
    return 0;
}

int enet_on_disconnect() {
    return 0;
}

//int enet_create_packet() {

//}
