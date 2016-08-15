//
//  LoginCharacterPacket.h
//  UltimaOnlineCore
//
//  Created by Hercules Junior on 8/15/16.
//  Copyright © 2016 Hercules Junior. All rights reserved.
//

#ifndef CORE_NETWORK_PACKET_CLIENT_LOGINCHARACTERPACKET_H
#define CORE_NETWORK_PACKET_CLIENT_LOGINCHARACTERPACKET_H

#include "ClientPacket.h"

namespace core {
    namespace network {
        namespace packet {
            namespace client {
                class LoginCharacterPacket : public ClientPacket {
                public:
                    
                    enum Flag {
                        T2A = 0x00,
                        RENAISSANCE = 0x01,
                        THIRD_DAWN = 0x02,
                        LBR = 0x04,
                        AOS = 0x08,
                        SE = 0x10,
                        SA = 0x20,
                        UO3D = 0x40,
                        RESERVED = 0x80,
                        CLIENT3D = 0x100
                    };
                    
                    LoginCharacterPacket(const char *character, Flag flag, uint32_t slot, uint32_t ipAddress);
                    ~LoginCharacterPacket();
                    
                    const char* getCharacter();
                    void setCharacter(const char* character);
                    
                    Flag getFlags();
                    void setFlags(Flag flags);
                    
                    uint32_t getSlot();
                    void setSlot(uint32_t slot);
                    
                    uint32_t getIpAddress();
                    void setIpAddress(uint32_t ipAddress);
                    
                    virtual void buildPacket();
                    
                private:
                    char *_character;
                    Flag _flags;
                    uint32_t _slot;
                    uint32_t _ipAddress;
                };
            }
        }
    }
}

#endif /* CORE_NETWORK_PACKET_CLIENT_LOGINCHARACTERPACKET_H */
