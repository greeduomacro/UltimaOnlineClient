//
//  GameServerListPacket.h
//  UltimaOnlineCore
//
//  Created by Hercules Junior on 8/7/16.
//  Copyright © 2016 Hercules Junior. All rights reserved.
//

#ifndef CORE_NETWORK_PACKET_GAMESERVERLISTPACKET_H
#define CORE_NETWORK_PACKET_GAMESERVERLISTPACKET_H

#include "Packet.h"
#include <vector>

namespace core {
    namespace network {
        namespace packet {
            class GameServerListPacket : public Packet {
            public:
                
                GameServerListPacket(const unsigned char *packetBuffer);
                ~GameServerListPacket();
                
                struct ServerEntry {
                    unsigned short index;
                    char name[32];
                    char full;
                    char timezone;
                    unsigned int address;
                };
                
            private:
                std::vector<ServerEntry*> _serverList;
                unsigned char _flag;
            };
        }
    }
}

#endif /* CORE_NETWORK_PACKET_GAMESERVERLISTPACKET_H */
