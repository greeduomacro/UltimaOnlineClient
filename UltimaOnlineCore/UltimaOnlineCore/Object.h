//
//  SkillLock.h
//  UltimaOnlineCore
//
//  Created by hercules on 4/22/16.
//  Copyright © 2016 Hercules Junior. All rights reserved.
//

#ifndef CORE_TYPES_OBJECT_H_
#define CORE_TYPES_OBJECT_H_

namespace core {
    class Object {
    public:
        /**
         * \brief Default empty constructor
         */
        Object() { }
        
        
        /**
         * Empty virtual destructor
         */
        virtual ~Object() {	}
        
        
        /**
         * Default empty copy constructor
         * @param other The instance to copy from
         */
        Object (const Object& other) { }
    };
}

#endif /* CORE_TYPES_OBJECT_H_ */
