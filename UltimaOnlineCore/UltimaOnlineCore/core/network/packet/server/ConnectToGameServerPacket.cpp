//
//  ConnectToGameServerPacket.cpp
//  UltimaOnlineCore
//
//  Created by Hercules Junior on 8/13/16.
//  Copyright © 2016 Hercules Junior. All rights reserved.
//

#include "ConnectToGameServerPacket.h"
#include <stdio.h>
#include <string.h>

using namespace core::network::packet::server;

ConnectToGameServerPacket::ConnectToGameServerPacket() : ServerPacket(0x8C, 0) {
    _gameServerIP = nullptr;
}

ConnectToGameServerPacket::ConnectToGameServerPacket(const uint8_t *packetBuffer) : ServerPacket(packetBuffer) {
    _gameServerIP = Packet::INT2IP(this->unpack32(1));
}

ConnectToGameServerPacket::~ConnectToGameServerPacket() {
    if (_gameServerIP != nullptr)
        delete[] _gameServerIP;
}

const char* ConnectToGameServerPacket::getGameServerIP() {
    return _gameServerIP;
}

unsigned short ConnectToGameServerPacket::getGameServerPort() {
    return _gameServerPort;
}

unsigned int ConnectToGameServerPacket::getGameServerKey() {
    return _gameServerKey;
}

ServerPacket* ConnectToGameServerPacket::clone(const uint8_t *packetBuffer) {
    ConnectToGameServerPacket *cloned = new ConnectToGameServerPacket(packetBuffer);
    return cloned;
}
