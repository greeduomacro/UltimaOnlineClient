//
//  LoginRequestPacket.cpp
//  UltimaOnlineCore
//
//  Created by Hercules Junior on 8/3/16.
//  Copyright © 2016 Hercules Junior. All rights reserved.
//

#include "LoginRequestPacket.h"
#include <string.h>

using namespace core::network::packet;

LoginRequestPacket::LoginRequestPacket(const char *login, const char *password) : Packet(0x80, 62) {
    char *buf = (char*)this->getData();
    strcpy(buf+1, login);
    strcpy(buf+31, password);
    buf[61] = 0xFF;
}

LoginRequestPacket::~LoginRequestPacket() {
    
}