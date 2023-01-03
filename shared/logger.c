/*
	Generic logger implementation.
*/

#include "logger.h"

LOGGER * factory_create_logger() {
	return (struct LOGGER*)malloc(sizeof(LOGGER));
}

int log_info() {

}


int log_error() {

}


int log_warning() {

}

char * get_current_time_str() {

}

int set_logger() {

}

int get_logger() {

}
