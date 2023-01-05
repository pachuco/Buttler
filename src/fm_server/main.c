/*
Usage:
	fm_server -a "0.0.0.0" -p 23
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
#include "client.h"
#include "input.h"

#include "globals.h"

const int MINIMUM_ARGS = 2

int handle_arguments(int argc, char** argv[]) {

    log_info(global_logger, "Server started at @time@...");
    log_info(global_logger, "Parsing arguments...");

    //read and parse arguments...
}

int init(int argc, char** argv[]) {

    { // Logger
        global_logger = factory_create_logger(LOG.FILE);
        set_log_path(global_logger, ".");
	enable_logger(global_logger);

        log_info(global_logger, "Logger ready...");
    }

    { // Ini Config
        log_info(global_logger, "Reading .ini configuration file...");

	global_config = factory_create_config();
        open_config(config_file);
    }

    { // Initialization
        log_info(global_logger, "Initializing structures...");

	global_cipher = factory_create_cipher(CIPHER_TYPE.TWOFISH);
	server_thread = factory_create_cthreads(&routine);
    }

    return 0;
}

int main(int argc, char** argv[])
{
    if (argc < MINIMUM_ARGS) {
        printf("Usage: ...");
       	return 1;
    } else {
        handle_arguments(argc, argv)
    }

    init(argc, argv);

    // =====================

    { // Server/Lobby
        log_info(global_logger, "Setting up server and lobby...");

	global_server_lobby = factory_create_server();
        start_server(server_lobby, port); //on a new thread.
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
        handle_input();
    }

    return 0;
}
