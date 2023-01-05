/*
	Global variables program/systemwide.
*/

#ifndef GLOBALS_H
#define GLOBALS_H

// Primary structures.

LOGGER * global_logger = NULL;
CONFIG * global_config = NULL;
SERVER * global_server_lobby = NULL;
CIPHER * global_cipher = NULL;

// Counters and configurables.

char * IP_ADDRESS = NULL;
short LISTENING_PORT = 23;

int CONNECTED_CLIENTS = 0;

#endif
