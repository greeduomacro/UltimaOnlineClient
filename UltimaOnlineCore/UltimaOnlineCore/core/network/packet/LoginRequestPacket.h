//
//  LoginRequestPacket.h
//  UltimaOnlineCore
//
//  Created by Hercules Junior on 8/3/16.
//  Copyright © 2016 Hercules Junior. All rights reserved.
//

#ifndef CORE_NETWORK_PACKET_LOGINREQUESTPACKET_H
#define CORE_NETWORK_PACKET_LOGINREQUESTPACKET_H

#include "Packet.h"

namespace core {
    namespace network {
        namespace packet {
            class LoginRequestPacket : public Packet {
            public:
                LoginRequestPacket(const char *login, const char *password);
                ~LoginRequestPacket();
                
            private:
                char *_login;
                char *password;
            };
        }
    }
}

#endif /* CORE_NETWORK_PACKET_LOGINREQUESTPACKET_H */
