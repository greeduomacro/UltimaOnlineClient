//
//  LoginRequestPacket.h
//  UltimaOnlineCore
//
//  Created by Hercules Junior on 8/3/16.
//  Copyright © 2016 Hercules Junior. All rights reserved.
//

#ifndef CORE_NETWORK_PACKET_CLIENT_LOGINREQUESTPACKET_H
#define CORE_NETWORK_PACKET_CLIENT_LOGINREQUESTPACKET_H

#include "ClientPacket.h"

namespace core {
    namespace network {
        namespace packet {
            namespace client {
                class LoginRequestPacket : public ClientPacket {
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
}

#endif /* CORE_NETWORK_PACKET_CLIENT_LOGINREQUESTPACKET_H */
