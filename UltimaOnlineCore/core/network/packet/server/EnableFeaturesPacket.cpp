//
//  EnableFeaturesPacket.cpp
//  UltimaOnlineCore
//
//  Created by Hercules Junior on 8/15/16.
//  Copyright © 2016 Hercules Junior. All rights reserved.
//

#include "EnableFeaturesPacket.h"

using namespace core::network::packet::server;

EnableFeaturesPacket::EnableFeaturesPacket() : ServerPacket(0xB9, 3) {
}

EnableFeaturesPacket::EnableFeaturesPacket(const uint8_t *packetBuffer) : ServerPacket(packetBuffer) {
    _features = (Feature)this->unpack16(1);
}

EnableFeaturesPacket::~EnableFeaturesPacket() {
}

ServerPacket* EnableFeaturesPacket::clone(const uint8_t *packetBuffer) {
    EnableFeaturesPacket *cloned = new EnableFeaturesPacket(packetBuffer);
    return cloned;
}

EnableFeaturesPacket::Feature EnableFeaturesPacket::getFeatures() {
    return _features;
}
