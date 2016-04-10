//
//  IndexParser.h
//  UltimaOnlineCore
//
//  Created by Hercules Junior on 4/10/16.
//  Copyright © 2016 Hercules Junior. All rights reserved.
//

#ifndef CORE_PARSER_IndexParser_h
#define CORE_PARSER_IndexParser_h

#include "Parser.h"
#include "IndexAsset.h"

namespace core {
    namespace parser {
        class IndexParser : public Parser {
        public:
            IndexParser(core::file::FileReader &fileReader);
            asset::IndexAsset* parse();
        };
    }
}

#endif /* CORE_PARSER_IndexParser_h */
