//
//  LoginDeniedPacket.h
//  UltimaOnlineCore
//
//  Created by Hercules Junior on 8/7/16.
//  Copyright © 2016 Hercules Junior. All rights reserved.
//

#ifndef CORE_NETWORK_PACKET_LOGINDENIEDPACKET_H
#define CORE_NETWORK_PACKET_LOGINDENIEDPACKET_H

#include "Packet.h"

namespace core {
    namespace network {
        namespace packet {
            class LoginDeniedPacket : public Packet {
            public:
                
                enum Reason {
                    UNKNOWN_USER = 0x00,
                    ACCOUNT_IN_USE = 0x01,
                    ACCOUNT_DISABLED = 0x02,
                    ACCOUNT_CREDENTIALS_INVALID = 0x03,
                    COMMUNICATIONS_FAILED = 0x04,
                    IGR_CONCURRENCY_LIMIT = 0x05,
                    IGR_TIME_LIMIT = 0x06,
                    IGR_AUTHENTICATION = 0x07
                };
                
                LoginDeniedPacket(const unsigned char *packetBuffer);
                
                Reason getReason();
                void setReason(Reason reason);
                
            private:
                Reason _reason;
            };
        }
    }
}

#endif /* CORE_NETWORK_PACKET_LOGINDENIEDPACKET_H */
