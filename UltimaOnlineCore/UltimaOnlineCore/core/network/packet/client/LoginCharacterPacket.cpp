//
//  LoginCharacterPacket.cpp
//  UltimaOnlineCore
//
//  Created by Hercules Junior on 8/15/16.
//  Copyright © 2016 Hercules Junior. All rights reserved.
//

#include "LoginCharacterPacket.h"

#include <stdlib.h>
#include <string.h>
using namespace core::network::packet::client;

LoginCharacterPacket::LoginCharacterPacket(const char *character, Flag flag, uint32_t slot, uint32_t ipAddress) : ClientPacket(0x5D, 73) {
    _character = (char*)malloc(strlen(character)+1);
    strcpy(_character, character);
    
    _flags = flag;
    _slot = slot;
    _ipAddress = ipAddress;
}

LoginCharacterPacket::~LoginCharacterPacket() {
    free(_character);
}

void LoginCharacterPacket::buildPacket() {
    Packet::initPacket();
    int idx = 1;
    this->pack32(idx, 0xEDEDEDED);
    idx += 4;
    this->packCStr(idx, _character);
    idx += 32;
    this->pack32(idx, _flags);
    idx += 28;
    this->pack32(idx, _slot);
    idx += 4;
    this->pack32(idx, _ipAddress);
}

const char* LoginCharacterPacket::getCharacter() {
    return _character;
}

void LoginCharacterPacket::setCharacter(const char* character) {
    free(_character);
    _character = (char*)malloc(strlen(character)+1);
    strcpy(_character, character);
}

LoginCharacterPacket::Flag LoginCharacterPacket::getFlags() {
    return _flags;
}

void LoginCharacterPacket::setFlags(Flag flags) {
    _flags = flags;
}

uint32_t LoginCharacterPacket::getSlot() {
    return _slot;
}

void LoginCharacterPacket::setSlot(uint32_t slot) {
    _slot = slot;
}

uint32_t LoginCharacterPacket::getIpAddress() {
    return _ipAddress;
}

void LoginCharacterPacket::setIpAddress(uint32_t ipAddress) {
    _ipAddress = ipAddress;
}