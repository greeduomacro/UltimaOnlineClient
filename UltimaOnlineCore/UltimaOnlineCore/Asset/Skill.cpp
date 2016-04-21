//
//  SkillAsset.cpp
//  UltimaOnlineCore
//
//  Created by Hercules Junior on 4/10/16.
//  Copyright © 2016 Hercules Junior. All rights reserved.
//

#include "Skill.h"
#include <string.h>
#include <stdlib.h>

namespace core {
    namespace asset {
        Skill::Skill() {}
        
        Skill::Skill(uint8_t idx, bool action, const char* skillName) : _idx(idx), _action(action) {
            if (skillName != NULL)
                _name = strdup(skillName);
        }
        
        Skill::~Skill() {
            if (_name)
                free(_name);
            _group = NULL;
        }
        
        bool Skill::isAction() { return _action; }
        
        const char* Skill::getName() { return _name; }
        
        uint8_t Skill::getId() { return _idx; }
        
        const core::asset::SkillGroup* Skill::getGroup() {
            return _group;
        }
        
        void Skill::setId(uint8_t idx) {
            _idx = idx;
        }
        
        void Skill::setAction(bool isAction) {
            _action = isAction;
        }
        
        void Skill::setName(const char* skillName) {
            if (_name)
                free(_name);
            _name = strdup(skillName);
        }
        
        void Skill::setGroup(const core::asset::SkillGroup* group) {
            _group = group;
        }
    }
}