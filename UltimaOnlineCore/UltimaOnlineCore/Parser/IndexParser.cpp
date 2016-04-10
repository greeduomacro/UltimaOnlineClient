//
//  IndexParser.cpp
//  UltimaOnlineCore
//
//  Created by Hercules Junior on 4/10/16.
//  Copyright © 2016 Hercules Junior. All rights reserved.
//

#include "IndexParser.h"

namespace core {
    namespace parser {
        IndexParser::IndexParser(core::file::FileReader &fileReader) : Parser(fileReader) {}
        
        asset::IndexAsset* IndexParser::parse() {
            if (this->getFileReader().isEOF())
                return nullptr;
            int32_t lookup = this->parseInt32();
            if (lookup < 0) { //Invalid, skip!
                this->parseInt32();
                this->parseInt32();
                return this->parse();
            }
            int32_t size = this->parseInt32();
            this->parseInt32(); //Not used
            return new asset::IndexAsset(lookup, size);
        }
    }
}