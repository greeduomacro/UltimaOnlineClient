//
//  Packet.h
//  UltimaOnlineCore
//
//  Created by Hercules Junior on 8/3/16.
//  Copyright © 2016 Hercules Junior. All rights reserved.
//

#ifndef CORE_NETWORK_PACKET_PACKET_H
#define CORE_NETWORK_PACKET_PACKET_H

#include <stack>

namespace core {
    namespace network {
        namespace packet {
            
            class Packet {
            public:
                Packet(unsigned char packetID, unsigned short length);
                virtual ~Packet();
                
                unsigned char getPacketID();
                void setPacketID(unsigned char packetID);
                
                unsigned short getLength();
                void setLength(unsigned short length);
                
                unsigned char* getData();
                
                void pack16(unsigned char *Buf, unsigned short x);
                void pack32(unsigned char *Buf, unsigned int x);
                unsigned short unpack16(const unsigned char *data);
                unsigned int unpack32(const unsigned char *data);
                int unicodeToAscii(const char *unicodeText, int len, char *asciiText);
                
            protected:
                void createPacketData();
                
                unsigned char *_packetData;
            private:
                unsigned char _packetID;
                unsigned short _length;
            };
        }
    }
}

#endif /* CORE_NETWORK_PACKET_PACKET_H */
