//
//  LoginSeedPacket.h
//  UltimaOnlineCore
//
//  Created by Hercules Junior on 8/3/16.
//  Copyright © 2016 Hercules Junior. All rights reserved.
//

#ifndef CORE_NETWORK_PACKET_CLIENT_LOGINSEEDPACKET_H
#define CORE_NETWORK_PACKET_CLIENT_LOGINSEEDPACKET_H

#include "ClientPacket.h"

namespace core {
    namespace network {
        namespace packet {
            namespace client {
                class LoginSeedPacket : public ClientPacket {
                public:
                    LoginSeedPacket(const char *ipAddress);
                    ~LoginSeedPacket();
                    
                    virtual void buildPacket();
                    
                    const char *getIPAddress();
                    void setIPAddress(const char* ipAddress);
                    
                private:
                    char *_ipAddress;
                };
            }
        }
    }
}

#endif /* CORE_NETWORK_PACKET_CLIENT_LOGINSEEDPACKET_H */
