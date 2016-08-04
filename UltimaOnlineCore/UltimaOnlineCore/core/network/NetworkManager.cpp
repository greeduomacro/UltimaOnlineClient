//
//  NetworkManager.cpp
//  UltimaOnlineCore
//
//  Created by Hercules Junior on 8/3/16.
//  Copyright © 2016 Hercules Junior. All rights reserved.
//

#include "NetworkManager.h"

#include "easylogging++.h"

INITIALIZE_EASYLOGGINGPP

core::network::NetworkManager::NetworkManager() {
    //init NetworkManager
}

core::network::NetworkManager::~NetworkManager() {
    
}

core::network::NetworkManager& core::network::NetworkManager::getInstance() {
    static NetworkManager instance; // Guaranteed to be destroyed.
    // Instantiated on first use.
    return instance;
}

bool core::network::NetworkManager::connect(const char* host, int port) {
    LOG(INFO) << "Connecting...";
    return true;
}

bool core::network::NetworkManager::send(core::network::packet::Packet& packet) {
    return true;
}