//
//  Log.cpp
//  UltimaOnlineCore
//
//  Created by Hercules Junior on 8/11/16.
//  Copyright © 2016 Hercules Junior. All rights reserved.
//

#include "Log.h"
#include <ctime>
#include "Packet.h"

void core::log::Log::printPacket(bool isReceiving, const unsigned char* packetBuffer, unsigned short length) {
    time_t now = time(0);
    tm *ltm = localtime(&now);
    int actLine = 0, actRow = 0;
    
    printf("[%04d-%02d-%02d %02d:%02d:%02d] ", ltm->tm_year, ltm->tm_mon, ltm->tm_mday, ltm->tm_hour, ltm->tm_min, ltm->tm_sec);
    if (isReceiving) {
        printf("[Server->Client] ");
    } else {
        printf("[Client->Server] ");
    }
    printf("\nPacket: %s - Length: %d bytes\n", core::network::packet::Packet::getPacketName(packetBuffer[0]), length);
    printf("       0  1  2  3  4  5  6  7  8  9  A  B  C  D  E  F\n");
    printf("      -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --\n");
    for(actLine = 0; actLine < (length / 16) + 1; actLine++) {
        printf("%04x: ", actLine * 16);
        for(actRow = 0; actRow < 16; actRow++) {
            if(actLine * 16 + actRow < length) {
                printf("%02x ", (unsigned int)((unsigned char)packetBuffer[actLine * 16 + actRow]));
            } else {
                printf("-- ");
            }
        }
        printf(": ");
        for(actRow = 0; actRow < 16; actRow++) {
            if(actLine * 16 + actRow < length) {
                printf("%c", isprint(packetBuffer[actLine * 16 + actRow]) ? packetBuffer[actLine * 16 + actRow] : '.');
            }
        }
        printf("\n");
    }
    printf("\n");
}