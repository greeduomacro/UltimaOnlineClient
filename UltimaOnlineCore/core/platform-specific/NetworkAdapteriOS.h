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
            
            void setReadStreamOpened(bool isOpen);
            bool getReadStreamOpened();
            
            void setWriteStreamOpened(bool isOpen);
            bool getWriteStreamOpened();
            
        private:
            CFReadStreamRef _readStream;
            CFWriteStreamRef _writeStream;
            
            dispatch_queue_t networkQueue;
            
            
            bool _readStreamOpened;
            bool _writeStreamOpened;
        };
    }
}

#endif /* CORE_PLATFORM_NETWORKADAPTERIOS_H */
