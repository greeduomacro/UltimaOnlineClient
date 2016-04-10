//
//  Types.h
//  UltimaOnlineCore
//
//  Created by Hercules Junior on 4/10/16.
//  Copyright © 2016 Hercules Junior. All rights reserved.
//

#ifndef CORE_FILE_Types_h
#define CORE_FILE_Types_h

#define PATH_SEPARATOR "/"

namespace core {
    namespace file{
        enum ESeekMode {
            FILE_SEEK_BEGIN = 0,
            FILE_SEEK_CURRENT = 1,
            FILE_SEEK_END = 2
        };
    }
}

#endif /* CORE_FILE_Types_h */
