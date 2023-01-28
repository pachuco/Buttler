/*
	Server/lobby implementation.
*/

#include "server.h"

BUTTLER_SERVER * buttler_factory_create_server() {
	return (struct BUTTLER_SERVER*)malloc(sizeof(BUTTLER_SERVER*));
}

int buttler_init_server(BUTTLER_SERVER * this_server, char * ipaddr, short port) {

	log_info(global_logger, "[Server] Creating Server's ENET_Engine...");
	this_server->__engine = create_enet_engine();

	log_info(global_logger, "[Server] Initializing Server's ENET_Engine...");
	enet_init(this_server->__engine, ipaddr, port);

	this_server->__connected_clients = 0;
	this_server->__ip_address = ipaddr;
	this_server->__port = port;

	this_server->__is_listening = -1;

	//error check

	return 0;
}

int buttler_server_destructor(BUTTLER_SERVER * this_server) {

	enet_cleanup(this_server->__engine);

	return 0;
}

void buttler_start_server(BUTTLER_SERVER * this_server) {
    this_server->__is_listening = 0;
	log_info(global_logger, "[Server] Server's ENET_Engine set to listening state...");

	if (!this_server->__is_listening) {
		log_info(global_logger, "[Server] Creating server managing thread...");
		THREAD* server_thread = factory_create_thread();
		this_server->__host_thread = server_thread;

		log_info(global_logger, "[Server] Running server thread...");
		run_thread(server_thread, handle_io_requests, (void*)this_server, ENGINE_TYPE_SERVER);

	} else {
		//server already started. do nothing.
		//warn/print out feedback to user
	}
}

void buttler_stop_server(BUTTLER_SERVER * this_server) {
	this_server->__is_listening = -1;
}

////////////////////////////////////////////////////

unsigned long handle_io_requests(void* param) { //(SERVER* server, int HOST_TYPE) { //is on a separate thread.

    BUTTLER_SERVER* server = (BUTTLER_SERVER*)param;

    log_info(global_logger, "[Server New Thread] ENET loop and callback handling...");

    enet_start_engine(server->__engine, ENGINE_TYPE_SERVER);

    log_info(global_logger, "[Server New Thread] Starting and managing enet hosts...");

    enet_manage_hosts(server->__engine, &io_callback_on_connected_client,
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
