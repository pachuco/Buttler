/*
	Global variables program/systemwide.
*/

#ifndef GLOBALS_H
#define GLOBALS_H

// Primary structures.

extern LOGGER * global_logger;
extern CONFIG * global_config;
extern SERVER * global_server_lobby;
extern CIPHER * global_cipher;

// Counters and configurables.

extern char * IP_ADDRESS;
extern short LISTENING_PORT;

extern int CONNECTED_CLIENTS;

#endif
