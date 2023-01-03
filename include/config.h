/*
	Simple .ini configuration utility in a textfile.
*/

#ifndef CONFIG_H
#define CONFIG_H

CONFIG * factory_create_config();

int open_config();
int set_config();

char * get_config_key(char * from_value);
char * get_config_value(char * from_key);

int close_config();
int spawn_default_config();

#endif
