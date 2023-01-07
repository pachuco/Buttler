/*
	Configuration file implementation.
*/

#include "config.h"

const unsigned int CONFIG_OVERWRITE = 1;

int init_config(CONFIG * config, char * file_path, int MODE) {

    return 0;
}

int close_config(CONFIG * config) {
    //other pointers from struct

    free(config);

    return 0;
}

CONFIG * factory_create_config() {
    return (struct CONFIG*)malloc(sizeof(CONFIG));
}

int set_config(CONFIG * config, char * key, char * value, int append) {

    return 0;
}

char * get_config_key(CONFIG * config, char * from_value) {

    return NULL;
}

char * get_config_value(CONFIG * config, char * from_key) {

    return NULL;
}

int spawn_default_config() {
	//use a HEREDOC.

	return 0;
}
