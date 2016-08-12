//
//  ServerPacket.h
//  UltimaOnlineCore
//
//  Created by Hercules Junior on 8/3/16.
//  Copyright © 2016 Hercules Junior. All rights reserved.
//

#ifndef CORE_NETWORK_PACKET_SERVER_SERVERPACKET_H
#define CORE_NETWORK_PACKET_SERVER_SERVERPACKET_H

#include "Packet.h"

namespace core {
    namespace network {
        namespace packet {
            namespace server {
                class ServerPacket : public Packet {
                public:
                    ServerPacket(unsigned char packetID, unsigned short length);
                    ServerPacket(const unsigned char *packetBuffer);
                    virtual ~ServerPacket();

                    static ServerPacket* createPacket(const unsigned char *packetBuffer, unsigned short length);
                    virtual ServerPacket* clone(const unsigned char *packetBuffer) = 0;
                };
            }
        }
    }
}

#endif /* CORE_NETWORK_PACKET_PACKET_H */
