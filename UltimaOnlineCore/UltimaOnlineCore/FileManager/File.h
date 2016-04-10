//
//  File.h
//  UltimaOnlineCore
//
//  Created by Hercules Junior on 4/9/16.
//  Copyright © 2016 Hercules Junior. All rights reserved.
//

#ifndef CORE_FILE_File_h
#define CORE_FILE_File_h

#include <stdio.h>
#include <string>

namespace core {
    namespace file{
        class File {
        public:
            File(FILE* file, const char* path, const char* openedMode);
            
            // Overrides
            virtual void retain();
            virtual void release();
            virtual unsigned int getTotalReferences();
            virtual const char* getPath();
            virtual char* getOpenedMode() const;
            virtual FILE* getFile();
            virtual ~File();
        private:
            FILE* _file;
            
            char *_openedMode;
            
            unsigned int _totalReferences;
            
            char *_path;
        };
    }
}


#endif /* CORE_FILE_File_h */
