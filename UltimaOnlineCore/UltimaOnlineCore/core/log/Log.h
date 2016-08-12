//
//  Log.h
//  UltimaOnlineCore
//
//  Created by Hercules Junior on 8/11/16.
//  Copyright © 2016 Hercules Junior. All rights reserved.
//

#ifndef CORE_LOG_LOG_H
#define CORE_LOG_LOG_H

#ifdef DEBUG
#define LOG_INFO(...) Log::printInfo(__VA_ARGS__)
#define LOG_DEBUG(...) Log::printDebug(__VA_ARGS__)
#else
#define LOG_INFO(...)
#define LOG_DEBUG(...)
#endif
#define LOG_WARN(...) Log::printWarn(__VA_ARGS__)


#include <iostream>

namespace core {
    namespace log {
        class Log {
        public:
            static void printInfo(char* format, ...);
            static void printDebug(char* format, ...);
            static void printWarn(char* format, ...);
            static void printPacket(bool isReceiving, const unsigned char* packetBuffer, unsigned short length);
        private:
        };
    }
}

#endif /* CORE_LOG_LOG_H */
