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
#include <iostream>

#include "FileReader.h"

namespace core {
    namespace asset {
        Skills::Skills() {
            
            core::file::FileReader skillsIdxFileReader("/Users/herculesjr/Development/UltimaOnlineClient/UOFiles/skills.idx");
            core::file::FileReader skillsFileReader("/Users/herculesjr/Development/UltimaOnlineClient/UOFiles/skills.mul");
            
            int index = 0;
            while (!skillsIdxFileReader.isEOF()) {
                ++index;
                int32_t lookup = skillsIdxFileReader.parseInt32();
                if (lookup < 0) { //Invalid, skip!
                    skillsIdxFileReader.seek(sizeof(int32_t)*2);
                    continue;
                }
                int32_t size = skillsIdxFileReader.parseInt32();
                skillsIdxFileReader.seek(sizeof(int32_t));
                if (size < 1) {
                    continue;
                }
                
                skillsFileReader.seek(lookup, core::file::FILE_SEEK_BEGIN);
                if (skillsFileReader.isEOF())
                    continue;
                bool isAction = skillsFileReader.parseBool();
                char* skillName = skillsFileReader.parseCStr();
                Skill *skill = new Skill(index-1, isAction, skillName);
                delete skillName;
                _skills.push_back(skill);
            }
            
            core::file::FileReader skillGroupsFileReader("/Users/herculesjr/Development/UltimaOnlineClient/UOFiles/SkillGrp.mul");
            int groupCount = skillGroupsFileReader.parseInt32();
            bool flag2 = false;
            if (groupCount == -1) {
                flag2 = true;
                groupCount = skillGroupsFileReader.parseInt32();
            }
            _skillGroups.push_back(new SkillGroup(0, "Miscellaneous"));
            for (int k = 1; k < groupCount; k++)
            {
                int num7;
                skillGroupsFileReader.seek((long)((flag2 ? 8 : 4) + ((k - 1) * (flag2 ? 0x22 : 0x11))), core::file::FILE_SEEK_BEGIN);
                char* groupName = skillGroupsFileReader.parseCStr();
                _skillGroups.push_back(new SkillGroup(k, groupName));
                delete groupName;
            }
            skillGroupsFileReader.seek((long) ((flag2 ? 8 : 4) + ((groupCount - 1) * (flag2 ? 0x22 : 0x11))), core::file::FILE_SEEK_BEGIN);
            for (Skill *skill : _skills) {
                int num9 = skillGroupsFileReader.parseInt32();
                SkillGroup *group = _skillGroups[num9];
                skill->setGroup(group);
                group->skills.push_back(skill);
            }
        }
        
        Skills::~Skills() {
            for (Skill *skill : _skills) {
                delete skill;
            }
            for (SkillGroup *skillGroup : _skillGroups) {
                delete skillGroup;
            }
        }
    }
}