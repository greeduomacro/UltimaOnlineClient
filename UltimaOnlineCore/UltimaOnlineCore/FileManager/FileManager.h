//
//  FileManager.h
//  UltimaOnlineCore
//
//  Created by Hercules Junior on 4/9/16.
//  Copyright © 2016 Hercules Junior. All rights reserved.
//

#ifndef FileManager_h
#define FileManager_h

#define PATH_SEPARATOR '/'

#include <string.h>
#include <map>

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


#endif /* FileManager_h */
