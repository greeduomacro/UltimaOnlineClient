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
    _adapter = NetworkAdapter::createNetworkAdapter();
}

core::network::NetworkManager::~NetworkManager() {
    delete _adapter;
}

core::network::NetworkManager& core::network::NetworkManager::getInstance() {
    static NetworkManager instance; // Guaranteed to be destroyed.
    // Instantiated on first use.
    return instance;
}

bool core::network::NetworkManager::connect(const char* host, int port) {
    LOG(INFO) << "Connecting...";
    _adapter->connect(host, port);
    return true;
}

bool core::network::NetworkManager::send(core::network::packet::Packet& packet) {
    packet.buildPacket();
    _adapter->send(packet.getData(), packet.getLength());
    return true;
}