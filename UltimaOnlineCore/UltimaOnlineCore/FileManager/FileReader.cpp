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
