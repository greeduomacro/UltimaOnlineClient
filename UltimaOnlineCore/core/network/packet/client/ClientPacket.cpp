//
//  ClientPacket.cpp
//  UltimaOnlineCore
//
//  Created by Hercules Junior on 8/12/16.
//  Copyright © 2016 Hercules Junior. All rights reserved.
//

#include "ClientPacket.h"

using namespace core::network::packet::client;

ClientPacket::ClientPacket(uint8_t packetID, uint16_t length) : core::network::packet::Packet(packetID, length) {
}

ClientPacket::ClientPacket(const uint8_t* packetBuffer) : core::network::packet::Packet(packetBuffer) {
}

ClientPacket::~ClientPacket() {
}