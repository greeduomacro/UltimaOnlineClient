//
//  LoginDeniedPacket.cpp
//  UltimaOnlineCore
//
//  Created by Hercules Junior on 8/7/16.
//  Copyright © 2016 Hercules Junior. All rights reserved.
//

#include "LoginDeniedPacket.h"

#include <stdlib.h>
#include <string.h>
using namespace core::network::packet;

LoginDeniedPacket::LoginDeniedPacket(const unsigned char *packetBuffer) : Packet(packetBuffer) {
    _reason = (core::network::packet::LoginDeniedPacket::Reason)this->unpack8(1);
}

core::network::packet::LoginDeniedPacket::Reason LoginDeniedPacket::getReason() {
    return _reason;
}

void LoginDeniedPacket::setReason(core::network::packet::LoginDeniedPacket::Reason reason) {
    _reason = reason;
}
