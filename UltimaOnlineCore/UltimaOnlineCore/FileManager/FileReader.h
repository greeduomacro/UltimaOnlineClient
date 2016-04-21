//
//  FileReader.h
//  UltimaOnlineCore
//
//  Created by Hercules Junior on 4/10/16.
//  Copyright © 2016 Hercules Junior. All rights reserved.
//

#ifndef CORE_FILE_FileReader_h
#define CORE_FILE_FileReader_h
#include "Types.h"
#include "File.h"
#include <stack>
namespace core {
    namespace file {
        class FileReader
        {
        public:
            FileReader(const char* path);
            
            int8_t parseInt8();
            uint8_t parseUInt8();
            int16_t parseInt16();
            uint16_t parseUInt16();
            int32_t parseInt32();
            uint32_t parseUInt32();
            int64_t parseInt64();
            uint64_t parseUInt64();
            char* parseCStr();
            char* parseCStrOfSize(uint32_t length);
            char* parseByteArray(uint32_t numberOfBytes);
            float parseFloat();
            bool parseBool();
            
            // Overrides
            virtual ~FileReader();
            virtual void reset();
            virtual bool isEOF();
            virtual size_t read(void* buffer, size_t bufferSize);
            virtual size_t read(void* buffer, size_t start, size_t bufferSize);
            virtual size_t size();
            virtual void seek(size_t size, ESeekMode mode);
            virtual void seek(size_t size);
            virtual int peek();
            virtual void pushPosition();
            virtual void popPosition(bool seekToNewPosition=false);
        private:
            File* _file;
            
            long int _position;
            size_t _size;
            
            std::stack<long int> _positionStack;
        };
    }
}

#endif /* CORE_FILE_FileReader_h */
