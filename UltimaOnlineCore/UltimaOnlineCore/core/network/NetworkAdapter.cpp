//
//  NetworkAdapter.cpp
//  UltimaOnlineCore
//
//  Created by Hercules Junior on 8/4/16.
//  Copyright © 2016 Hercules Junior. All rights reserved.
//

#include "NetworkAdapter.h"
#include "NetworkAdapteriOS.h"

#include "easylogging++.h"

#define MIN_DECBUF_SIZE(in) ((in * 4) + 4)

core::network::NetworkAdapter* core::network::NetworkAdapter::getInstance() {
    static platforms::NetworkAdapteriOS instance;
    return (NetworkAdapter*)&instance;
}

core::network::NetworkAdapter::NetworkAdapter() {
    _connected = false;
}

void core::network::NetworkAdapter::clean() {
    DecompressClean(&_huffObj);
}

void core::network::NetworkAdapter::parsePacket(unsigned char *buf, unsigned int length) {
    this->logPacket(buf, length);
    int outbyt=0;
    char *dcbuf = (char *)malloc(MIN_DECBUF_SIZE(length));
    int len = length;
    Decompress(dcbuf, (char*)buf, &outbyt, &len, &_huffObj); // Descomprimir
    memcpy(buf, dcbuf, outbyt); // Copiar buf descomprimido
    free(dcbuf); // Liberar buf descomprimido
}

void core::network::NetworkAdapter::logPacket(const unsigned char *pBuffer, unsigned int length) {
    int actLine = 0, actRow = 0;
    printf("       0  1  2  3  4  5  6  7  8  9  A  B  C  D  E  F\n");
    printf("      -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --\n");
    for(actLine = 0; actLine < (length / 16) + 1; actLine++) {
        printf("%04x: ", actLine * 16);
        for(actRow = 0; actRow < 16; actRow++) {
            if(actLine * 16 + actRow < length) {
                printf("%02x ", (unsigned int)((unsigned char)pBuffer[actLine * 16 + actRow]));
            } else {
                printf("-- ");
            }
        }
        printf(": ");
        for(actRow = 0; actRow < 16; actRow++) {
            if(actLine * 16 + actRow < length) {
                printf("%c", isprint(pBuffer[actLine * 16 + actRow]) ? pBuffer[actLine * 16 + actRow] : '.');
            }
        }
        printf("\n");
    }
    return;
}
