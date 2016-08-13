//
//  ConnectToGameServerPacket.h
//  UltimaOnlineCore
//
//  Created by Hercules Junior on 8/7/16.
//  Copyright © 2016 Hercules Junior. All rights reserved.
//

#ifndef CORE_NETWORK_PACKET_SERVER_CONNECTTOGAMESERVERPACKET_H
#define CORE_NETWORK_PACKET_SERVER_CONNECTTOGAMESERVERPACKET_H

#include "ServerPacket.h"

namespace core {
    namespace network {
        namespace packet {
            namespace server {
                class ConnectToGameServerPacket : public ServerPacket {
                public:
                    
                    ConnectToGameServerPacket();
                    ConnectToGameServerPacket(const uint8_t *packetBuffer);
                    ~ConnectToGameServerPacket();
                    
                    virtual ServerPacket* clone(const uint8_t *packetBuffer);
                    
                    const char* getGameServerIP();
                    unsigned short getGameServerPort();
                    unsigned int getGameServerKey();
                    
                private:
                    char *_gameServerIP;
                    unsigned short _gameServerPort;
                    unsigned int _gameServerKey;
                };
            }
        }
    }
}

#endif /* CORE_NETWORK_PACKET_SERVER_CONNECTTOGAMESERVERPACKET_H */
