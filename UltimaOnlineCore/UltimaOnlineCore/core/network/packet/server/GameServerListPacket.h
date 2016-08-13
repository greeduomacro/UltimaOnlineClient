//
//  GameServerListPacket.h
//  UltimaOnlineCore
//
//  Created by Hercules Junior on 8/7/16.
//  Copyright © 2016 Hercules Junior. All rights reserved.
//

#ifndef CORE_NETWORK_PACKET_SERVER_GAMESERVERLISTPACKET_H
#define CORE_NETWORK_PACKET_SERVER_GAMESERVERLISTPACKET_H

#include "ServerPacket.h"
#include <vector>

namespace core {
    namespace network {
        namespace packet {
            namespace server {
                class GameServerListPacket : public ServerPacket {
                public:
                    GameServerListPacket();
                    GameServerListPacket(const uint8_t *packetBuffer);
                    ~GameServerListPacket();
                    
                    struct ServerEntry {
                        uint16_t index;
                        char name[32];
                        uint8_t full;
                        uint8_t timezone;
                        uint32_t address;
                    };
                    
                    typedef std::vector<GameServerListPacket::ServerEntry*> ServerEntryList;
                    
                    const ServerEntryList& getServerList();
                    
                    virtual ServerPacket* clone(const uint8_t *packetBuffer);
                    
                private:
                    ServerEntryList _serverList;
                    uint8_t _flag;
                };
            }
        }
    }
}

#endif /* CORE_NETWORK_PACKET_SERVER_GAMESERVERLISTPACKET_H */
