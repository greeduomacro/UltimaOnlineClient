//
//  IndexAsset.h
//  UltimaOnlineCore
//
//  Created by Hercules Junior on 4/10/16.
//  Copyright © 2016 Hercules Junior. All rights reserved.
//

#ifndef CORE_ASSET_IndexAsset_h
#define CORE_ASSET_IndexAsset_h

#include <inttypes.h>
#include "Asset.h"

namespace core {
    namespace asset {
        class IndexAsset: public Asset {
        public:
            IndexAsset();
            IndexAsset(int32_t lookup, int32_t size);
            int32_t getLookup();
            int32_t getSize();
            void setLookup(int32_t lookup);
            void setSize(int32_t size);
        private:
            int32_t _lookup;
            int32_t _size;
        };
    }
}

#endif /* CORE_ASSET_IndexAsset_h */
