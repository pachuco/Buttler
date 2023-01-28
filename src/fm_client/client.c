/*
	Client implementation.
*/

#include "client.h"

int init_client(CLIENT * this_client, char * ipaddr, short port) {

	this_client->engine = create_enet_engine();
	enet_init(this_client->engine, ipaddr, port);

	this_client->is_connected = 0;
	this_client->ip_address = ipaddr;
	this_client->port = port;

	//error check

	return 0;
}

int destructor(CLIENT * this_client) {

	enet_cleanup(this_client->engine);

	return 0;
}

CLIENT * factory_create_client() {
	return (struct CLIENT*)malloc(sizeof(CLIENT*));
}

int host_connect_client(CLIENT * this_client) {

    ENetAddress address;
    ENetPeer * peer;
    ENetHost * client;

    enet_address_set_host(&address, "127.0.0.1");
    address.port = 2345;

    peer = enet_host_connect(client, &address, 2, 0);

    return 0;
}

int host_disconnect_client(CLIENT * this_client) {
	this_client->is_connected = -1;
    //call disconnect call.

    return 0;
}

////////////////////////////////////////////////////

int handle_io_requests(CLIENT* client, int HOST_TYPE) { //is on a separate thread.

    enet_start_engine(client->engine, HOST_TYPE);

    enet_manage_hosts(client->engine, &io_callback_on_connected_client,
        &io_callback_on_receive_data, &io_callback_on_disconnected_client);

    return 0;
}

/////////////////////////////////////////////////////////////////////
// Dispatch Handlers
/////////////////////////////////////////////////////////////////////

int io_callback_on_connected_client() {

	return 0;
}

int io_callback_on_receive_data() {

	return 0;
}

int io_callback_on_disconnected_client() {

    return 0;
}

///////////////////////

int bind_protocol_event(int (*callback)(void*), int protocol_event) {
    //push event to array.
    return 0;
}
