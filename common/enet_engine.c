/*
    Enet engine implementation.
*/

#include "enet_engine.h"

const unsigned int ENGINE_TYPE_SERVER = 10;
const unsigned int ENGINE_TYPE_CLIENT = 11;

const unsigned int CONN_STATE_CONNECTED = 1;
const unsigned int CONN_STATE_DISCONNECTED = 2;
const unsigned int CONN_STATE_UNRESPONSIVE = 3;
const unsigned int CONN_STATE_POLLED = 4;

ENET_ENGINE *create_enet_engine()
{
    return (ENET_ENGINE *)malloc(sizeof(ENET_ENGINE));
}

int enet_init(ENET_ENGINE *engine, char *ip_address, short port)
{

    log_info(global_logger, "[ENET Engine] Initialization...");

    engine->ip_addr = ip_address;
    engine->port = port;

    char log_msg_ip[1024] = {0};
    char log_msg_port[1024] = {0};

    snprintf(log_msg_ip, sizeof(log_msg_ip), "[ENET Engine] Configured to IP: %s...", ip_address);
    snprintf(log_msg_port, sizeof(log_msg_port), "[ENET Engine] Configured to Port: %d", port);

    log_info(global_logger, log_msg_ip);
    log_info(global_logger, log_msg_port);

    // initialize other structs...

    if (enet_initialize() != 0)
    {
        fprintf(stderr, "An error occurred while initializing ENet.\n");
        atexit(enet_deinitialize);

        return EXIT_FAILURE;
    }

    return 0;
}

int enet_cleanup(ENET_ENGINE *engine)
{
    enet_host_destroy(engine->host_socket);

    atexit(enet_deinitialize);

    return 0;
}

int enet_start_engine(ENET_ENGINE *engine, int ENGINE_TYPE)
{
    engine->ENGINE_TYPE = ENGINE_TYPE;

    log_info(global_logger, "[ENET Engine New Thread] Starting engine...");

    if (engine->ENGINE_TYPE == ENGINE_TYPE_SERVER)
    {

        log_info(global_logger, "[ENET Engine New Thread] Type of engine: SERVER.");

        if (strcmp(engine->ip_addr, "0.0.0.0") == 0)
        {
            engine->host_addr.host = ENET_HOST_ANY;
            engine->host_addr.port = engine->port;

            log_info(global_logger, "[ENET Engine New Thread] Binding to ENET_HOST_ANY - 0.0.0.0 ...");
        }
        else
        {
            log_info(global_logger, "[ENET Engine New Thread] Binding to specified IP...");
            enet_address_set_host(&engine->host_addr, engine->ip_addr);
        }

        engine->host_socket = enet_host_create(&engine->host_addr, 32, 2, 0, 0);
        // engine->client_socket = enet_host_create(NULL, 1, 2, 0, 0);
    }
    else if (ENGINE_TYPE == ENGINE_TYPE_CLIENT)
    {

        log_info(global_logger, "[ENET Engine New Thread] Type of engine: CLIENT.");

        enet_address_set_host(&engine->host_addr, engine->ip_addr);
    }
    else
    {
        //... unknown engine type.
    }

    return 0;
}

int enet_manage_hosts(ENET_ENGINE *engine, int (*on_connected_callback)(void *),
                      int (*on_received_callback)(void *), int (*on_disconnected_callback)(void *))
{

    log_info(global_logger, "[ENET Engine New Thread] Managing hosts loop...");
    log_info(global_logger, "------------------------------------------------");

    while (enet_host_service(engine->host_socket, &engine->host_event, 1000) >= 0)
    {
        switch (engine->host_event.type) //.type?...
        {
        case ENET_EVENT_TYPE_NONE:
            // do nothing.
            log_info(global_logger, "[Enet Engine] Event NONE. All is fine.");
            break;

        case ENET_EVENT_TYPE_CONNECT:

            log_info(global_logger, "[ENET Engine] A client connected...");

            enet_on_connect(engine, engine->host_event, on_connected_callback);
            break;

        case ENET_EVENT_TYPE_RECEIVE:

            log_info(global_logger, "[ENET Engine] Some data was received...");

            enet_on_receive(engine, engine->host_event, on_received_callback);
            break;

        case ENET_EVENT_TYPE_DISCONNECT:

            log_info(global_logger, "[ENET Engine] A client disconnected...");

            enet_on_disconnect(engine, engine->host_event, on_disconnected_callback);
            break;
        }
    }

    log_info(global_logger, "[ENET Engine New Thread] ** Host management loop exited...");
    log_info(global_logger, "[ENET Engine New Thread] ** Shutting down or an error occured...");

    return 0;
}

int enet_destruct()
{

    // free other structs.

    return 0;
}

// Propagators //////////////////////////

int enet_on_connect(ENET_ENGINE *engine, ENetEvent event, int (*on_connected_callback)(void *))
{

    //low level logic, decrypting, etc.

    //pass data directly to server to handle protocol


    on_connected_callback(engine, event);

    return 0;
}

int enet_on_receive(ENET_ENGINE *engine, ENetEvent event, int (*on_received_callback)(void *))
{
    //low level logic, decrypting, etc.

    //pass data directly to server to handle protocol

    on_received_callback(engine, event);

    return 0;
}

int enet_on_disconnect(ENET_ENGINE *engine, ENetEvent event, int (*on_disconnected_callback)(void *))
{
    //low level logic, decrypting, etc.

    //pass data directly to server to handle protocol

    on_disconnected_callback(engine, event);

    return 0;
}

// int enet_create_packet() {

//}
