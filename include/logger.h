/*
	Generic logging facility.
*/

#ifndef LOGGER_H
#define LOGGER_H

#include <stdio.h>
#include <stdlib.h>

// Structures:

extern const unsigned int LOGGER_FILE;
extern const unsigned int LOGGER_STDOUT;
extern const unsigned int LOGGER_STDERR;

extern const unsigned int LOGGER_OVERWRITE;

typedef struct LOGGER {
	int __ENABLED_LOGGING;
	int __TYPE_OF_LOGGER;
	int __MODE_OF_LOGGING;

	FILE * __log_file;
	char * __log_file_path;
} LOGGER;

// Signatures:

int init_logger(LOGGER * logger, int TYPE, int MODE);
int cleanup_logger(LOGGER * logger);

LOGGER * factory_create_logger();

int log_info(LOGGER * logger, char * message);
int log_error(LOGGER * logger, char * message);
int log_warning(LOGGER * logger, char * message);

char * get_current_time_str();

void set_logger(LOGGER * newLogger);
void set_log_path(LOGGER * logger, char * path);

void enable_logger(LOGGER * logger);
void disable_logger(LOGGER * logger);

#endif
