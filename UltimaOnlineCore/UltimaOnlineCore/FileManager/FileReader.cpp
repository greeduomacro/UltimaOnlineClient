//
//  FileReader.cpp
//  UltimaOnlineCore
//
//  Created by Hercules Junior on 4/10/16.
//  Copyright © 2016 Hercules Junior. All rights reserved.
//

#include "FileReader.h"
#include "FileManager.h"

namespace core {
    namespace file {
        
        FileReader::FileReader(const char* path) {
            _file = FileManager::getInstance().open(path, "rb");
            _position = 0;
            
            fseek(_file->getFile(), 0, SEEK_END);
            _size = ftell(_file->getFile());
            fseek(_file->getFile(), _position, SEEK_SET);
        }
        
        FileReader::~FileReader() {
            FileManager::getInstance().close(_file);
        }
        
        int8_t FileReader::parseInt8() {
            int8_t num;
            this->read(&num, sizeof(num));
            return num;
        }
        
        uint8_t FileReader::parseUInt8() {
            uint8_t num;
            this->read(&num, sizeof(num));
            return num;
        }
        
        int16_t FileReader::parseInt16() {
            int16_t num;
            this->read(&num, sizeof(num));
            return num;
        }
        
        uint16_t FileReader::parseUInt16() {
            uint16_t num;
            this->read(&num, sizeof(num));
            return num;
        }
        
        int32_t FileReader::parseInt32() {
            int32_t num;
            this->read(&num, sizeof(num));
            return num;
        }
        
        uint32_t FileReader::parseUInt32() {
            uint32_t num;
            this->read(&num, sizeof(num));
            return num;
        }
        
        int64_t FileReader::parseInt64() {
            int64_t num;
            this->read(&num, sizeof(num));
            return num;
        }
        
        uint64_t FileReader::parseUInt64() {
            uint64_t num;
            this->read(&num, sizeof(num));
            return num;
        }
        
        char* FileReader::parseCStr() {
            pushPosition();
            int length = 0;
            while (fgetc(_file->getFile()) != '\0') {
                ++length;
            }
            popPosition(true);
            char* buffer = new char[length + 1 * (sizeof(char))];
            if (length > 0) {
                size_t readBytes = this->read(buffer, length);
                buffer[readBytes] = '\0';
            }
            return buffer;
        }
        
        char* FileReader::parseCStrOfSize(uint32_t length) {
            char* buffer = new char[length + 1 * (sizeof(char))];
            if (length > 0) {
                size_t readBytes = this->read(buffer, length);
                buffer[readBytes] = '\0';
            }
            return buffer;
        }
        
        char* FileReader::parseByteArray(uint32_t numberOfBytes) {
            char* buffer = new char[numberOfBytes];
            if (numberOfBytes > 0) {
                this->read(buffer, numberOfBytes);
            }
            return buffer;
        }
        
        float FileReader::parseFloat() {
            float num;
            this->read(&num, sizeof(num));
            return num;
        }
        
        bool FileReader::parseBool() {
            bool boolean;
            this->read(&boolean, sizeof(boolean));
            return boolean;
        }

        
        void FileReader::reset() {
            _position = 0;
            rewind(_file->getFile());
        }
        
        bool FileReader::isEOF() {
            return _position >= (long) size();
        }
        
        size_t FileReader::read(void* buffer, size_t bufferSize) {
            if (buffer != nullptr) {
                size_t read = fread(buffer, 1, bufferSize, _file->getFile());
                _position = ftell(_file->getFile());
                
                return read;
            } else {
                return 0;
            }
        }
        
        size_t FileReader::read(void* buffer, size_t start, size_t bufferSize) {
            fseek(_file->getFile(), start, SEEK_SET);
            size_t read = fread(buffer, 1, bufferSize, _file->getFile());
            _position = ftell(_file->getFile());
            return read;
        }
        
        size_t FileReader::size() {
            return _size;
        }
        
        void FileReader::seek(size_t size, ESeekMode mode){
            int seekMode = SEEK_SET;
            
            if(mode == FILE_SEEK_CURRENT){
                seekMode = SEEK_CUR;
            }else if(mode == FILE_SEEK_BEGIN){
                seekMode = SEEK_SET;
            }else if (mode == FILE_SEEK_END){
                seekMode = SEEK_END;
            }
            fseek(_file->getFile(), size, seekMode);
            
            _position = ftell(_file->getFile());
        }
        
        void FileReader::seek(size_t size) {
            fseek(_file->getFile(), size, SEEK_CUR);
            _position = ftell(_file->getFile());
        }
        
        int FileReader::peek(){
            pushPosition();
            int character = fgetc(_file->getFile());
            
            popPosition(true);
            
            return character;
        }
        
        void FileReader::pushPosition(){
            _positionStack.push(_position);
        }
        
        void FileReader::popPosition(bool seekToNewPosition){
            _position = _positionStack.top();
            _positionStack.pop();
            
            if(seekToNewPosition){
                this->seek(_position, FILE_SEEK_BEGIN);
            }
        }
    }
}
