//
//  Packet.h
//  UltimaOnlineCore
//
//  Created by Hercules Junior on 8/3/16.
//  Copyright © 2016 Hercules Junior. All rights reserved.
//

#ifndef CORE_NETWORK_PACKET_PACKET_H
#define CORE_NETWORK_PACKET_PACKET_H

#define PACKET_LENGTH_DYNAMIC 0x8000

#include <stdint.h>

namespace core {
    namespace network {
        namespace packet {
            
            const int packetLengths[256] = {
                /* 0x00 */ 0x0068, 0x0005, 0x0007, PACKET_LENGTH_DYNAMIC,
                /* 0x05 */ 0x0002, 0x0005, 0x0005, 0x0007,
                /* 0x09 */ 0x000E, 0x0005, 0x000B, 0x010A,
                /* 0x0C */ PACKET_LENGTH_DYNAMIC, 0x0003, PACKET_LENGTH_DYNAMIC, 0x003D,
                /* 0x10 */ 0x00D7, PACKET_LENGTH_DYNAMIC, PACKET_LENGTH_DYNAMIC, 0x000A,
                /* 0x15 */ 0x0006, 0x0009, 0x0001, PACKET_LENGTH_DYNAMIC,
                /* 0x19 */ PACKET_LENGTH_DYNAMIC, PACKET_LENGTH_DYNAMIC, PACKET_LENGTH_DYNAMIC, 0x0025,
                /* 0x1C */ PACKET_LENGTH_DYNAMIC, 0x0005, 0x0004, 0x0008,
                /* 0x20 */ 0x0013, 0x0008, 0x0003, 0x001A,
                /* 0x25 */ 0x0007, 0x0014, 0x0005, 0x0002,
                /* 0x29 */ 0x0005, 0x0001, 0x0005, 0x0002,
                /* 0x2C */ 0x0002, 0x0011, 0x000F, 0x000A,
                /* 0x30 */ 0x0005, 0x0001, 0x0002, 0x0002,
                /* 0x35 */ 0x000A, 0x028D, PACKET_LENGTH_DYNAMIC, 0x0008,
                /* 0x39 */ 0x0007, 0x0009, PACKET_LENGTH_DYNAMIC, PACKET_LENGTH_DYNAMIC,
                /* 0x3C */ PACKET_LENGTH_DYNAMIC, 0x0002, 0x0025, PACKET_LENGTH_DYNAMIC,
                /* 0x40 */ 0x00C9, PACKET_LENGTH_DYNAMIC, PACKET_LENGTH_DYNAMIC, 0x0229,
                /* 0x45 */ 0x02C9, 0x0005, PACKET_LENGTH_DYNAMIC, 0x000B,
                /* 0x49 */ 0x0049, 0x005D, 0x0005, 0x0009,
                /* 0x4C */ PACKET_LENGTH_DYNAMIC, PACKET_LENGTH_DYNAMIC, 0x0006, 0x0002,
                /* 0x50 */ PACKET_LENGTH_DYNAMIC, PACKET_LENGTH_DYNAMIC, PACKET_LENGTH_DYNAMIC, 0x0002,
                /* 0x55 */ 0x000C, 0x0001, 0x000B, 0x006E, 0x006A,
                /* 0x59 */ PACKET_LENGTH_DYNAMIC, PACKET_LENGTH_DYNAMIC, 0x0004,
                /* 0x5C */ 0x0002, 0x0049, PACKET_LENGTH_DYNAMIC, 0x0031,
                /* 0x60 */ 0x0005, 0x0009, 0x000F, 0x000D,
                /* 0x65 */ 0x0001, 0x0004, PACKET_LENGTH_DYNAMIC, 0x0015,
                /* 0x69 */ PACKET_LENGTH_DYNAMIC, PACKET_LENGTH_DYNAMIC, 0x0003, 0x0009,
                /* 0x6C */ 0x0013, 0x0003, 0x000E, PACKET_LENGTH_DYNAMIC,
                /* 0x70 */ 0x001C, PACKET_LENGTH_DYNAMIC, 0x0005, 0x0002,
                /* 0x75 */ PACKET_LENGTH_DYNAMIC, 0x0023, 0x0010, 0x0011,
                /* 0x79 */ PACKET_LENGTH_DYNAMIC, 0x0009, PACKET_LENGTH_DYNAMIC, 0x0002,
                /* 0x7C */ PACKET_LENGTH_DYNAMIC, 0x000D, 0x0002, PACKET_LENGTH_DYNAMIC,
                /* 0x80 */ 0x003E, PACKET_LENGTH_DYNAMIC, 0x0002, 0x0027,
                /* 0x85 */ 0x0045, 0x0002, PACKET_LENGTH_DYNAMIC, PACKET_LENGTH_DYNAMIC,
                /* 0x89 */ 0x0042, PACKET_LENGTH_DYNAMIC, PACKET_LENGTH_DYNAMIC, PACKET_LENGTH_DYNAMIC,
                /* 0x8C */ 0x000B, PACKET_LENGTH_DYNAMIC, PACKET_LENGTH_DYNAMIC, PACKET_LENGTH_DYNAMIC,
                /* 0x90 */ 0x0013, 0x0041, PACKET_LENGTH_DYNAMIC, 0x0063,
                /* 0x95 */ PACKET_LENGTH_DYNAMIC, 0x0009, PACKET_LENGTH_DYNAMIC, 0x0002,
                /* 0x99 */ PACKET_LENGTH_DYNAMIC, 0x001A, PACKET_LENGTH_DYNAMIC, 0x0102,
                /* 0x9C */ 0x0135, 0x0033, PACKET_LENGTH_DYNAMIC, PACKET_LENGTH_DYNAMIC,
                /* 0xA0 */ 0x0003, 0x0009, 0x0009, 0x0009,
                /* 0xA5 */ 0x0095, PACKET_LENGTH_DYNAMIC, PACKET_LENGTH_DYNAMIC, 0x0004,
                /* 0xA9 */ PACKET_LENGTH_DYNAMIC, PACKET_LENGTH_DYNAMIC, 0x0005, PACKET_LENGTH_DYNAMIC,
                /* 0xAC */ PACKET_LENGTH_DYNAMIC, PACKET_LENGTH_DYNAMIC, PACKET_LENGTH_DYNAMIC, 0x000D,
                /* 0xB0 */ PACKET_LENGTH_DYNAMIC, PACKET_LENGTH_DYNAMIC, PACKET_LENGTH_DYNAMIC, PACKET_LENGTH_DYNAMIC,
                /* 0xB5 */ PACKET_LENGTH_DYNAMIC, 0x0040, 0x0009, PACKET_LENGTH_DYNAMIC,
                /* 0xB9 */ PACKET_LENGTH_DYNAMIC, 0x0003, 0x0006, 0x0009,
                /* 0xBC */ 0x0003, PACKET_LENGTH_DYNAMIC, PACKET_LENGTH_DYNAMIC, PACKET_LENGTH_DYNAMIC,
                /* 0xC0 */ 0x0024, PACKET_LENGTH_DYNAMIC, PACKET_LENGTH_DYNAMIC, PACKET_LENGTH_DYNAMIC,
                /* 0xC5 */ 0x0006, 0x00CB, 0x0001, 0x0031,
                /* 0xC9 */ 0x0002, 0x0006, 0x0006, 0x0007,
                /* 0xCC */ PACKET_LENGTH_DYNAMIC, 0x0001, PACKET_LENGTH_DYNAMIC, 0x004E,
                /* 0xD0 */ PACKET_LENGTH_DYNAMIC, 0x0002, 0x0019, PACKET_LENGTH_DYNAMIC,
                /* 0xD5 */ PACKET_LENGTH_DYNAMIC, PACKET_LENGTH_DYNAMIC, PACKET_LENGTH_DYNAMIC, PACKET_LENGTH_DYNAMIC,
                /* 0xD9 */ PACKET_LENGTH_DYNAMIC, 0x010C, PACKET_LENGTH_DYNAMIC, PACKET_LENGTH_DYNAMIC,
                /* 0xDC */ 0x0009, 0x0000, 0x0000, 0x0000,
                /* 0xE0 */ 0x0000, 0x0000, 0x0000, 0x0000,
                /* 0xE5 */ 0x0000, 0x0000, 0x0000, 0x0000,
                /* 0xE9 */ 0x0000, 0x0000, 0x0000, 0x0000,
                /* 0xEC */ 0x0000, 0x0000, 0x0000, 0x0000,
                /* 0xF0 */ PACKET_LENGTH_DYNAMIC, 0x0000, 0x0000, 0x0000,
                /* 0xF5 */ 0x0000, 0x0000, 0x0000, 0x0000,
                /* 0xF9 */ 0x0000, 0x0000, 0x0000, 0x0000,
                /* 0xFC */ 0x0000, 0x0000, 0x0000, 0x0004
            };

            
            class Packet {
            public:
                Packet(uint8_t packetID, uint16_t length);
                Packet(const uint8_t *packetBuffer);
                virtual ~Packet();
                virtual void initPacket(bool fillCmd = true);
                
