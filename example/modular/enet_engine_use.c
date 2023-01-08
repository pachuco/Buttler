#include <stdio.h>
#include <stdlib.h>

#include "enet_engine.h"

int callback_on_connected_client() {

}

int callback_on_receive_data() {

}

int callback_on_disconnected_client() {

}

int main()
{
    printf("Testing ENET_Engine module...\n");

    //this is an internal object to the SERVER module. do not use directly.

    ENET_ENGINE* my_engine = create_enet_engine();
    enet_init(my_engine, "0.0.0.0", 2345);

    enet_start_engine(my_engine);

    enet_manage_hosts(my_engine, &callback_on_connected_client,
        &callback_on_receive_data, &callback_on_disconnected_client);

    return 0;
}
