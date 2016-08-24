//
//  EnableFeaturesPacket.h
//  UltimaOnlineCore
//
//  Created by Hercules Junior on 8/7/16.
//  Copyright © 2016 Hercules Junior. All rights reserved.
//

#ifndef CORE_NETWORK_PACKET_SERVER_ENABLEFEATURESPACKET_H
#define CORE_NETWORK_PACKET_SERVER_ENABLEFEATURESPACKET_H

#include "ServerPacket.h"

namespace core {
    namespace network {
        namespace packet {
            namespace server {
                class EnableFeaturesPacket : public ServerPacket {
                public:
                    
                    enum Feature {
                        NONE = 0x0000,
                        CHAT = 0x0001, //t2a regions
                        ANIMATION = 0x0002,
                        THIRDDAWN = 0x0004,
                        LBR = 0x0008,
                        AOS = 0x0010,
                        CHAR_SLOT6 = 0x0020,
                        SE = 0x0040,
                        ML = 0x0080,
                        AGE8_SPLASH = 0x0100,
                        AGE9_SPLASH = 0x0200,
                        AGE10_SPLASH = 0x0400,
                        INCREASE_STORAGE = 0x0800,
                        CHAR_SLOT7 = 0x1000,
                        KR = 0x2000,
                        TRIAL_ACCOUNT = 0x4000,
                        AGE11_SPLASH = 0x8000,
                    };
                    
                    EnableFeaturesPacket();
                    EnableFeaturesPacket(const uint8_t *packetBuffer);
                    ~EnableFeaturesPacket();
                    
                    virtual ServerPacket* clone(const uint8_t *packetBuffer);
                    
                    Feature getFeatures();
                    
                private:
                    Feature _features;
                };
            }
        }
    }
}

#endif /* CORE_NETWORK_PACKET_SERVER_ENABLEFEATURESPACKET_H */
