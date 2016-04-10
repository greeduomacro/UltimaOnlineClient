//
//  IndexAsset.cpp
//  UltimaOnlineCore
//
//  Created by Hercules Junior on 4/10/16.
//  Copyright © 2016 Hercules Junior. All rights reserved.
//

#include "IndexAsset.h"

namespace core {
    namespace asset {
        IndexAsset::IndexAsset(int32_t lookup, int32_t size) : _lookup(lookup), _size(size) {}
        
        int32_t IndexAsset::getLookup() { return _lookup; }
        int32_t IndexAsset::getSize() { return _size; }
        void IndexAsset::setLookup(int32_t lookup) { _lookup = lookup; }
        void IndexAsset::setSize(int32_t size) { _size = size; }
    }
}