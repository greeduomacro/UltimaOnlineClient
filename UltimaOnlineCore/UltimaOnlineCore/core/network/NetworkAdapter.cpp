//
//  NetworkAdapter.cpp
//  UltimaOnlineCore
//
//  Created by Hercules Junior on 8/4/16.
//  Copyright © 2016 Hercules Junior. All rights reserved.
//

#include "NetworkAdapter.h"
#include "NetworkAdapteriOS.h"
#include "Packet.h"
#include "NetworkManager.h"

core::network::NetworkAdapter* core::network::NetworkAdapter::getInstance() {
    static platforms::NetworkAdapteriOS instance;
    return (NetworkAdapter*)&instance;
}

core::network::NetworkAdapter::NetworkAdapter() {
    _connected = false;
}

void core::network::NetworkAdapter::clean() {

}

void core::network::NetworkAdapter::parsePacket(unsigned char *buf, unsigned int length) {
    static unsigned char recvBuf[15000] = {0};
    static int recvBufLen = 0;
    static unsigned char *pnow=recvBuf;
    static bool partialPacket = false;
    recvBufLen += length;
    memcpy(pnow, buf, length);
    int len = packet::Packet::getPacketLength(pnow);
    if (recvBufLen != len) {
        while(!partialPacket) {
            len = packet::Packet::getPacketLength(pnow);
            if (len <= recvBufLen && recvBufLen > 0) {
                NetworkManager::getInstance().processPacket(pnow, len);
                pnow += len;
                recvBufLen -= len;
            } else if(recvBufLen > 0) {
                partialPacket = true;
            } else {
                partialPacket = false;
            }
        }
        if(partialPacket) {
            memcpy(recvBuf, pnow, recvBufLen);
            pnow = recvBuf;
        } else {
            pnow = recvBuf;
            recvBufLen = 0;
        }
    } else {
        NetworkManager::getInstance().processPacket(pnow, recvBufLen);
        pnow = recvBuf;
        recvBufLen = 0;
    }
}
