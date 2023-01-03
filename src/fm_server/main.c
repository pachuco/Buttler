#include <stdio.h>
#include <stdlib.h>

#include "logger.h"
#include "config.h"

#include "globals.h"

//byte order?
//hungarian notation

struct LOGGER * global_logger = NULL;
struct CONFIG * global_config = NULL;
struct SERVER * global_server_lobby = NULL;

int connected_clients = 0;
short listening_port = 23;
char ** ip_address = NULL;

enum LOG = { FILE, STDOUT, STDERR };

int init(int argc, char** argv[]) {

    { // Logger
        global_logger = factory_create_logger();
        set_log(global_logger, LOG.FILE, "."));

        log_info(global_logger, "Logger ready...");
    }

    { // Arguments
        log_info(global_logger, "Server started at @time@...");
        log_info(global_logger, "Parsing arguments...");

        read and parse arguments something something if argc and argv[2.];
    }

    { // Ini Config
        log_info(global_logger, "Reading .ini configuration file...");
        // move this to config file. struct CONFIG * config_file = (struct CONFIG*)malloc(sizeof(CONFIG));
	global_config = factory_create_config();
        open_config(config_file);
    }

    { // Initialization
        log_info(global_logger, "Initializing structures...");
        //handle initialization.
    }

    return 0;
}

int main(int argc, char** argv[])
{
    init(argc, argv);

    { // Server/Lobby
        log_info(global_logger, "Setting up server and lobby...");
        // move to server side file. struct SERVER_LOBBY * server_lobby = (struct SERVER*)malloc(sizeof(SERVER_LOBBY));
	global_server_lobby = factory_create_server();
        start_server(server_lobby, port); //on a new thread. use pthread.
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
