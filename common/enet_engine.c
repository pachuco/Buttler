/*
	Enet engine implementation.
*/

#include "enet_engine.h"

int enet_init() {

    if (enet_initialize () != 0)
    {
        fprintf (stderr, "An error occurred while initializing ENet.\n");
        atexit (enet_deinitialize);

        return EXIT_FAILURE;
    }

    return 0;
}

int enet_cleanup() {
	enet_host_destroy(...);

        atexit(enet_deinitialize);
}

int enet_start_engine() {
	server = enet_host_create (& address /* the address to bind the server host to */, 
                             32      /* allow up to 32 clients and/or outgoing connections */,
                              2      /* allow up to 2 channels to be used, 0 and 1 */,
                              0      /* assume any amount of incoming bandwidth */,
                              0      /* assume any amount of outgoing bandwidth */);
}

int enet_manage_hosts() {
	while (enet_host_service (client, & event, 1000) > 0)
	{
    		switch (event.type)
    		{
    			case ENET_EVENT_TYPE_CONNECT:
				forward_to_bound_callbacks(event);
			break;

			case ENET_EVENT_TYPE_RECEIVE:
				forward_to_bound_callbacks(event);
			break;

			case ENET_EVENT_TYPE_SENT:
				forward_to_bound_callbacks(event);
			break;

			case ENET_EVENT_TYPE_DISCONNECT:
				forward_to_bound_callbacks(event);
			break;
		}
	}
}

// Propagators //////////////////////////

int enet_close() {

}

int enet_listen() {

}

int enet_accept() {

}

int enet_connect() {

}

int enet_sendbytes() {

}

int enet_recvbytes() {

}

int enet_block() {

}
