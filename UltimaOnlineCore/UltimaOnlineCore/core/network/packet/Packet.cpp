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

using namespace core::network::packet;

Packet::Packet(unsigned char packetID, unsigned short length) {
    _packetID = packetID;
    _length = length;
    _packetData = nullptr;
    if (_length > 0 && _length < std::numeric_limits<typeof(length)>::max()) {
        this->createPacketData();
    }
}

void Packet::createPacketData() {
    if (_packetData != nullptr) {
        free(_packetData);
    }
    _packetData = (unsigned char*)calloc(1, _length * sizeof(unsigned char));
    _packetData[0] = _packetID;
}

Packet::~Packet() {
    if (_packetData != nullptr) {
        free(_packetData);
    }
}

unsigned char* Packet::getData() {
    return _packetData;
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

unsigned int Packet::unpack32(const unsigned char *data)
{
    return (data[0] << 24) | (data[1] << 16) | (data[2] << 8) | data[3];
}

unsigned short Packet::unpack16(const unsigned char *data)
{
    return (data[0] << 8) | data[1];
}

void Packet::pack32(unsigned char *data, unsigned int x)
{
    data[0] = (unsigned char)(x >> 24);
    data[1] = (unsigned char)((x >> 16) & 0xff);
    data[2] = (unsigned char)((x >> 8) & 0xff);
    data[3] = (unsigned char)(x & 0xff);
    
    return;
}

void Packet::pack16(unsigned char *data, unsigned short x)
{
    data[0] = x >> 8;
    data[1] = x & 0xff;
    
    return;
}