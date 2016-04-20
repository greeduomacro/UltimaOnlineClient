//
//  SkillAsset.cpp
//  UltimaOnlineCore
//
//  Created by Hercules Junior on 4/10/16.
//  Copyright © 2016 Hercules Junior. All rights reserved.
//

#include "Skills.h"
#include <string.h>
#include <stdlib.h>

namespace core {
    namespace asset {
        Skills::Skills() {
            core::file::FileReader skillsIdxFileReader("/Users/herculesjr/Development/UltimaOnlineClient/UOFiles/skills.idx");
        }
        
        Skills::~Skills() {
        }
    }
}