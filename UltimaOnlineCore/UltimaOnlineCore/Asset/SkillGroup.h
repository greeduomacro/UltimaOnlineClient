//
//  SkillAsset.hpp
//  UltimaOnlineCore
//
//  Created by Hercules Junior on 4/10/16.
//  Copyright © 2016 Hercules Junior. All rights reserved.
//

#ifndef CORE_ASSET_SkillGroup_h
#define CORE_ASSET_SkillGroup_h

#import <vector>
#import "Asset.h"

namespace core {
    namespace asset {
        class Skill;
        class SkillGroup: public Asset {
        public:
            SkillGroup();
            ~SkillGroup();
            SkillGroup(uint8_t groupID, const char* name);
            const char* getName();
            uint8_t getGroupID();
            void setGroupID(uint8_t groupID);
            void setName(const char* skillName);
        private:
            uint8_t _groupID;
            char* _name;
            std::vector<const core::asset::Skill* const> _skills;
        };
    }
}

#endif /* CORE_ASSET_SkillGroup_h */
