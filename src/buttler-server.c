#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include "enet/enet.h"
#include "miniaudio.h"
#include "ini.h"

void printHelp(void) {
    printf(
        "Buttler server component.\n"
        "Receive HW port I/O commands, output soundcard audio.\n"
        "\n"
        "Usage: buttserve -PARAM\n"
        "\n"
        "Flags:\n"
        "   -help: show this help.\n"
        "   -list: show audio input devices.\n"
        "   -host INIFILE: start a server from specified ini file.\n"
    );
}

bool enumPrintInputDevices() {
    #define ASSERTMA(X) if ((X) != MA_SUCCESS) {return false;}
    ma_context context;
    ma_device_info* pCaptureInfos;
    ma_uint32 captureCount;
    
    ASSERTMA(ma_context_init(NULL, 0, NULL, &context));
    ASSERTMA(ma_context_get_devices(&context, NULL, NULL, &pCaptureInfos, &captureCount));
    
    for (ma_uint32 i = 0; i < captureCount; i++) {
        printf("%d: %s\n", i, pCaptureInfos[i].name);
    }
    ma_context_uninit(&context);
    
    #undef ASSERTMA
}

typedef enum {
    RET_OK,
    RET_FAIL_PARAM,
    RET_FAIL_MINIAUDIO,
} RETURNCODE;
RETURNCODE main(int argc, char *argv[]) {
    #define FAILPRINTHELP() {printHelp(); return RET_FAIL_PARAM;}
    #define PARAM(NR, X) !strcmp(argv[NR], X)
    if (argc < 2) FAILPRINTHELP();
    
    if        (PARAM(1, "-help")) {
        printHelp();
        return RET_OK;
    } else if (PARAM(1, "-list")) {        
        if (!enumPrintInputDevices()) return RET_FAIL_MINIAUDIO;
    } else if (PARAM(1, "-host")) {
        if (argc < 3) FAILPRINTHELP();
        
        
        
    } else {
        FAILPRINTHELP();
    }
    
    #undef FAILPRINTHELP
    #undef PARAM
}

int enet_main() {
    if (enet_initialize () != 0) {
        printf("An error occurred while initializing ENet.\n");
        return 1;
    }

    ENetAddress address = {0};

    address.host = ENET_HOST_ANY; // Bind the server to the default localhost.
    address.port = 7777; // Bind the server to port 7777.

    #define MAX_CLIENTS 32

    // create a server
    ENetHost * server = enet_host_create(&address, MAX_CLIENTS, 2, 0, 0);

    if (server == NULL) {
        printf("An error occurred while trying to create an ENet server host.\n");
        return 1;
    }

    printf("Started a server...\n");

    ENetEvent event;

    // Wait up to 1000 milliseconds for an event. (WARNING: blocking)
    while (enet_host_service(server, &event, 1) >= 0) {
        switch (event.type) {
            case ENET_EVENT_TYPE_CONNECT:
                printf("A new client connected from %x:%u.\n",  event.peer->address.host, event.peer->address.port);
                // Store any relevant client information here.
                event.peer->data = "Client information";
                break;

            case ENET_EVENT_TYPE_RECEIVE:
                printf("A packet of length %lu containing %s was received from %s on channel %u.\n",
                        event.packet->dataLength,
                        event.packet->data,
                        event.peer->data,
                        event.channelID);
                // Clean up the packet now that we're done using it.
                enet_packet_destroy (event.packet);
                break;

            case ENET_EVENT_TYPE_DISCONNECT:
                printf("%s disconnected.\n", event.peer->data);
                // Reset the peer's client information.
                event.peer->data = NULL;
                break;

            /*case ENET_EVENT_TYPE_DISCONNECT_TIMEOUT:
                printf("%s disconnected due to timeout.\n", event.peer->data);
                // Reset the peer's client information.
                event.peer->data = NULL;
                break;*/

            case ENET_EVENT_TYPE_NONE:
                break;
        }
    }

    enet_host_destroy(server);
    enet_deinitialize();
    return 0;
}