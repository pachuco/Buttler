/*
	Generic logging facility.
*/

#ifndef LOGGER_H
#define LOGGER_H

// Structures:
// TODO.

// Signatures:

int factory_create_logger();

int log_info();
int log_error();
int log_warning();

char * get_current_time_str();

int set_logger();
int get_logger();

#endif
