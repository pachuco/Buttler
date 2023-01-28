#include <stdio.h>
#include <stdlib.h>

#include "client.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Project Header files.
#include "logger.h"
#include "config.h"
#include "thread.h"
#include "cipher.h"
#include "client.h"

#include "globals.h"

const int MINIMUM_ARGS = 2;

//////////////////////////////////////////////////////////////////////

LOGGER * global_logger = NULL;
CONFIG * global_config = NULL;
CLIENT * global_client = NULL;
CIPHER * global_cipher = NULL;

// Counters and configurables.

char * IP_ADDRESS = NULL;
short CONNECTING_PORT = 2345;

//////////////////////////////////////////////////////////////////////

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

    global_client = factory_create_client();
    init_client(global_client, "127.0.0.1", CONNECTING_PORT);

    //set_callback_events();

    host_connect_client(global_client);

    getchar();

    return 0;
}
