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
                    ServerPacket(uint8_t packetID, uint16_t length);
                    ServerPacket(const uint8_t *packetBuffer);
                    virtual ~ServerPacket();

                    static ServerPacket* createPacket(const uint8_t *packetBuffer, uint16_t length);
                    virtual ServerPacket* clone(const uint8_t *packetBuffer) = 0;
                };
            }
        }
    }
}

#endif /* CORE_NETWORK_PACKET_PACKET_H */
