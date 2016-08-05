//
//  NetworkAdapteriOS.h
//  UltimaOnlineCore
//
//  Created by Hercules Junior on 8/4/16.
//  Copyright © 2016 Hercules Junior. All rights reserved.
//

#ifndef CORE_PLATFORM_NETWORKADAPTERIOS_H
#define CORE_PLATFORM_NETWORKADAPTERIOS_H

#include "NetworkAdapter.h"

#import <Foundation/Foundation.h>

namespace core {
    namespace platforms {
        class NetworkAdapteriOS : public network::NetworkAdapter {
        public:
            NetworkAdapteriOS();
            virtual bool connect(const char* host, unsigned int port);
            virtual bool send(const unsigned char* bytes, unsigned int length);
            
        private:
            CFReadStreamRef _readStream;
            CFWriteStreamRef _writeStream;
        };
    }
}

#endif /* CORE_PLATFORM_NETWORKADAPTERIOS_H */
