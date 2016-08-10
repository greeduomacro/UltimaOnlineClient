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

const char* LoginDeniedPacket::getReasonCStr() {
    switch (_reason) {
        case Reason::UNKNOWN_USER:
            return "Unknown User";
            break;
        case Reason::ACCOUNT_IN_USE:
            return "Account in use";
            break;
        case Reason::ACCOUNT_DISABLED:
            return "Account disabled";
            break;
        case Reason::ACCOUNT_CREDENTIALS_INVALID:
            return "Invalid credentials";
            break;
        case Reason::COMMUNICATIONS_FAILED:
            return "Communications failed";
            break;
        case Reason::IGR_CONCURRENCY_LIMIT:
            return "IGR Concurrency limit";
            break;
        case Reason::IGR_TIME_LIMIT:
            return "IGR Time limit";
            break;
        case Reason::IGR_AUTHENTICATION:
            return "IGR Authentication failed";
            break;
        default:
            return "Reason unknown";
            break;
    }
}

void LoginDeniedPacket::setReason(core::network::packet::LoginDeniedPacket::Reason reason) {
    _reason = reason;
}
