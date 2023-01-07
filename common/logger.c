/*
	Generic logger implementation.
*/

#include "logger.h"

const unsigned int LOGGER_FILE = 1;
const unsigned int LOGGER_STDOUT = 2;
const unsigned int LOGGER_STDERR = 3;

int init_logger(LOGGER * logger) {
    logger->__ENABLED_LOGGING = -1;
	logger->__TYPE_OF_LOGGER = -1;

	logger->__log_file = NULL;
	logger->__log_file_path = NULL;

	//open file if necessary. [e.g if it's LOG.FILE

	return 0;
}

void cleanup_logger(LOGGER * logger) {
    //close file, if necessary. [if logger type file]
    //other structural data pointers if allocated as well.

    free(logger);
}

LOGGER * factory_create_logger(int TYPE) {
	return (struct LOGGER*)malloc(sizeof(LOGGER));
}

int log_info(LOGGER * logger, char * message) {
	if (logger->__ENABLED_LOGGING == 0) {

		if (logger->__TYPE_OF_LOGGER == LOGGER_FILE) {
			printf("to_file");
		} else if (logger->__TYPE_OF_LOGGER == LOGGER_STDOUT) {
			printf("to_stdout");
		} else {
			printf("to_stderr");
		}
	}

	return 0;
}

int log_error(LOGGER * logger, char * message) {
	if (logger->__ENABLED_LOGGING == 0) {

        if (logger->__TYPE_OF_LOGGER == LOGGER_FILE) {
            printf("to_file");
        } else if (logger->__TYPE_OF_LOGGER == LOGGER_STDOUT) {
            printf("to_stdout");
        } else {
            printf("to_stderr");
        }
    }

    return 0;
}

int log_warning(LOGGER * logger, char * message) {
	if (logger->__ENABLED_LOGGING == 0) {

		if (logger->__TYPE_OF_LOGGER == LOGGER_FILE) {
            printf("to_file");
        } else if (logger->__TYPE_OF_LOGGER == LOGGER_STDOUT) {
            printf("to_stdout");
        } else {
            printf("to_stderr");
        }
    }

    return 0;
}

char * get_current_time_str() {
	//TODO.

	return NULL;
}

void set_log_path(LOGGER * logger, char * path) {
	logger->__log_file_path = path;
}

void enable_logger(LOGGER * logger) {
	logger->__ENABLED_LOGGING = 0;
}

void disable_logger(LOGGER * logger) {
	logger->__ENABLED_LOGGING = 1;
}
