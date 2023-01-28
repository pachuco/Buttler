/*
	Client implementation.
*/

#include "client.h"

BUTTLER_CLIENT * buttler_factory_create_client() {
	return (struct BUTTLER_CLIENT*)malloc(sizeof(BUTTLER_CLIENT*));
}

int buttler_init_client(BUTTLER_CLIENT * client, char * ipaddr, short port) {

	client->__engine = create_enet_engine();
	enet_init(client->__engine, ipaddr, port);

	client->__is_connected = 0;
	client->__ip_address = ipaddr;
	client->__port = port;

	//error check

	return 0;
}

int buttler_client_destructor(BUTTLER_CLIENT * client) {

	enet_cleanup(client->__engine);

	return 0;
}

int buttler_host_connect_client(BUTTLER_CLIENT * client) {

    ENetAddress address;
    ENetPeer * peer;
    ENetHost * host_client;

    enet_address_set_host(&address, "127.0.0.1");
    address.port = 2345;

    peer = enet_host_connect(host_client, &address, 2, 0);

    return 0;
}

int buttler_host_disconnect_client(BUTTLER_CLIENT * client) {
	client->__is_connected = -1;
    //call disconnect call.

    return 0;
}

////////////////////////////////////////////////////

int buttler_handle_io_requests(BUTTLER_CLIENT* client, int HOST_TYPE) { //is on a separate thread.

    enet_start_engine(client->__engine, HOST_TYPE);

    enet_manage_hosts(client->__engine, &io_callback_on_connected_client,
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
