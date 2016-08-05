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
                
                const char* getLogin();
                void setLogin(const char* login);
                
                const char* getPassword();
                void setPassword(const char* password);
                
                virtual void buildPacket();
                
            private:
                char *_login;
                char *_password;
            };
        }
    }
}

#endif /* CORE_NETWORK_PACKET_LOGINREQUESTPACKET_H */
