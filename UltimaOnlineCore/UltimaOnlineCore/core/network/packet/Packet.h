//
//  Packet.h
//  UltimaOnlineCore
//
//  Created by Hercules Junior on 8/3/16.
//  Copyright © 2016 Hercules Junior. All rights reserved.
//

#ifndef CORE_NETWORK_PACKET_PACKET_H
#define CORE_NETWORK_PACKET_PACKET_H

namespace core {
    namespace network {
        namespace packet {
            
            class Packet {
            public:
                Packet(unsigned char packetID, unsigned short length);
                Packet(const unsigned char *packetBuffer);
                virtual ~Packet();
                virtual void initPacket(bool fillCmd = true);
                
                virtual void buildPacket() = 0;
                
                unsigned char getPacketID();
                void setPacketID(unsigned char packetID);
                
                unsigned short getLength();
                void setLength(unsigned short length);
                
                unsigned char* getData();
                
                void pack8(unsigned int idx, unsigned char x);
                void pack16(unsigned int idx, unsigned short x);
                void pack32(unsigned int idx, unsigned int x);
                void packCStr(unsigned int idx, const char *data);
                unsigned char unpack8(unsigned int idx);
                unsigned short unpack16(unsigned int idx);
                unsigned int unpack32(unsigned int idx);
                const char* unpackCStr(unsigned int idx);
                int unicodeToAscii(const char *unicodeText, int len, char *asciiText);
                
                const char* getName();
                
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
