//
//  NetworkManager.cpp
//  UltimaOnlineCore
//
//  Created by Hercules Junior on 8/3/16.
//  Copyright © 2016 Hercules Junior. All rights reserved.
//

#include "NetworkManager.h"
#import <CoreFoundation/CoreFoundation.h>

#include "easylogging++.h"

INITIALIZE_EASYLOGGINGPP

core::network::NetworkManager::NetworkManager() {
    _adapter = NetworkAdapter::getInstance();
}

core::network::NetworkManager::~NetworkManager() {
}

core::network::NetworkManager& core::network::NetworkManager::getInstance() {
    static NetworkManager instance; // Guaranteed to be destroyed.
    // Instantiated on first use.
    return instance;
}

bool core::network::NetworkManager::connect(const char* host, int port) {
    _adapter->clean();
    _adapter->connect(host, port);
    return true;
}

bool core::network::NetworkManager::send(core::network::packet::Packet& packet) {
    packet.buildPacket();
    _adapter->logPacket(packet.getData(), packet.getLength());
    _adapter->send(packet.getData(), packet.getLength());
    return true;
}

bool core::network::NetworkManager::registerPacketHandler(HandlerQueue queue, unsigned char packetID, core::network::packet::IPacketHandler &packetHandler) {
    PacketHandlerList &handlers = _afterSystemPacketHandlers[packetID];
    switch (queue) {
        case HandlerQueue::AfterSystem:
            handlers = _afterSystemPacketHandlers[packetID];
            break;
        case HandlerQueue::System:
            handlers = _systemPacketHandlers[packetID];
            break;
        case HandlerQueue::BeforeSystem:
            handlers = _beforeSystemPacketHandlers[packetID];
            break;
    }
    handlers.push_back(&packetHandler);
    packetHandler.setHandlerRegisterList(handlers);
    return true;
}