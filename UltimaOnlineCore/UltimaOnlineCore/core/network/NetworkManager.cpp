//
//  NetworkManager.cpp
//  UltimaOnlineCore
//
//  Created by Hercules Junior on 8/3/16.
//  Copyright © 2016 Hercules Junior. All rights reserved.
//

#include "NetworkManager.h"
#import <CoreFoundation/CoreFoundation.h>
#include "Log.h"
#include "ServerPacket.h"

core::network::NetworkManager::NetworkManager() {
    _adapter = NetworkAdapter::getInstance();
}

core::network::NetworkManager::~NetworkManager() {
    for(auto &ent1 : _beforeSystemPacketHandlers) {
        ent1.second.clear();
    }
    _beforeSystemPacketHandlers.clear();
    for(auto &ent1 : _systemPacketHandlers) {
        ent1.second.clear();
    }
    _systemPacketHandlers.clear();
    for(auto &ent1 : _afterSystemPacketHandlers) {
        ent1.second.clear();
    }
    _afterSystemPacketHandlers.clear();
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

bool core::network::NetworkManager::send(core::network::packet::client::ClientPacket& packet) {
    packet.buildPacket();
    log::Log::printPacket(false, packet.getData(), packet.getLength());
    _adapter->send(packet.getData(), packet.getLength());
    return true;
}

bool core::network::NetworkManager::registerPacketHandler(HandlerQueue queue, unsigned char packetID, core::network::packet::IPacketHandler &packetHandler) {
    packet::PacketHandlerList *handlers = &_afterSystemPacketHandlers[packetID];
    switch (queue) {
        case HandlerQueue::AfterSystem:
            handlers = &_afterSystemPacketHandlers[packetID];
            break;
        case HandlerQueue::System:
            handlers = &_systemPacketHandlers[packetID];
            break;
        case HandlerQueue::BeforeSystem:
            handlers = &_beforeSystemPacketHandlers[packetID];
            break;
    }
    handlers->push_back(&packetHandler);
    packetHandler.setHandlerRegisterList(*handlers);
    return true;
}

void core::network::NetworkManager::processPacket(const unsigned char *buf, unsigned short len) {
    log::Log::printPacket(true, buf, len);
    bool ignoreNextQueue = false;
    core::network::packet::server::ServerPacket *packet = core::network::packet::server::ServerPacket::createPacket(buf, len);
    
    packet::PacketHandlerList &handlers = _beforeSystemPacketHandlers[buf[0]&0xff];
    for(auto &handle : handlers) {
        ignoreNextQueue = !handle->handlePacket(*packet) | false;
    }
    if (!ignoreNextQueue) {
        handlers = _systemPacketHandlers[buf[0]&0xff];
        for(auto &handle : handlers) {
            ignoreNextQueue = !handle->handlePacket(*packet) | false;
        }
    }
    if (!ignoreNextQueue) {
        handlers = _afterSystemPacketHandlers[buf[0]&0xff];
        for(auto &handle : handlers) {
            ignoreNextQueue = !handle->handlePacket(*packet) | false;
        }
    }
}
