//
//  NetworkAdapter.h
//  UltimaOnlineCore
//
//  Created by Hercules Junior on 8/4/16.
//  Copyright © 2016 Hercules Junior. All rights reserved.
//

#ifndef CORE_NETWORK_NETWORKADAPTER_H
#define CORE_NETWORK_NETWORKADAPTER_H

namespace core {
    namespace network {
        class NetworkAdapter {
        public:
            static NetworkAdapter* createNetworkAdapter();
            
//            virtual ~NetworkAdapter();
            
            virtual bool connect(const char* host, unsigned int port) = 0;
            virtual bool send(const unsigned char* bytes, unsigned int length) = 0;
        };
    }
}

#endif /* CORE_NETWORK_NETWORKADAPTER_H */
