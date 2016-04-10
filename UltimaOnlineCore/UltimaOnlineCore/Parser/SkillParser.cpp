//
//  SkillParser.cpp
//  UltimaOnlineCore
//
//  Created by Hercules Junior on 4/10/16.
//  Copyright © 2016 Hercules Junior. All rights reserved.
//

#include "SkillParser.h"

namespace core {
    namespace parser {
        SkillParser::SkillParser(core::file::FileReader &fileReader) : Parser(fileReader) {}
        
        asset::SkillAsset* SkillParser::parse(uint32_t position, uint32_t nameLength) {
            this->getFileReader().seek(position, core::file::FILE_SEEK_BEGIN);
            if (this->getFileReader().isEOF())
                return nullptr;
            bool isAction = this->parseBool();
            char* skillName = this->parseCStr(nameLength);
            asset::SkillAsset *skill = new asset::SkillAsset(isAction, skillName);
            delete skillName;
            return skill;
        }
    }
}