//
//  ServerPacket.cpp
//  UltimaOnlineCore
//
//  Created by Hercules Junior on 8/12/16.
//  Copyright © 2016 Hercules Junior. All rights reserved.
//

#include "Log.h"
#include "ServerPacket.h"
#include "ServerPackets.h"

#include <map>

using namespace core::network::packet::server;

ServerPacket::ServerPacket(uint8_t packetID, uint16_t length) : core::network::packet::Packet(packetID, length) {
    
}
ServerPacket::ServerPacket(const uint8_t *packetBuffer) : core::network::packet::Packet(packetBuffer) {
    
}
ServerPacket::~ServerPacket() {
    
}

ServerPacket* ServerPacket::createPacket(const uint8_t *packetBuffer, uint16_t length) {
    static std::map<uint8_t, ServerPacket*> packetTypes = {
        {0x0B, nullptr},
        {0x0C, nullptr},
        {0x11, nullptr},
        {0x15, nullptr},
        {0x16, nullptr},
        {0x17, nullptr},
        {0x1A, nullptr},
        {0x1B, nullptr},
        {0x1C, nullptr},
        {0x1D, nullptr},
        {0x1F, nullptr},
        {0x20, nullptr},
        {0x21, nullptr},
        {0x22, nullptr},
        {0x23, nullptr},
        {0x24, nullptr},
        {0x25, nullptr},
        {0x26, nullptr},
        {0x27, nullptr},
        {0x28, nullptr},
        {0x29, nullptr},
        {0x2A, nullptr},
        {0x2B, nullptr},
        {0x2C, nullptr},
        {0x2D, nullptr},
        {0x2E, nullptr},
        {0x2F, nullptr},
        {0x30, nullptr},
        {0x31, nullptr},
        {0x32, nullptr},
        {0x33, nullptr},
        {0x36, nullptr},
        {0x39, nullptr},
        {0x3A, nullptr},
        {0x3C, nullptr},
        {0x3E, nullptr},
        {0x3F, nullptr},
        {0x4E, nullptr},
        {0x4F, nullptr},
        {0x53, nullptr},
        {0x54, nullptr},
        {0x55, nullptr},
        {0x56, nullptr},
        {0x5B, nullptr},
        {0x65, nullptr},
        {0x66, nullptr},
        {0x6C, nullptr},
        {0x6D, nullptr},
        {0x6E, nullptr},
        {0x6F, nullptr},
        {0x70, nullptr},
        {0x71, nullptr},
        {0x72, nullptr},
        {0x73, nullptr},
        {0x74, nullptr},
        {0x76, nullptr},
        {0x77, nullptr},
        {0x78, nullptr},
        {0x7C, nullptr},
        {0x82, new LoginDeniedPacket()},
        {0x86, nullptr},
        {0x88, nullptr},
        {0x89, nullptr},
        {0x8C, nullptr},
        {0x90, nullptr},
        {0x93, nullptr},
        {0x95, nullptr},
        {0x97, nullptr},
        {0x98, nullptr},
        {0x99, nullptr},
        {0x9A, nullptr},
        {0x9C, nullptr},
        {0x9E, nullptr},
        {0xA1, nullptr},
        {0xA2, nullptr},
        {0xA3, nullptr},
        {0xA5, nullptr},
        {0xA6, nullptr},
        {0xA8, new GameServerListPacket()},
        {0xA9, nullptr},
        {0xAA, nullptr},
        {0xAB, nullptr},
        {0xAE, nullptr},
        {0xAF, nullptr},
        {0xB0, nullptr},
        {0xB2, nullptr},
        {0xB7, nullptr},
        {0xB8, nullptr},
        {0xB9, nullptr},
        {0xBA, nullptr},
        {0xBB, nullptr},
        {0xBC, nullptr},
        {0xBD, nullptr},
        {0xBE, nullptr},
        {0xBF, nullptr},
        {0xC0, nullptr},
        {0xC1, nullptr},
        {0xC2, nullptr},
        {0xC4, nullptr},
        {0xC6, nullptr},
        {0xC7, nullptr},
        {0xC8, nullptr},
        {0xC9, nullptr},
        {0xCA, nullptr},
        {0xCB, nullptr},
        {0xCC, nullptr},
        {0xD0, nullptr},
        {0xD1, nullptr},
        {0xD2, nullptr},
        {0xD3, nullptr},
        {0xD4, nullptr},
        {0xD6, nullptr},
        {0xD7, nullptr},
        {0xD8, nullptr},
        {0xDB, nullptr},
        {0xDC, nullptr},
        {0xDD, nullptr},
        {0xDE, nullptr},
        {0xDF, nullptr},
        {0xE2, nullptr},
        {0xE3, nullptr},
        {0xF0, nullptr},
        {0xF1, nullptr},
        {0xF3, nullptr},
        {0xF5, nullptr}
    };
    uint8_t packetID = packetBuffer[0];
    ServerPacket *packet = packetTypes[packetID];
    if (packet == nullptr) {
        LOG_WARN("[ServerPacket::createPacket] Packet 0x%02X unknown (%s)\n", packetID, Packet::getPacketName(packetID));
    } else {
        packet = packet->clone(packetBuffer);
    }
    return packet;
}