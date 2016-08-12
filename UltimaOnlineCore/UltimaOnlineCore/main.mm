//
//  main.cpp
//  UltimaOnlineCore
//
//  Created by Hercules Junior on 1/16/16.
//  Copyright © 2016 Hercules Junior. All rights reserved.
//

#include <iostream>
#include <unordered_map>
#include <CoreFoundation/CoreFoundation.h>
#include "core/network/NetworkManager.h"
#include "core/network/packet/LoginSeedPacket.h"
#include "core/network/packet/LoginRequestPacket.h"
#include "core/game/Game.h"

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    core::network::NetworkManager &networkManager = core::network::NetworkManager::getInstance();
    core::game::Game &game = core::game::Game::getInstance();
    if (networkManager.connect("10.0.1.11", 2593)) {
        core::network::packet::LoginSeedPacket loginSeed("127.0.0.1");
        networkManager.send(loginSeed);
        core::network::packet::LoginRequestPacket loginRequest("", "admin");
        networkManager.send(loginRequest);
    }
//    CFRunLoopRun();
    std::cin.ignore(std::cin.rdbuf()->in_avail()+1);
    return 0;
}
