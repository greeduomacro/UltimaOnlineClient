//
//  LoginSeedPacket.cpp
//  UltimaOnlineCore
//
//  Created by Hercules Junior on 8/6/16.
//  Copyright © 2016 Hercules Junior. All rights reserved.
//

#include "LoginSeedPacket.h"
#include <stdlib.h>
#include <string.h>

using namespace core::network::packet::client;

LoginSeedPacket::LoginSeedPacket(const char *ipAddress) : ClientPacket(0x00, 4) {
    _ipAddress = (char*)malloc(strlen(ipAddress)+1);
    strcpy(_ipAddress, ipAddress);
}

LoginSeedPacket::~LoginSeedPacket() {
    free(_ipAddress);
}

void LoginSeedPacket::buildPacket() {
    Packet::initPacket(false);
    uint32_t ip = Packet::IP2INT(_ipAddress);
    this->pack32(0, ip);
}

const char* LoginSeedPacket::getIPAddress() {
    return _ipAddress;
}

void LoginSeedPacket::setIPAddress(const char* ipAddress) {
    free(_ipAddress);
    _ipAddress = (char*)malloc(strlen(ipAddress)+1);
    strcpy(_ipAddress, ipAddress);
}