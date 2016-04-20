//
//  SkillAsset.hpp
//  UltimaOnlineCore
//
//  Created by Hercules Junior on 4/10/16.
//  Copyright © 2016 Hercules Junior. All rights reserved.
//

#ifndef CORE_ASSET_Skill_h
#define CORE_ASSET_Skill_h

#import "Asset.h"
#import "SkillLock.h"
#import "SkillGroup.h"

namespace core {
    namespace asset {
        class Skill: public Asset {
        public:
            Skill();
            ~Skill();
            Skill(uint8_t idx, bool isAction, const char* skillName);
            bool isAction();
            const char* getName();
            void setAction(bool isAction);
            void setName(const char* skillName);
        private:
            uint8_t _idx;
            bool _action;
            char* _name;
            core::asset::SkillGroup *_group;
            SkillLock _lock;
            float real;
            float value;
        };
    }
}

#endif /* CORE_ASSET_Skill_h */
