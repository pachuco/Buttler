/*
	Server/lobby implementation.
*/

#include "server.h"

int start_server() {
	//main while loop for handling connections

	//on it's own dedicated thread.

	//call "this"->listen(port);

	//update log.
}

int handle_io_request_recv() {

	//check incoming buffer size.
	//read buffer.


	//append to bytes read statistics [unless enet tracks them itself]


	//parsing of packets

	//see if enet supports this or if it's needed to loop to extract the buffer

	//case CLIENT_OPT_IN
		handle_client_opt_in();
	//case CLIENT_OPT_OUT
		handle_client_opt_out();
	//case CLIENT_FM_COMMAND
		handle_client_fm_command();
	//case CLIENT_READY
		handle_client_ready();
			//trigger heartbeat and audio chunk streaming

	//update log.

}

//decouple the enet engine from the audio parsing/streaming. it needs it's own module. pass messages around instead.

int handle_io_request_send() {
	//loop to send buffer


	//append to bytes sent statstics [unless enet tracks them itself]

	//update log.
}

int on_accept_connected() {
	//spawn thread for client.

	//check MAX_THREAD property to see if can accept connection or not.

	//check MAX_CONN property to see if full queue or not.

	//add user to list of connected sockets/hosts.

	//async_send_exchage

	//async_recv_post_io

	//update log
}

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

int listen() {

}

int accept() {

}

int handle_user_opt_in() {

}

int handle_user_opt_out() {

}

int broadcast() {

}

int broadcast_packet() {

}

int on_receive_packet() {

}

int on_sent() {

}

int on_sent_packet() {

}
