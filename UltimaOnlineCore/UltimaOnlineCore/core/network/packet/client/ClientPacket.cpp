//
//  ClientPacket.cpp
//  UltimaOnlineCore
//
//  Created by Hercules Junior on 8/12/16.
//  Copyright © 2016 Hercules Junior. All rights reserved.
//

#include "ClientPacket.h"

using namespace core::network::packet::client;

ClientPacket::ClientPacket(unsigned char packetID, unsigned short length) : core::network::packet::Packet(packetID, length) {
}

ClientPacket::ClientPacket(const unsigned char* packetBuffer) : core::network::packet::Packet(packetBuffer) {
}

ClientPacket::~ClientPacket() {
}