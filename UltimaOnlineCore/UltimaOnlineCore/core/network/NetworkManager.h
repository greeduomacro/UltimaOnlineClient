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

namespace core {
    namespace network {
        class NetworkManager {
        public:
            static NetworkManager& getInstance();
            
            bool connect(const char* host, int port);
            bool send(core::network::packet::Packet& packet);
            
            NetworkManager(NetworkManager const&) = delete;
            void operator=(NetworkManager const&) = delete;
            
        private:
            NetworkManager();
            ~NetworkManager();
        };
    }
}

#endif /* CORE_NETWORK_NETWORKMANAGER_H */
