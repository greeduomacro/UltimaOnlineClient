//
//  SkillAsset.cpp
//  UltimaOnlineCore
//
//  Created by Hercules Junior on 4/10/16.
//  Copyright © 2016 Hercules Junior. All rights reserved.
//

#include "SkillGroup.h"
#include <string.h>
#include <stdlib.h>

namespace core {
    namespace asset {
        SkillGroup::SkillGroup() {}
        
        SkillGroup::SkillGroup(uint8_t groupID, const char* name) : _groupID(groupID) {
            if (name != NULL)
                _name = strdup(name);
        }
        
        SkillGroup::~SkillGroup() {
            if (_name)
                free(_name);
        }
        
        uint8_t SkillGroup::getGroupID() { return _groupID; }
        
        const char* SkillGroup::getName() { return _name; }
        
        void SkillGroup::setGroupID(uint8_t groupID) {
            _groupID = groupID;
        }
        
        void SkillGroup::setName(const char* skillName) {
            if (_name)
                free(_name);
            _name = strdup(skillName);
        }
    }
}