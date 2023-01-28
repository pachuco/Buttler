/*
	Generic logger implementation.
*/

#include "logger.h"

const unsigned int LOGGER_FILE = 1;
const unsigned int LOGGER_STDOUT = 2;
const unsigned int LOGGER_STDERR = 3;

const unsigned int LOGGER_OVERWRITE = 4;

LOGGER *factory_create_logger()
{
	return (struct LOGGER *)malloc(sizeof(LOGGER));
}

int init_logger(LOGGER *logger, int TYPE, int MODE)
{
	logger->__ENABLED_LOGGING = -1;
	logger->__ENABLED_DEBUG_LOGGING = -1;
	logger->__TYPE_OF_LOGGER = TYPE;
	logger->__MODE_OF_LOGGING = MODE;

	logger->__log_file = NULL;
	logger->__log_file_path = NULL;

	// open file if necessary. [e.g if it's LOG.FILE - change path variable/member if necessary.

	return 0;
}

int cleanup_logger(LOGGER *logger)
{
	// close file, if necessary. [if logger type file]
	// other structural data pointers if allocated as well.

	free(logger);

	return 0;
}

int log_info(LOGGER *logger, char *message)
{
	if (logger->__ENABLED_LOGGING == 0)
	{

		time_t t = time(NULL);
		struct tm tm = *localtime(&t);

		if (logger->__TYPE_OF_LOGGER == LOGGER_FILE)
		{
			printf("%s\n", message); // to file
		}
		else if (logger->__TYPE_OF_LOGGER == LOGGER_STDOUT)
		{
			// to stdout
			printf("INFO: [[ %d-%02d-%02d %02d:%02d:%02d ]] - %s\n", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec, message);
		}
		else
		{
			printf("%s\n", message); // to stderr
		}
	}

	return 0;
}

int log_error(LOGGER *logger, char *message)
{
	if (logger->__ENABLED_LOGGING == 0)
	{

		time_t t = time(NULL);
		struct tm tm = *localtime(&t);

		if (logger->__TYPE_OF_LOGGER == LOGGER_FILE)
		{
			printf("%s\n", message); // to file
		}
		else if (logger->__TYPE_OF_LOGGER == LOGGER_STDOUT)
		{
			// to stdout
			printf("ERROR: [[ %d-%02d-%02d %02d:%02d:%02d ]] - %s\n", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec, message);
		}
		else
		{
			printf("%s\n", message); // to stderr
		}
	}

	return 0;
}

int log_warning(LOGGER *logger, char *message)
{
	if (logger->__ENABLED_LOGGING == 0)
	{

		time_t t = time(NULL);
		struct tm tm = *localtime(&t);

		if (logger->__TYPE_OF_LOGGER == LOGGER_FILE)
		{
			printf("%s\n", message); // to file
		}
		else if (logger->__TYPE_OF_LOGGER == LOGGER_STDOUT)
		{
			// to stdout
			printf("WARN: [[ %d-%02d-%02d %02d:%02d:%02d ]] - %s\n", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec, message);
		}
		else
		{
			printf("%s\n", message); // to stderr
		}
	}

	return 0;
}

int log_debug(LOGGER *logger, char *message)
{
	if (logger->__ENABLED_LOGGING == 0)
	{

		time_t t = time(NULL);
		struct tm tm = *localtime(&t);

		if (logger->__TYPE_OF_LOGGER == LOGGER_FILE)
		{
			printf("%s\n", message); // to file
		}
		else if (logger->__TYPE_OF_LOGGER == LOGGER_STDOUT && logger->__ENABLED_DEBUG_LOGGING == 0)
		{
			// to stdout, if DEBUG is enabled
			printf("DEBUG: [[ %d-%02d-%02d %02d:%02d:%02d ]] - %s\n", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec, message);
		}
		else
		{
			printf("%s\n", message); // to stderr
		}
	}

	return 0;
}

char *get_current_time_str()
{
	// TODO. move the logic that's already in log_debug, log_info, etc and structure it here.

	return NULL;
}

void set_log_path(LOGGER *logger, char *path)
{
	logger->__log_file_path = path;
}

void enable_logger(LOGGER *logger)
{
	logger->__ENABLED_LOGGING = 0;
}

void disable_logger(LOGGER *logger)
{
	logger->__ENABLED_LOGGING = 1;
}

void enable_debug_logging(LOGGER *logger)
{
	logger->__ENABLED_DEBUG_LOGGING = 0;
}

void disable_debug_logging(LOGGER *logger)
{
	logger->__ENABLED_DEBUG_LOGGING = 1;
}