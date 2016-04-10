//
//  FileManager.h
//  UltimaOnlineCore
//
//  Created by Hercules Junior on 4/9/16.
//  Copyright © 2016 Hercules Junior. All rights reserved.
//

#ifndef CORE_FILE_FileManager_h
#define CORE_FILE_FileManager_h

#include <string.h>
#include <map>
#include <vector>
#include "File.h"

namespace core {
    namespace file {
        
        struct cmp_str
        {
            bool operator()(const char *a, const char *b) const
            {
                return strcmp(a, b) < 0;
            }
        };
        
        class FileManager {
        public:
            static FileManager& getInstance();
            FileManager(FileManager const&)     = delete;
            void operator=(FileManager const&)  = delete;
            
            bool exists(const char* file) const;
            
            bool deleteAt(const char* path) const;
            
            bool isDirectory(const char* path) const;
            
            int listFiles(const char* path, std::vector<std::string>* files, bool recursively = false);
            
            File* open(const char* file, const char* mode);
            
            void close(File *file);
            
            bool createDirectory(const char* path, bool recursively=false) const;
            
        private:
            FileManager();
            ~FileManager();
            
            std::map<const char*,File*,cmp_str> *_openedFiles; // <const char*, File*> - path - file
        };
    }
}


#endif /* CORE_FILE_FileManager_h */
