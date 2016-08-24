//
//  IPacketHandler.h
//  UltimaOnlineCore
//
//  Created by Hercules Junior on 8/9/16.
//  Copyright © 2016 Hercules Junior. All rights reserved.
//

#ifndef CORE_NETWORK_PACKET_IPACKETHANDLER_H
#define CORE_NETWORK_PACKET_IPACKETHANDLER_H

#include <vector>

namespace core {
    namespace network {
        namespace packet {
            class IPacketHandler;
            typedef std::vector<IPacketHandler*> PacketHandlerList;
            class IPacketHandler {
            public:
                virtual bool handlePacket(core::network::packet::server::ServerPacket &packet) = 0;
                virtual bool deregisterHandler() = 0;
                virtual void setHandlerRegisterList(PacketHandlerList &registerList) = 0;
            };
        }
    }
}

#endif /* CORE_NETWORK_PACKET_IPACKETHANDLER_H */
