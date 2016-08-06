//
//  NetworkAdapter.h
//  UltimaOnlineCore
//
//  Created by Hercules Junior on 8/4/16.
//  Copyright © 2016 Hercules Junior. All rights reserved.
//

#ifndef CORE_NETWORK_NETWORKADAPTER_H
#define CORE_NETWORK_NETWORKADAPTER_H

#include "UOHuffman.h"
#include <thread>
#include <mutex>
#include <condition_variable>

#define NETWORK_BUFSIZE 1000

namespace core {
    namespace network {
        class NetworkAdapter {
        public:
            static NetworkAdapter* getInstance();
            
            static void logPacket(const unsigned char *pBuffer, unsigned int length);
            void parsePacket(unsigned char *buf, unsigned int length);
            
            void clean();
            
//            virtual ~NetworkAdapter();
            
            virtual bool connect(const char* host, unsigned int port) = 0;
            virtual bool send(const unsigned char* bytes, unsigned int length) = 0;
            bool _connected;
        protected:
            NetworkAdapter();
            std::mutex mtx;             // mutex for critical section
            std::condition_variable cv;
            
        private:
            HuffmanObj _huffObj;
        };
    }
}

#endif /* CORE_NETWORK_NETWORKADAPTER_H */
