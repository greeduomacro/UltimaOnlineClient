//
//  Packet.cpp
//  UltimaOnlineCore
//
//  Created by Hercules Junior on 8/3/16.
//  Copyright © 2016 Hercules Junior. All rights reserved.
//

#include "Packet.h"
#include <limits>
#include <stdlib.h>
#include <string.h>

using namespace core::network::packet;

Packet::Packet(unsigned char packetID, unsigned short length) {
    _packetID = packetID;
    _length = length;
    _packetData = nullptr;
}

void Packet::createPacketData() {
    if (_packetData != nullptr) {
        free(_packetData);
    }
    _packetData = (unsigned char*)calloc(1, _length * sizeof(unsigned char));
}

Packet::~Packet() {
    if (_packetData != nullptr) {
        free(_packetData);
    }
}

unsigned char* Packet::getData() {
    return _packetData;
}

unsigned short Packet::getLength() {
    return _length;
}
void Packet::setLength(unsigned short length) {
    _length = length;
}

void Packet::buildPacket() {
    if (_length > 0 && _length < std::numeric_limits<typeof(_length)>::max()) {
        this->createPacketData();
    }
    _packetData[0] = _packetID;
}

int Packet::unicodeToAscii(const char *unicodeText, int Len, char *asciiText)
{
    int i = 0, nonAsciiCompatible = 0;
    
    for(i = 0; i < Len; i+=2)
    {
        if(unicodeText[i] != 0x00)
            nonAsciiCompatible++;
        
        asciiText[i/2] = unicodeText[i+1];
    }
    
    asciiText[i++/2] = '\0'; /* null terminate it */
    
    return nonAsciiCompatible;
}

unsigned int Packet::unpack32(unsigned int idx)
{
    unsigned char *data = _packetData+idx;
    return (data[0] << 24) | (data[1] << 16) | (data[2] << 8) | data[3];
}

unsigned short Packet::unpack16(unsigned int idx)
{
    unsigned char *data = _packetData+idx;
    return (data[0] << 8) | data[1];
}

void Packet::pack32(unsigned int idx, unsigned int x)
{
    unsigned char *data = _packetData+idx;
    data[0] = (unsigned char)(x >> 24);
    data[1] = (unsigned char)((x >> 16) & 0xff);
    data[2] = (unsigned char)((x >> 8) & 0xff);
    data[3] = (unsigned char)(x & 0xff);
    
    return;
}

void Packet::pack16(unsigned int idx, unsigned short x)
{
    unsigned char *data = _packetData+idx;
    data[0] = x >> 8;
    data[1] = x & 0xff;
    
    return;
}

void Packet::pack8(unsigned int idx, unsigned char x)
{
    unsigned char *data = _packetData+idx;
    data[0] = x;
    return;
}

void Packet::packCStr(unsigned int idx, const char *data) {
    strcpy((char*)_packetData+idx, data);
}