//
//  LoginDeniedPacket.cpp
//  UltimaOnlineCore
//
//  Created by Hercules Junior on 8/7/16.
//  Copyright © 2016 Hercules Junior. All rights reserved.
//

#include "GameServerListPacket.h"

#include <stdlib.h>
#include <string.h>
using namespace core::network::packet::server;

GameServerListPacket::GameServerListPacket() : ServerPacket(0x82, 0) {
}

GameServerListPacket::GameServerListPacket(const uint8_t *packetBuffer) : ServerPacket(packetBuffer) {
    _flag = this->unpack8(3);
    uint16_t count = this->unpack16(4);
    int idx = 6;
    for (int i = 0; i < count; ++i) {
        ServerEntry *entry = (ServerEntry*)malloc(sizeof(ServerEntry));
        entry->index = this->unpack16(idx);
        idx += 2;
        strcpy(entry->name, this->unpackCStr(idx));
        idx += 32;
        entry->full = this->unpack8(idx++);
        entry->timezone = this->unpack8(idx++);
        entry->address = this->unpack32(idx);
        idx += 4;
        _serverList.push_back(entry);
    }
}

GameServerListPacket::~GameServerListPacket() {
    for (int i = 0; i < _serverList.size(); ++i) {
        ServerEntry *entry = _serverList[i];
        free(entry);
    }
    _serverList.clear();
}

const std::vector<GameServerListPacket::ServerEntry*>& GameServerListPacket::getServerList() {
    return _serverList;
}

ServerPacket* GameServerListPacket::clone(const uint8_t *packetBuffer) {
    GameServerListPacket *cloned = new GameServerListPacket(packetBuffer);
    return cloned;
}

/*

Subcommand Build
N/A

Notes
System Info Flags: 0xCC - Do not send video card info. 0x64 - Send Video card. RunUO And SteamEngine both send 0x5D.

Server IP has to be sent in reverse order. For example, 192.168.0.1 is sent as 0100A8C0.
*/