/*
	Generic logger implementation.
*/

#include "logger.h"

int init_logger(LOGGER * logger) {
	//open file if necessary.
}

LOGGER * factory_create_logger(int TYPE) {
	return (struct LOGGER*)malloc(sizeof(LOGGER));
}

int log_info(LOGGER * logger, char * message) {
	if (logger->ENABLED_LOGGING == 0) {

		if (logger->TYPE_OF_LOGGER == LOG.FILE) {
			//log to file
		} else if (logger->TYPE_OF_LOGGER == LOG.STDOUT) {
			//log to stdout
		} else {
			//log to stderr
		}
	}
}

int log_error(LOGGER * logger, char * message) {
	if (logger->ENABLED_LOGGING == 0) {
                if (logger->TYPE_OF_LOGGER == LOG.FILE) {
                        //log to file
                } else if (logger->TYPE_OF_LOGGER == LOG.STDOUT) {
                        //log to stdout
                } else {
                        //log to stderr
                }
        }
}

int log_warning(LOGGER * logger, char * message) {
	if (logger->ENABLED_LOGGING == 0) {
		if (logger->TYPE_OF_LOGGER == LOG.FILE) {
                        //log to file
                } else if (logger->TYPE_OF_LOGGER == LOG.STDOUT) {
                        //log to stdout
                } else {
                        //log to stderr
                }
        }
}

char * get_current_time_str() {
	//TODO.
}

void set_logger(LOGGER * newLogger) {
	global_logger = newLogger;
}

void set_log_path(LOGGER * logger, char * path) {
	logger->log_file_path = path;
}

LOGGER * get_logger() {
	return global_logger;
}

void enable_logger(LOGGER * logger) {
	logger->ENABLED_LOGGING = 0;
}

void disable_logger(LOGGER * logger) {
	logger->ENABLED_LOGGING = 1;
}

void terminate_logger(LOGGER * logger) {
	//close file, if necessary.
}
