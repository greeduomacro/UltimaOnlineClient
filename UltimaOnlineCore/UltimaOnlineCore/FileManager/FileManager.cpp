//
//  FileManager.cpp
//  UltimaOnlineCore
//
//  Created by Hercules Junior on 4/9/16.
//  Copyright © 2016 Hercules Junior. All rights reserved.
//

#include "FileManager.h"
#include <sys/stat.h>

using namespace std;

namespace core {
    namespace file {
        FileManager::FileManager() {
            _openedFiles = new std::map<const char*,File*,cmp_str>();
        }
        
        FileManager::~FileManager() {
            delete _openedFiles;
        }
        
        bool FileManager::exists(const char* file) const {
            bool exist;
            struct stat s;
            
            if (stat(file, &s) == 0) {
                exist = true;
            } else {
                exist = false;
            }
            return exist;
        }
        
        bool FileManager::deleteAt(const char* path) const {
            bool sucessOnDelete;
            
            if(remove(path) == 0) {
                sucessOnDelete = true;
            } else {
                sucessOnDelete = false;
            }
            
            return sucessOnDelete;
        }
        
        bool FileManager::isDirectory(const char* path) const {
            bool isDirectory = false;
            struct stat s;
            
            if (stat(path, &s) == 0 && S_ISDIR(s.st_mode)) {
                isDirectory = true;
            }
            return isDirectory;
        }
        
        File* FileManager::open(const char* file, const char* mode) {
            if (this->isDirectory(file)) {
                return NULL;
            }
            
            File* filePtr = (*_openedFiles)[file];
            
            if (filePtr == nullptr) {
                FILE *stdFile = fopen(file, mode);
                if(stdFile == NULL) {
                    return NULL;
                }
                
                filePtr = new File(stdFile, file, mode);
                (*_openedFiles)[file] = filePtr;
            }
            filePtr->retain();
            return filePtr;
        }
        
        void FileManager::close(File *file) {
            if (file == NULL) {
                return;
            }
            file->release();
            
            if(file->getTotalReferences() == 0){
                fclose(file->getFile());
                
                const char *fileKey = file->getPath();
                
                //Remove da tabela
                _openedFiles->erase(fileKey);
                
                delete file;
            }
        }
        
        bool FileManager::createDirectory(const char* path, bool recursively) const {
            if (!this->exists(path)) {
                int result = mkdir(path, ACCESSPERMS);
                if (result == -1)
                    return false;
            }
            return true;
        }
        
        FileManager& FileManager::getInstance() {
            static FileManager instance; // Guaranteed to be destroyed.
            // Instantiated on first use.
            return instance;
        }
    }
}