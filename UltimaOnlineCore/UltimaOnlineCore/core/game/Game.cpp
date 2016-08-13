//
//  Game.cpp
//  UltimaOnlineCore
//
//  Created by Hercules Junior on 8/10/16.
//  Copyright © 2016 Hercules Junior. All rights reserved.
//

#include "Game.h"
#include "NetworkManager.h"
#include "PacketHandler.h"
#include "Log.h"
#include "ServerPackets.h"

using namespace core::game;
using namespace core::network;
using namespace core::network::packet;
using namespace core::network::packet::server;

Game& Game::getInstance() {
    static Game instance; // Guaranteed to be destroyed.
    // Instantiated on first use.
    return instance;
}

Game::Game() {
    PacketHandler<Game> *loginDeniedPacketHandler = new PacketHandler<Game>(*this, &Game::handleLoginDenied);
    network::NetworkManager::getInstance().registerPacketHandler(NetworkManager::HandlerQueue::System, 0x82, *loginDeniedPacketHandler);
    
    PacketHandler<Game> *gameServerListPacketHandler = new PacketHandler<Game>(*this, &Game::handleGameServerList);
    network::NetworkManager::getInstance().registerPacketHandler(NetworkManager::HandlerQueue::System, 0xA8, *gameServerListPacketHandler);
}

Game::~Game() {
    
}

/* UO Handlers */

bool Game::handleLoginDenied(core::network::packet::server::ServerPacket &packet) {
    LoginDeniedPacket &deniedPacket = (LoginDeniedPacket&)packet;
    printf("[LOGIN DENIED] Reason: %s\n", deniedPacket.getReasonCStr());
    return true;
}

bool Game::handleGameServerList(core::network::packet::server::ServerPacket &packet) {
    for (auto &i : ((GameServerListPacket&)packet).getServerList()) {
        LOG_DEBUG("Server[%d]: %s, %s\n", i->index, i->name, i->full!=0 ? "full":"empty");
    }
    return true;
}
