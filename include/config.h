/*
	Simple .ini configuration utility in a textfile.
*/

#ifndef CONFIG_H
#define CONFIG_H

#include <stdio.h>
#include <stdlib.h>

typedef struct CONFIG CONFIG;

extern CONFIG* global_config;

extern const unsigned int CONFIG_OVERWRITE;

typedef struct CONFIG {
    int CONFIG_MODE;
    char * file_path;

    FILE* file_desc;
} CONFIG;

int init_config(CONFIG * config, char * file_path, int MODE);
int close_config(CONFIG * config);

CONFIG * factory_create_config();

int write_config(CONFIG * config, char * key, char * value, int append);

char * read_config_key(CONFIG * config, char * from_value, char * value_out);
char * read_config_value(CONFIG * config, char * from_key, char * key_out);

int spawn_default_config();

#endif
