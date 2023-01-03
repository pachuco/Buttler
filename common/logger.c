/*
	Generic logger implementation.
*/

#include "logger.h"

LOGGER * factory_create_logger(int TYPE) {
	return (struct LOGGER*)malloc(sizeof(LOGGER));
}

int log_info(char * message) {
	if (ENABLED_LOGGING == 0) {
		//log
		if (
	}
}


int log_error(char * message) {
	if (ENABLED_LOGGING == 0) {
                //log
        }
}


int log_warning(char * message) {
	if (ENABLED_LOGGING == 0) {
                //log
        }
}

char * get_current_time_str() {
	//TODO.
}

void set_logger(LOGGER * newLogger) {
	global_logger = newLogger;
}

LOGGER * get_logger() {
	return global_logger;
}

void enable_logger(LOGGER * logger) {
	ENABLED_LOGGING = 0;
}

void disable_logger(LOGGER * logger) {
	ENABLED_LOGGING = 1;
}
