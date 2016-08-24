//
//  NetworkManager.h
//  UltimaOnlineCore
//
//  Created by Hercules Junior on 8/3/16.
//  Copyright © 2016 Hercules Junior. All rights reserved.
//

#ifndef CORE_NETWORK_NETWORKMANAGER_H
#define CORE_NETWORK_NETWORKMANAGER_H

#include "packet/Packet.h"
#include "NetworkAdapter.h"
#include <map>
#include <vector>
#include "packet/PacketHandler.h"
#include "packet/client/ClientPacket.h"

namespace core {
    namespace network {
        class NetworkManager {
        public:
            enum HandlerQueue {
                AfterSystem = 0, /* DEFAULT */
                System = 1,
                BeforeSystem = 2,
            };
            static NetworkManager& getInstance();
            
            bool connect(const char* host, int port);
            bool send(core::network::packet::client::ClientPacket& packet);
            bool registerPacketHandler(HandlerQueue queue, uint8_t packetID, core::network::packet::IPacketHandler &packetHandler);
            
            void processPacket(const uint8_t *buf, uint16_t len);
            
            NetworkManager(NetworkManager const&) = delete;
            void operator=(NetworkManager const&) = delete;
            
        private:
            NetworkManager();
            ~NetworkManager();
            
            NetworkAdapter *_adapter;
            
            std::map<uint8_t, packet::PacketHandlerList> _beforeSystemPacketHandlers;
            std::map<uint8_t, packet::PacketHandlerList> _systemPacketHandlers;
            std::map<uint8_t, packet::PacketHandlerList> _afterSystemPacketHandlers;

        };
    }
}

#endif /* CORE_NETWORK_NETWORKMANAGER_H */
