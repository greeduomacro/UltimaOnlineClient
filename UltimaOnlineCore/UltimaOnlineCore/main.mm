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
#include "core/network/packet/LoginRequestPacket.h"

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    core::network::NetworkManager &networkManager = core::network::NetworkManager::getInstance();
    if (networkManager.connect("server.chaosage.com.br", 5003)) {
        core::network::packet::LoginRequestPacket loginRequest("malckav", "UJuTyLEmaZU");
        networkManager.send(loginRequest);
    }
    CFRunLoopRun();
//    std::cout<<"Press ENTER to exit";
//    std::cin.ignore(std::cin.rdbuf()->in_avail()+1);
    return 0;
}
