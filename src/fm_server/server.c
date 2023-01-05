/*
	Server/lobby implementation.
*/

#include "server.h"

int init(SERVER * this_server) {

	this_server->engine = (struct ENET_SERVER*)malloc(sizeof(ENET_SERVER*));
	enet_init(this_server->engine);

	//error check

	return 0;
}

int destructor(SERVER * this_server) {

	enet_cleanup(this_server);
}

SERVER * factory_create_server() {
	return (struct SERVER*)malloc(sizeof(SERVER*));
}

void start_server(SERVER * this_server) {
	init(this_server);

	if (!this_server->is_listening) {
		this_server->listening_thread = new thread.@handle_io_requests;
	} else {
		//server already started. do nothing.
		//warn/print out feedback to user
	}
}

void stop_server(SERVER * this_server) {
	this_server->is_listening = false;
}

int handle_io_requests() {
	this_server->is_listening = true;
	this_server->listen(port);

	//update log.

	while (context->is_listening) {
		this_server->bind_callbacks(
			on_io_request_received,
			on_io_request_sent,
			on_io_request_connected,
			on_io_request_disconnected
		);
	}
}

int bind_callback(routine pointers) {
	//DISPATCH TO APPROPRIATE CALLBACK.

	enet_engine->io_receive_callback = pointers;
	enet_engine->io_send_callback = pointers;
	enet_engine->io_connect_callback = pointers;
	enet_engine->io_disconnect_callback = pointers;
}

/////////////////////////////////////////////////////////////////////
// Dispatch Handlers
/////////////////////////////////////////////////////////////////////

int on_io_request_received(IO_CONTEXT * context //probably a void pointer needed) {

	check incoming buffer size.
	read buffer.


	decrypt packet();
	parse_packet_header();

	append to bytes read statistics [unless enet tracks them itself]


	parsing of packets

	//see if enet supports this or if it's needed to loop to extract the buffer

	case CLIENT_OPT_IN
		handle_client_opt_in();
	break;

	case CLIENT_OPT_OUT
		handle_client_opt_out();
	break;

	case CLIENT_FM_COMMAND
		handle_client_fm_command();
	break;

	case CLIENT_READY
		handle_client_ready();
		//trigger heartbeat and audio chunk streaming
	break;

	//update log.

}

//decouple the enet engine from the audio parsing/streaming. it needs it's own module. pass messages around instead.

int on_io_request_sent() {
	//loop to send buffer


	//append to bytes sent statstics [unless enet tracks them itself]

	//update log.
}

int on_io_request_connected() {
	//spawn thread for client.

	//check MAX_THREAD property to see if can accept connection or not.

	//check MAX_CONN property to see if full queue or not.

	//add user to list of connected sockets/hosts.

	//async_send_exchage

	//async_recv_post_io

	//update log
}

int on_io_request_disconnected() {

}

/////////////////////////////////////////////////////////////////////
// Protocol parsing handlers.
/////////////////////////////////////////////////////////////////////

int on_handshake_exchange(client_struct) {
	//timestamp packets and/or TLS handshaking for certificates/encrypted traffic.

	//no compression

	//update log
}

int on_disconnect(client_struct) {
	//deallocate pointers

	//remove client from array

	//update log
}

int on_terminate(client_struct) {
	//deallocate pointers

	//remove client from array

	//update log
}

int on_heartbeat(client_struct) {
	//poll target. start timer.

	//update log.
}

int on_heartbeat_response() {
	//reset timer. wait for next poll.
}

int buffer_push() {

}

int buffer_pop() {

}

int serialize_packet() {
	//NBO, packet unwrapping, decryption.
}

int deserialize_packet() {
	//NBO, packet unwrapping, decryption.
}

void close_client() {

}

int handle_user_opt_in() {

}

int handle_user_opt_out() {

}

int broadcast() {

}

int broadcast_packet() {

}
