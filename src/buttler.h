#include <stdint.h>

typedef struct {
    uint8_t portOff;
    uint8_t data;
} PortDataPair;







enum PAKCET_TYPE {
    PKT_CONNECT,
    PKT_DISCONNECT,
    PKT_WRITE,
    PKT_READ,
    PKT_READ_REPLY,
    PKT_WAIT,
    PKT_PING,
    PKT_PING_REPLY,
};

typedef struct {
    uint8_t type;
} PacketUnknown;

typedef struct {
    uint8_t      type;
    uint16_t     numPairs;
    uint16_t     portBase;
    PortDataPair pairs[0];
} PacketWrite;

typedef struct {
    uint8_t  type;
    uint16_t portBase;
    uint8_t  portOffStart;
    uint8_t  portOffEnd;
} PacketRead;

typedef PacketWrite PacketReadReply;

typedef struct {
    uint8_t  type;
    uint16_t pingId;
} PacketPing;

typedef PacketPing PacketPingReply;