                uint8_t getPacketID();
                void setPacketID(uint8_t packetID);
                
                uint16_t getLength();
                void setLength(uint16_t length);
                
                uint8_t* getData();
                
                void pack8(unsigned int idx, uint8_t x);
                void pack16(unsigned int idx, uint16_t x);
                void pack32(unsigned int idx, uint32_t x);
                void packCStr(unsigned int idx, const char *data);
                uint8_t unpack8(unsigned int idx);
                uint16_t unpack16(unsigned int idx);
                uint32_t unpack32(unsigned int idx);
                const char* unpackCStr(unsigned int idx);
                int unicodeToAscii(const char *unicodeText, int len, char *asciiText);
                
                const char* getName();
                
                static const char* getPacketName(uint8_t packetID);
                static unsigned int getPacketLength(uint8_t packetID);
                static unsigned int getPacketLength(const uint8_t *packetBuffer);
                static Packet* createPacket(const uint8_t *packetBuffer, uint16_t length);
                static uint32_t IP2INT(const char* ipAddress);
                static char* INT2IP(uint32_t ipAddress);
                static char* INT2IP(uint32_t ipAddress, bool bigEndian);
                
            protected:
                void createPacketData();
                
                uint8_t *_packetData;
            private:
                uint8_t _packetID;
                uint16_t _length;
            };
        }
    }
}

#endif /* CORE_NETWORK_PACKET_PACKET_H */
