/*
	Global variables program/systemwide.
*/

#ifndef GLOBALS_H
#define GLOBALS_H

// Internal libraries.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// External libraries.
#include <enet.h>
#include <mbedtls.h>

// Primary structures.

LOGGER * global_logger = NULL;
CONFIG * global_config = NULL;
SERVER * global_server_lobby = NULL;

// Counters and configurables.

short LISTENING_PORT = 23;
char * IP_ADDRESS = NULL;

int CONNECTED_CLIENTS = 0;

#endif
