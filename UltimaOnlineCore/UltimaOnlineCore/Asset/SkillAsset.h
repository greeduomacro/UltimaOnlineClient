//
//  SkillAsset.hpp
//  UltimaOnlineCore
//
//  Created by Hercules Junior on 4/10/16.
//  Copyright © 2016 Hercules Junior. All rights reserved.
//

#ifndef CORE_ASSET_SkillAsset_h
#define CORE_ASSET_SkillAsset_h

#import "Asset.h"

namespace core {
    namespace asset {
        class SkillAsset: public Asset {
        public:
            SkillAsset();
            ~SkillAsset();
            SkillAsset(bool isAction, const char* skillName);
            bool isAction();
            const char* getSkillName();
            void setIsAction(bool isAction);
            void setSkillName(const char* skillName);
        private:
            bool _isAction;
            char* _skillName;
        };
    }
}

#endif /* CORE_ASSET_SkillAsset_h */
