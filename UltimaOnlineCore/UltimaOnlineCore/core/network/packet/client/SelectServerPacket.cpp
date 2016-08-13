//
//  SelectServerPacket.cpp
//  UltimaOnlineCore
//
//  Created by Hercules Junior on 8/13/16.
//  Copyright © 2016 Hercules Junior. All rights reserved.
//

#include "SelectServerPacket.h"

using namespace core::network::packet::client;

SelectServerPacket::SelectServerPacket(short choice) : ClientPacket(0xA0, 3) {
    _choice = choice;
}

SelectServerPacket::~SelectServerPacket() {
}

void SelectServerPacket::buildPacket() {
    Packet::initPacket();
    this->pack16(1, _choice);
}
