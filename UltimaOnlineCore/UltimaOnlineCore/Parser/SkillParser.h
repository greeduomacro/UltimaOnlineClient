//
//  SkillParser.hpp
//  UltimaOnlineCore
//
//  Created by Hercules Junior on 4/10/16.
//  Copyright © 2016 Hercules Junior. All rights reserved.
//

#ifndef CORE_PARSER_SkillParser_hpp
#define CORE_PARSER_SkillParser_hpp

#include "Parser.h"
#include "SkillAsset.h"

namespace core {
    namespace parser {
        class SkillParser : public Parser {
        public:
            SkillParser(core::file::FileReader &fileReader);
            asset::SkillAsset* parse(uint32_t position, uint32_t nameLength);
        };
    }
}

#endif /* CORE_PARSER_SkillParser_h */
