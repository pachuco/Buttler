#include <stdio.h>
#include <stdlib.h>

#include "config.h"

int main()
{
    printf("Testing Config module...\n");

    CONFIG* my_config = factory_create_config();
    init_config(my_config, "cfg.ini", CONFIG_OVERWRITE);

    write_config(my_config, "LOGGER", "TRUE", 0);

    char value_out[4096]; //memset
    char key_out[4096]; //memset

    read_config_key(my_config, "LOGGER", value_out);
    read_config_value(my_config, "TRUE", key_out); //what if there's multiple entries with the same value? return first entry [for now] [return array later]

    //print out value_out and key_out

    close_config(my_config);

    return 0;
}
