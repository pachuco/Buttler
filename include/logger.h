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

LOGGER * factory_create_logger(int TYPE);

int log_info(char * message);
int log_error(char * message);
int log_warning(char * message);

char * get_current_time_str();

void set_logger(LOGGER * newLogger);
LOGGER * get_logger();

void enable_logger();
void disable_logger();

#endif
