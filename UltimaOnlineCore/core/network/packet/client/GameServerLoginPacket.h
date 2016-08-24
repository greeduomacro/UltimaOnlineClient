//
//  GameServerLoginPacket.h
//  UltimaOnlineCore
//
//  Created by Hercules Junior on 8/3/16.
//  Copyright © 2016 Hercules Junior. All rights reserved.
//

#ifndef CORE_NETWORK_PACKET_CLIENT_GAMESERVERLOGINPACKET_H
#define CORE_NETWORK_PACKET_CLIENT_GAMESERVERLOGINPACKET_H

#include "ClientPacket.h"

namespace core {
    namespace network {
        namespace packet {
            namespace client {
                class GameServerLoginPacket : public ClientPacket {
                public:
                    GameServerLoginPacket(const char *login, const char *password, uint32_t key);
                    ~GameServerLoginPacket();
                    
                    const char* getLogin();
                    void setLogin(const char* login);
                    
                    const char* getPassword();
                    void setPassword(const char* password);
                    
                    uint32_t getKey();
                    void setKey(uint32_t key);
                    
                    virtual void buildPacket();
                    
                private:
                    char *_login;
                    char *_password;
                    uint32_t _key;
                };
            }
        }
    }
}

#endif /* CORE_NETWORK_PACKET_CLIENT_GAMESERVERLOGINPACKET_H */
