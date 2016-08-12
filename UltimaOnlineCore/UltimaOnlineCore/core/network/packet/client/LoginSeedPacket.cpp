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
    
    int i = 0;
    char *p = strtok(_ipAddress, ".");
    while (p) {
        int i_dec = atoi(p);
        this->pack8(i++, i_dec);
        p = strtok(NULL, ".");
    }
}

const char* LoginSeedPacket::getIPAddress() {
    return _ipAddress;
}

void LoginSeedPacket::setIPAddress(const char* ipAddress) {
    free(_ipAddress);
    _ipAddress = (char*)malloc(strlen(ipAddress)+1);
    strcpy(_ipAddress, ipAddress);
}