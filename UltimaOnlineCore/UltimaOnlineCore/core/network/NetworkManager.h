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
            bool send(core::network::packet::Packet& packet);
            bool registerPacketHandler(HandlerQueue queue, unsigned char packetID, core::network::packet::IPacketHandler &packetHandler);
            
            NetworkManager(NetworkManager const&) = delete;
            void operator=(NetworkManager const&) = delete;
            
        private:
            NetworkManager();
            ~NetworkManager();
            
            NetworkAdapter *_adapter;
            
            typedef std::vector<core::network::packet::IPacketHandler*> PacketHandlerList;
            std::map<unsigned char, PacketHandlerList> _beforeSystemPacketHandlers;
            std::map<unsigned char, PacketHandlerList> _systemPacketHandlers;
            std::map<unsigned char, PacketHandlerList> _afterSystemPacketHandlers;

        };
    }
}

#endif /* CORE_NETWORK_NETWORKMANAGER_H */
