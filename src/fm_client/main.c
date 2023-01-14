#include <stdio.h>
#include <stdlib.h>

#include "client.h"

int on_client_opt_out() {
    return 0;
}

int on_client_opt_in() {
    return 0;
}

int on_client_details() {
    return 0;
}

int on_client_fm_command() {
    return 0;
}

int on_client_join_lobby() {
    return 0;
}

int on_client_ready_stream() {
    return 0;
}

// ====================================================================

void set_callback_events() {

    //bind_protocol_event(on_client_join_lobby, CLIENT_CONNECT);
    //bind_protocol_event(on_client_details, CLIENT_DETAILS);

    //bind_protocol_event(on_client_opt_in, CLIENT_OPT_IN);
    //bind_protocol_event(on_client_opt_out, CLIENT_OPT_OUT);

    //bind_protocol_event(on_client_fm_command, CLIENT_FM_COMMAND);

    //bind_protocol_event(on_client_ready_stream, CLIENT_READY_STREAM);
}

int main(int argc, char ** argv)
{

    CLIENT* host_client = factory_create_client();
    init_client(host_client, "127.0.0.1", 2345);

    //set_callback_events();

    host_connect_client(host_client);

    return 0;
}
