//
//  ArtParser.h
//  UltimaOnlineCore
//
//  Created by Hercules Junior on 4/10/16.
//  Copyright © 2016 Hercules Junior. All rights reserved.
//

#ifndef CORE_PARSER_ArtParser_h
#define CORE_PARSER_ArtParser_h

#include <stdio.h>
#include "Parser.h"

namespace core {
    namespace parser {
        class ArtPaser : public Parser {
        public:
            ArtPaser(core::file::FileReader& fileReader);
        };
    }
}

#endif /* CORE_PARSER_ArtParser_h */
