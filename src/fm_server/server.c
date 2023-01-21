/*
	Server/lobby implementation.
*/

#include "server.h"

int init_server(SERVER * this_server, char * ipaddr, short port) {

	log_info(global_logger, "Creating Server's ENET_Engine...");
	this_server->engine = create_enet_engine();

	log_info(global_logger, "Initializing Server's ENET_Engine...");
	enet_init(this_server->engine, ipaddr, port);

	this_server->connected_clients = 0;
	this_server->ip_address = ipaddr;
	this_server->port = port;

	this_server->is_listening = -1;

	//error check

	return 0;
}

int destructor(SERVER * this_server) {

	enet_cleanup(this_server->engine);

	return 0;
}

SERVER * factory_create_server() {
	return (struct SERVER*)malloc(sizeof(SERVER*));
}

void start_server(SERVER * this_server) {
    this_server->is_listening = 0;
	log_info(global_logger, "Server's ENET_Engine set to listening state...");

	if (!this_server->is_listening) {
		log_info(global_logger, "Creating server managing thread...");
		THREAD* server_thread = factory_create_thread();
		this_server->host_thread = server_thread;

		log_info(global_logger, "Running server thread...");
		run_thread(server_thread, handle_io_requests, this_server, ENGINE_TYPE_SERVER);

	} else {
		//server already started. do nothing.
		//warn/print out feedback to user
	}
}

void stop_server(SERVER * this_server) {
	this_server->is_listening = -1;
}

////////////////////////////////////////////////////

int handle_io_requests(SERVER* server, int HOST_TYPE) { //is on a separate thread.

    log_info(global_logger, "[On separate thread] ENET loop and callback handling...");

    enet_start_engine(server->engine, HOST_TYPE);

    enet_manage_hosts(server->engine, &io_callback_on_connected_client,
        &io_callback_on_receive_data, &io_callback_on_disconnected_client);

    return 0;
}

/////////////////////////////////////////////////////////////////////
// Dispatch Handlers
/////////////////////////////////////////////////////////////////////

int io_callback_on_connected_client() {
    //spawn thread for client.

	//check MAX_THREAD property to see if can accept connection or not.

	//check MAX_CONN property to see if full queue or not.

	//add user to list of connected sockets/hosts.

	//async_send_exchage

	//async_recv_post_io

	//update log
	return 0;
}

int io_callback_on_receive_data() {
    /*check incoming buffer size.
	read buffer.


	decrypt packet();
	parse_packet_header();

	append to bytes read statistics [unless enet tracks them itself]


	parsing of packets

	//see if enet supports this or if it's needed to loop to extract the buffer


	int CONTEXT_EVENT = ...getevent_protocol;
	int number_of_events = ...;

    for (int i = 0; i < number_of_events; i++) {
        //loop through events

        if (CONTEXT_EVENT == events[i]) {

            invoke_callback(callback[i], SERVER* contextual_server, CLIENT* contextual_client);
        } else {
            //packet dropped, no protocol.
        }
    }

	//update log.
	*/
	return 0;
}

int io_callback_on_disconnected_client() {
    return 0;
}

//decouple the enet engine from the audio parsing/streaming. it needs it's own module. pass messages around instead.

///////////////////////

int bind_protocol_event(int (*callback)(void*), int protocol_event) {
    //push event to array.
    return 0;
}
