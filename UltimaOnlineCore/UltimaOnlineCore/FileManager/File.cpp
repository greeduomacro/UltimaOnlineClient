//
//  File.cpp
//  UltimaOnlineCore
//
//  Created by Hercules Junior on 4/9/16.
//  Copyright © 2016 Hercules Junior. All rights reserved.
//

#include "File.h"

using namespace std;

namespace core {
    namespace file {
        File::~File(){
            delete _path;
            delete _openedMode;
        }
        
        File::File(FILE* file, const char* path, const char* openedMode) {
            _file = file;
            _totalReferences = 0;
            _openedMode = new char[strlen(openedMode)];
            strcpy(_openedMode, openedMode);
            _path = new char[strlen(path)];
            strcpy(_path, path);
        }
        
        void File::retain(){
            this->_totalReferences++;
        }
        
        void File::release(){
            this->_totalReferences--;
        }
        
        unsigned int File::getTotalReferences(){
            return this->_totalReferences;
        }
        
        const char* File::getPath(){
            return this->_path;
        }
        
        FILE* File::getFile(){
            return this->_file;
        }
        
        char* File::getOpenedMode() const{
            return _openedMode;
        }
    }
}
