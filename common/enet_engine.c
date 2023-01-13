/*
	Enet engine implementation.
*/

#include "enet_engine.h"

const unsigned int ENGINE_TYPE_SERVER = 10;
const unsigned int ENGINE_TYPE_CLIENT = 11;

const unsigned int CONN_STATE_CONNECTED = 1;
const unsigned int CONN_STATE_DISCONNECTED = 2;
const unsigned int CONN_STATE_UNRESPONSIVE = 3;
const unsigned int CONN_STATE_POLLED = 4;

ENET_ENGINE* create_enet_engine() {
    return (ENET_ENGINE*)malloc(sizeof(ENET_ENGINE));
}

int enet_init(ENET_ENGINE* engine, char * ip_address, short port) {

    engine->ip_addr = ip_address;
    engine->port = port;

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
	enet_host_destroy(engine->host_socket);

    atexit(enet_deinitialize);

    return 0;
}

int enet_start_engine(ENET_ENGINE* engine, int ENGINE_TYPE) {
    engine->ENGINE_TYPE = ENGINE_TYPE;

    if (engine->ENGINE_TYPE == ENGINE_TYPE_SERVER) {

        if (strcmp(engine->ip_addr, "0.0.0.0")) {
            engine->host_addr.host = ENET_HOST_ANY;
            engine->host_addr.port = engine->port;
        } else {
            enet_address_set_host(&engine->host_addr, engine->ip_addr);
        }

        engine->host_socket = enet_host_create(&engine->host_addr, 32, 2, 0, 0);

    } else if (ENGINE_TYPE == ENGINE_TYPE_CLIENT) {
            enet_address_set_host(&engine->host_addr, engine->ip_addr);
    } else {
            //... unknown engine type.
    }

	return 0;
}

int enet_manage_hosts(ENET_ENGINE* engine, int (*on_connected_callback)(void*),
                      int (*on_received_cacllback)(void*), int (*on_disconnected_callback)(void*)) {

	while (enet_host_service (engine->host_socket, &engine->host_event, 1000) > 0)
	{
        switch (engine->host_event.type) //.type?...
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
