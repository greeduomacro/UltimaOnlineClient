//
//  CharacterListPacket.cpp
//  UltimaOnlineCore
//
//  Created by Hercules Junior on 8/15/16.
//  Copyright © 2016 Hercules Junior. All rights reserved.
//

#include "CharacterListPacket.h"

#include <stdlib.h>
#include <string.h>
using namespace core::network::packet::server;

CharacterListPacket::CharacterListPacket() : ServerPacket(0xA9, 0) {
}

CharacterListPacket::CharacterListPacket(const uint8_t *packetBuffer) : ServerPacket(packetBuffer) {
    uint8_t count = this->unpack8(3);
    _characters.resize(count);
    
    int idx = 4;
    for (int i = 0; i < count; ++i) {
        Character &c = _characters[i];
        strcpy(c.name, (char*)packetBuffer+idx);
        idx += 30;
        strcpy(c.password, (char*)packetBuffer+idx);
        idx += 30;
    }
    
    count = this->unpack8(idx++);
    _cities.resize(count);
    for (int i = 0; i < count; ++i) {
        City &c = _cities[i];
        c.index = this->unpack8(idx++);
        strcpy(c.name, (char*)packetBuffer+idx);
        idx += 31;
        strcpy(c.region, (char*)packetBuffer+idx);
        idx += 31;
    }
    _flags = (Flag)this->unpack32(idx);
}

CharacterListPacket::~CharacterListPacket() {
    _characters.clear();
    _cities.clear();
}

const std::vector<CharacterListPacket::Character>& CharacterListPacket::getCharacters() {
    return _characters;
}

const std::vector<CharacterListPacket::City>& CharacterListPacket::getCities() {
    return _cities;
}


ServerPacket* CharacterListPacket::clone(const uint8_t *packetBuffer) {
    CharacterListPacket *cloned = new CharacterListPacket(packetBuffer);
    return cloned;
}
