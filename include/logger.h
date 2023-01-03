/*
	Generic logging facility.
*/

#ifndef LOGGER_H
#define LOGGER_H

// Structures:

enum LOG = { FILE = 1, STDOUT = 2, STDERR = 3 };

typedef struct LOGGER {
	int ENABLED_LOGGING = -1;
	int TYPE_OF_LOGGER = -1;

	FILE * log_file = NULL;
	char *log_file_path = NULL;
} LOGGER;

// Signatures:

int init_logger(LOGGER * logger);

LOGGER * factory_create_logger(int TYPE);

int log_info(LOGGER * logger, char * message);
int log_error(LOGGER * logger, char * message);
int log_warning(LOGGER * logger, char * message);

char * get_current_time_str();

void set_logger(LOGGER * newLogger);
LOGGER * get_logger();

void enable_logger(LOGGER * logger);
void disable_logger(LOGGER * logger);

void terminate_logger(LOGGER * logger);

#endif
