//
//  CharacterListPacket.h
//  UltimaOnlineCore
//
//  Created by Hercules Junior on 8/15/16.
//  Copyright © 2016 Hercules Junior. All rights reserved.
//

#ifndef CORE_NETWORK_PACKET_SERVER_CHARACTERLISTPACKET_H
#define CORE_NETWORK_PACKET_SERVER_CHARACTERLISTPACKET_H

#include "ServerPacket.h"
#include <vector>

namespace core {
    namespace network {
        namespace packet {
            namespace server {
                class CharacterListPacket : public ServerPacket {
                public:
                    
                    enum Flag {
                        NONE = 0x0000,
                        UNKNOWN1 = 0x0001,
                        IGR_CLIENT = 0x0002,
                        SINGLE_CHAR = 0x0004,
                        CONTEXT_MENU = 0x0008,
                        LIMIT_CHAR_SLOT = 0x0010,
                        TOOLTIP = 0x0020,
                        CHAR_SLOT6 = 0x0040,
                        SAMURAI_NINJA_CLASS = 0x0080,
                        ELVEN_RACE = 0x0100,
                        KR = 0x0200,
                        UO3D_CLIENT_TYPE = 0x0400,
                        UNKNOWN2 = 0x0800,
                        CHAR_SLOT7 = 0x1000,
                        UNKNOWN3 = 0x2000,
                        MOVEMENT_PACKET = 0x4000,
                        FELOCCA_AREA = 0x8000,
                    };
                    
                    struct Character {
                        char name[30];
                        char password[30];
                    };
                    
                    struct City {
                        uint8_t index;
                        char name[31];
                        char region[31];
                    };
                    
                    CharacterListPacket();
                    CharacterListPacket(const uint8_t *packetBuffer);
                    ~CharacterListPacket();
                    
                    virtual ServerPacket* clone(const uint8_t *packetBuffer);
                    
                    Flag getFlags();
                    const std::vector<Character>& getCharacters();
                    const std::vector<City>& getCities();
                    
                private:
                    Flag _flags;
                    std::vector<Character> _characters;
                    std::vector<City> _cities;
                };
            }
        }
    }
}

#endif /* CORE_NETWORK_PACKET_SERVER_CHARACTERLISTPACKET_H */
