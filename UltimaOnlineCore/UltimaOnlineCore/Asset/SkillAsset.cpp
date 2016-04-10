//
//  SkillAsset.cpp
//  UltimaOnlineCore
//
//  Created by Hercules Junior on 4/10/16.
//  Copyright © 2016 Hercules Junior. All rights reserved.
//

#include "SkillAsset.h"
#include <string.h>
#include <stdlib.h>

namespace core {
    namespace asset {
        SkillAsset::SkillAsset() {}
        
        SkillAsset::SkillAsset(bool isAction, const char* skillName) : _isAction(isAction) {
            if (skillName != NULL)
                _skillName = strdup(skillName);
        }
        
        SkillAsset::~SkillAsset() {
            if (_skillName)
                free(_skillName);
        }
        
        bool SkillAsset::isAction() { return _isAction; }
        
        const char* SkillAsset::getSkillName() { return _skillName; }
        
        void SkillAsset::setIsAction(bool isAction) {
            _isAction = isAction;
        }
        
        void SkillAsset::setSkillName(const char* skillName) {
            if (_skillName)
                free(_skillName);
            _skillName = strdup(skillName);
        }
    }
}