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

	enet_cleanup(this_client);

	return 0;
}

CLIENT * factory_create_client() {
	return (struct CLIENT*)malloc(sizeof(CLIENT*));
}

int host_connect(CLIENT * this_client) {
    //connect
}

void host_disconnect_client(CLIENT * this_client) {
	this_client->is_connected = -1;
    //call disconnect call.
}

////////////////////////////////////////////////////

int handle_io_requests(CLIENT* client, int HOST_TYPE) { //is on a separate thread.

    enet_start_engine(client->engine, HOST_TYPE);

    enet_manage_hosts(client->engine, &io_callback_on_connected_client,
        &io_callback_on_receive_data, &io_callback_on_disconnected_client);
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
