/*
	Server/lobby implementation.
*/

#include "server.h"

int start_server() {
	//main while loop for handling connections

	//on it's own dedicated thread.
}

int handle_io_request() {
	//parsing of packets
}

int on_connected() {
	//spawn thread for client.

	//check MAX_THREAD property to see if can accept connection or not.

	//add user to list of connected sockets/hosts.
}

int on_handshake_exchange() {

}

int on_disconnect() {

}

int on_terminate() {

}

int on_heartbeat() {

}

int serialize_packet() {
	//NBO, packet unwrapping, decryption.
}

int deserialize_packet() {
	//NBO, packet unwrapping, decryption.
}




close() {

}

listen() {

}

accept() {

}

on_accept() {

}

on_receive() {

}

handle_user_opt_in() {

}

handle_user_opt_out() {

}

broadcast() {

}

broadcast_packet() {

}

on_receive_packet() {

}

on_sent() {

}

on_sent_packet() {

}
