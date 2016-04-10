//
//  Parser.cpp
//  UltimaOnlineCore
//
//  Created by Hercules Junior on 4/10/16.
//  Copyright © 2016 Hercules Junior. All rights reserved.
//

#include "Parser.h"

namespace core {
    namespace parser {
        Parser::Parser(core::file::FileReader &fileReader) : _fileReader(fileReader) {}
        
        core::file::FileReader& Parser::getFileReader() {
            return _fileReader;
        }
        
        int8_t Parser::parseInt8() {
            int8_t num;
            _fileReader.read(&num, sizeof(num));
            return num;
        }
        
        uint8_t Parser::parseUInt8() {
            uint8_t num;
            _fileReader.read(&num, sizeof(num));
            return num;
        }
        
        int16_t Parser::parseInt16() {
            int16_t num;
            _fileReader.read(&num, sizeof(num));
            return num;
        }
        
        uint16_t Parser::parseUInt16() {
            uint16_t num;
            _fileReader.read(&num, sizeof(num));
            return num;
        }
        
        int32_t Parser::parseInt32() {
            int32_t num;
            _fileReader.read(&num, sizeof(num));
            return num;
        }
        
        uint32_t Parser::parseUInt32() {
            uint32_t num;
            _fileReader.read(&num, sizeof(num));
            return num;
        }
        
        int64_t Parser::parseInt64() {
            int64_t num;
            _fileReader.read(&num, sizeof(num));
            return num;
        }
        
        uint64_t Parser::parseUInt64() {
            uint64_t num;
            _fileReader.read(&num, sizeof(num));
            return num;
        }
        
        char* Parser::parseCStr(uint32_t length) {
            char* buffer = new char[length + 1 * (sizeof(char))];
            if (length > 0) {
                size_t readBytes = _fileReader.read(buffer, length);
                buffer[readBytes] = '\0';
            }
            return buffer;
        }
        
        char* Parser::parseByteArray(uint32_t numberOfBytes) {
            char* buffer = new char[numberOfBytes];
            if (numberOfBytes > 0) {
                _fileReader.read(buffer, numberOfBytes);
            }
            return buffer;
        }
        
        float Parser::parseFloat() {
            float num;
            _fileReader.read(&num, sizeof(num));
            return num;
        }
        
        bool Parser::parseBool() {
            bool boolean;
            _fileReader.read(&boolean, sizeof(boolean));
            return boolean;
        }
    }
}