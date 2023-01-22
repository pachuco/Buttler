/*
Usage:
	fm_server -a "0.0.0.0" -p 2345
	fm_server --config cfg.ini
*/

// Internal libraries.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Project Header files.
#include "logger.h"
#include "config.h"
#include "thread.h"
#include "cipher.h"
#include "server.h"

#include "globals.h"

const int MINIMUM_ARGS = 2;

//////////////////////////////////////////////////////////////////////

LOGGER * global_logger = NULL;
CONFIG * global_config = NULL;
SERVER * global_server_lobby = NULL;
CIPHER * global_cipher = NULL;

// Counters and configurables.

char * IP_ADDRESS = NULL;
short LISTENING_PORT = 23;

int CONNECTED_CLIENTS = 0;

//////////////////////////////////////////////////////////////////////

int on_client_opt_out() {
    return 0;
}

int on_client_opt_in() {
    return 0;
}

int on_client_details() {
    return 0;
}

int on_client_fm_command() {
    return 0;
}

int on_client_join_lobby() {
    return 0;
}

int on_client_ready_stream() {
    return 0;
}

// ====================================================================

void set_callback_events() {

    bind_protocol_event(on_client_join_lobby, CLIENT_CONNECT);
    bind_protocol_event(on_client_details, CLIENT_DETAILS);

    bind_protocol_event(on_client_opt_in, CLIENT_OPT_IN);
    bind_protocol_event(on_client_opt_out, CLIENT_OPT_OUT);

    bind_protocol_event(on_client_fm_command, CLIENT_FM_COMMAND);

    bind_protocol_event(on_client_ready_stream, CLIENT_READY_STREAM);
}


//////////////////////////////////////////////////////////////////////

int handle_arguments(int argc, char ** argv) {

    log_info(global_logger, "Server started at @time@...");
    log_info(global_logger, "Parsing arguments...");

    //read and parse arguments...

    return 0;
}

int init(int argc, char ** argv) {

    { // Logger

	global_logger = factory_create_logger();
    	init_logger(global_logger, LOGGER_STDOUT, LOGGER_OVERWRITE);

    	enable_logger(global_logger);

        log_info(global_logger, "Logger ready...");
    }

    { // Ini Config
        log_info(global_logger, "Reading .ini configuration file...");

	global_config = factory_create_config();
	init_config(global_config, "cfg.ini", CONFIG_OVERWRITE);

	close_config(global_config);
    }

    { // Initialization
        log_info(global_logger, "Initializing structures...");

	global_cipher = factory_create_cipher();
    	init_cipher(global_cipher);

    	set_algorithm(global_cipher, CIPHER_TWOFISH);
    }

    return 0;
}

int main(int argc, char ** argv)
{
    if (argc < MINIMUM_ARGS) {
        printf("Usage: ...");
       	return 1;
    } else {
	init(argc, argv);
        handle_arguments(argc, argv);
    }

    // =====================

    { // Server/Lobby
        log_info(global_logger, "Setting up server and lobby...");

	global_server_lobby = factory_create_server();
	init_server(global_server_lobby, argv[1], (short)atoi(argv[2]));

	log_info(global_logger, "Setting callback events...");
	set_callback_events();

	log_info(global_logger, "Starting server...");
        start_server(global_server_lobby); //on a new thread.
    }

    { // Business Logic
        log_info(global_logger, "Displaying welcome message...");

        //Welcome message.
        //Prompt for input.
    }

    { // Input loop & async listen.
        log_info(global_logger, "Awaiting input...");
        log_info(global_logger, "Waiting for connections on IP: x and Port: y");

	//input on main thread.
        //handle_input();
    }

    return 0;
}
