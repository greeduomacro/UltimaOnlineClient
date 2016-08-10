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

#include "LoginDeniedPacket.h"

using namespace core::game;
using namespace core::network;
using namespace core::network::packet;

Game& Game::getInstance() {
    static Game instance; // Guaranteed to be destroyed.
    // Instantiated on first use.
    return instance;
}

Game::Game() {
    PacketHandler<Game> *loginDeniedPacketHandler = new PacketHandler<Game>(*this, &Game::handleLoginDenied);
    network::NetworkManager::getInstance().registerPacketHandler(NetworkManager::HandlerQueue::System, 0x82, *loginDeniedPacketHandler);
}

Game::~Game() {
    
}

/* UO Handlers */

bool Game::handleLoginDenied(core::network::packet::Packet &packet) {
    LoginDeniedPacket &deniedPacket = (LoginDeniedPacket&)packet;
    printf("[LOGIN DENIED] Reason: %s", deniedPacket.getReasonCStr());
    return true;
}
