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
#include "Log.h"

#define MIN_DECBUF_SIZE(in) ((in * 4) + 4)

core::network::NetworkAdapter* core::network::NetworkAdapter::getInstance() {
    static platforms::NetworkAdapteriOS instance;
    return (NetworkAdapter*)&instance;
}

core::network::NetworkAdapter::NetworkAdapter() {
    _connected = false;
    DecompressClean(&huffmanObj);
}

void core::network::NetworkAdapter::clean() {

}

void core::network::NetworkAdapter::parsePacket(const uint8_t *buf, unsigned int length) {
    static uint8_t recvBuf[15000] = {0};
    static int recvBufLen = 0;
    static uint8_t *pnow=recvBuf;
    static bool partialPacket = false;
    static int i = 2;
    int outbyt = 0;
    int l = length;
    if (i-- <= 0) {
        char *dcbuf = (char *)malloc(MIN_DECBUF_SIZE(length));
        Decompress(dcbuf, (char*)buf, &outbyt, &l, &huffmanObj); // Descomprimir
        memcpy((char*)buf, dcbuf, outbyt); // Copiar buf descomprimido
        free(dcbuf); // Liberar buf descomprimido
        
        log::Log::printInfo("[parsePacket::HUFFMAN] Decompressed %u bytes into %u bytes\n", l, outbyt);
        recvBufLen += outbyt;
        memcpy(pnow, buf, outbyt);
    } else {
        recvBufLen += length;
        memcpy(pnow, buf, length);
    }
    
    
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
