
#define HEADER_SIZE                 0xAA
#define PAYLOAD_SIZE                0xAB
#define CRC_SIZE                    0xAC


#define CLIENT_CONNECT              0x01
#define CLIENT_PONG                 0x02
#define CLIENT_DETAILS              0x03
#define CLIENT_DISCONNECT           0x04
#define CLIENT_OPT_IN               0x05
#define CLIENT_OPT_OUT              0x06
#define CLIENT_FM_COMMAND           0x07


#define SERVER_DETAILS_ACK          0x08
#define SERVER_ACKNOWLEDGE          0x09
#define SERVER_PING                 0x0A
#define SERVER_DESTROY              0x0B
#define SERVER_OPT_RESPONSE         0x0C
#define SERVER_OPT_OWNERSHIP        0x0D
#define SERVER_LOBBY_BROADCAST      0x0E
#define SERVER_AUDIO_CHUNK          0x0F


#define CLIENT_RESERVED             0xFF
#define SERVER_RESERVED             0xFE
