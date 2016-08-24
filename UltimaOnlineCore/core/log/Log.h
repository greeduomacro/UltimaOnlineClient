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
#define LOG_INFO(...) core::log::Log::printInfo(__VA_ARGS__)
#define LOG_DEBUG(...) core::log::Log::printDebug(__VA_ARGS__)
#else
#define LOG_INFO(...)
#define LOG_DEBUG(...)
#endif
#define LOG_WARN(...) core::log::Log::printWarn(__VA_ARGS__)


#include <iostream>

namespace core {
    namespace log {
        class Log {
        public:
            static void printInfo(const char* format, ...);
            static void printDebug(const char* format, ...);
            static void printWarn(const char* format, ...);
            static void printPacket(bool isReceiving, const uint8_t* packetBuffer, uint16_t length);
        protected:
            static void writeLog(const char* format, va_list args);
        private:
            
        };
    }
}

#endif /* CORE_LOG_LOG_H */
