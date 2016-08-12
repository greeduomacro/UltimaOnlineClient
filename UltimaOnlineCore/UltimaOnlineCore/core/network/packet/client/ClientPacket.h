//
//  ClientPacket.h
//  UltimaOnlineCore
//
//  Created by Hercules Junior on 8/3/16.
//  Copyright © 2016 Hercules Junior. All rights reserved.
//

#ifndef CORE_NETWORK_PACKET_CLIENT_CLIENTPACKET_H
#define CORE_NETWORK_PACKET_CLIENT_CLIENTPACKET_H

#include "Packet.h"

namespace core {
    namespace network {
        namespace packet {
            namespace client {
                class ClientPacket : public Packet {
                public:
                    ClientPacket(unsigned char packetID, unsigned short length);
                    ClientPacket(const unsigned char *packetBuffer);
                    virtual ~ClientPacket();
                    virtual void buildPacket() = 0;
                };
            }
        }
    }
}

#endif /* CORE_NETWORK_PACKET_PACKET_H */
