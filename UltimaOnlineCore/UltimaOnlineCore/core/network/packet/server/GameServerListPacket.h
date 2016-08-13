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
                    GameServerListPacket(const unsigned char *packetBuffer);
                    ~GameServerListPacket();
                    
                    struct ServerEntry {
                        unsigned short index;
                        char name[32];
                        char full;
                        char timezone;
                        unsigned int address;
                    };
                    
                    typedef std::vector<GameServerListPacket::ServerEntry*> ServerEntryList;
                    
                    const ServerEntryList& getServerList();
                    
                    virtual ServerPacket* clone(const unsigned char *packetBuffer);
                    
                private:
                    ServerEntryList _serverList;
                    unsigned char _flag;
                };
            }
        }
    }
}

#endif /* CORE_NETWORK_PACKET_SERVER_GAMESERVERLISTPACKET_H */
