//
//  SelectServerPacket.h
//  UltimaOnlineCore
//
//  Created by Hercules Junior on 8/3/16.
//  Copyright © 2016 Hercules Junior. All rights reserved.
//

#ifndef CORE_NETWORK_PACKET_CLIENT_SELECTSERVERPACKET_H
#define CORE_NETWORK_PACKET_CLIENT_SELECTSERVERPACKET_H

#include "ClientPacket.h"

namespace core {
    namespace network {
        namespace packet {
            namespace client {
                class SelectServerPacket : public ClientPacket {
                public:
                    SelectServerPacket(short choice);
                    ~SelectServerPacket();
                    
                    virtual void buildPacket();
                    
                private:
                    short _choice;
                };
            }
        }
    }
}

#endif /* CORE_NETWORK_PACKET_CLIENT_SELECTSERVERPACKET_H */
