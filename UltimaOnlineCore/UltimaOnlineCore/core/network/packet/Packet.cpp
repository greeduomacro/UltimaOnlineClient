//
//  Packet.cpp
//  UltimaOnlineCore
//
//  Created by Hercules Junior on 8/3/16.
//  Copyright © 2016 Hercules Junior. All rights reserved.
//

#include "Packet.h"
#include <limits>
#include <stdlib.h>
#include <string.h>

using namespace core::network::packet;

unsigned int Packet::getPacketLength(unsigned char packetID) {
    return packetLengths[packetID];
}

Packet::Packet(const unsigned char *packetBuffer) {
    _packetID = packetBuffer[0];
    _length = packetLengths[_packetID];
    if (_length >= PACKET_LENGTH_DYNAMIC) {
        _length = (packetBuffer[1] << 8) | packetBuffer[2];
    }
    if (_length > 0 && _length < std::numeric_limits<typeof(_length)>::max()) {
        this->createPacketData();
        memcpy(_packetData, packetBuffer, _length);
    }
}

Packet::Packet(unsigned char packetID, unsigned short length) {
    _packetID = packetID;
    _length = length;
    _packetData = nullptr;
}

void Packet::createPacketData() {
    if (_packetData != nullptr) {
        free(_packetData);
    }
    _packetData = (unsigned char*)calloc(1, _length * sizeof(unsigned char));
}

Packet::~Packet() {
    if (_packetData != nullptr) {
        free(_packetData);
    }
}

unsigned char* Packet::getData() {
    return _packetData;
}

unsigned short Packet::getLength() {
    return _length;
}
void Packet::setLength(unsigned short length) {
    _length = length;
}

void Packet::initPacket(bool fillCmd) {
    if (_length > 0 && _length < std::numeric_limits<typeof(_length)>::max()) {
        this->createPacketData();
    }
    if (fillCmd) {
        _packetData[0] = _packetID;
    }
}

int Packet::unicodeToAscii(const char *unicodeText, int Len, char *asciiText) {
    int i = 0, nonAsciiCompatible = 0;
    
    for(i = 0; i < Len; i+=2)
    {
        if(unicodeText[i] != 0x00)
            nonAsciiCompatible++;
        
        asciiText[i/2] = unicodeText[i+1];
    }
    
    asciiText[i++/2] = '\0'; /* null terminate it */
    
    return nonAsciiCompatible;
}

unsigned int Packet::unpack32(unsigned int idx) {
    unsigned char *data = _packetData+idx;
    return (data[0] << 24) | (data[1] << 16) | (data[2] << 8) | data[3];
}

unsigned short Packet::unpack16(unsigned int idx) {
    unsigned char *data = _packetData+idx;
    return (data[0] << 8) | data[1];
}

unsigned char Packet::unpack8(unsigned int idx) {
    unsigned char *data = _packetData+idx;
    return data[0];
}

void Packet::pack32(unsigned int idx, unsigned int x) {
    unsigned char *data = _packetData+idx;
    data[0] = (unsigned char)(x >> 24);
    data[1] = (unsigned char)((x >> 16) & 0xff);
    data[2] = (unsigned char)((x >> 8) & 0xff);
    data[3] = (unsigned char)(x & 0xff);
    
    return;
}

void Packet::pack16(unsigned int idx, unsigned short x) {
    unsigned char *data = _packetData+idx;
    data[0] = x >> 8;
    data[1] = x & 0xff;
    
    return;
}

void Packet::pack8(unsigned int idx, unsigned char x) {
    unsigned char *data = _packetData+idx;
    data[0] = x;
    return;
}

void Packet::packCStr(unsigned int idx, const char *data) {
    strcpy((char*)_packetData+idx, data);
}

const char* Packet::getName() {
    static const char *packetNames[256] = {
        "Create character", /* 0x00 */
        "Disconnect notification", /* 0x01 */
        "Move request", /* 0x02 */
        "Talk request", /* 0x03 */
        "GOD: God mode on/off request", /* 0x04 */
        "Attack request", /* 0x05 */
        "Double click on object", /* 0x06 */
        "Pick up object request", /* 0x07 */
        "Drop item request", /* 0x08 */
        "Single click on object|Request look", /* 0x09 */
        "Edit dynamics and statics", /* 0x0a */
        "Edit area", /* 0x0b */
        "Alter tiledata", /* 0x0c */
        "Send new NPC data to the server", /* 0x0d */
        "Edit template data", /* 0x0e */
        "Paperdoll", /* 0x0f */
        "Modify hue data", /* 0x10 */
        "Status window info", /* 0x11 */
        "Request skill/magic/action usage", /* 0x12 */
        "Equip/Unequip item", /* 0x13 */
        "Change item's Z value", /* 0x14 */
        "Follow character", /* 0x15 */
        "Request scripts list", /* 0x16 */
        "Script modifcation commands", /* 0x17 */
        "Add new script to server", /* 0x18 */
        "Modify NPC speech data", /* 0x19 */
        "Object information", /* 0x1a */
        "Login Confirm|Character location and body type", /* 0x1b */
        "Server/player speech", /* 0x1c */
        "Delete object", /* 0x1d */
        "Control animation", /* 0x1e */
        "Cause explosion", /* 0x1f */
        "Draw game player", /* 0x20 */
        "Character move reject", /* 0x21 */
        "Character move ok|Resync request", /* 0x22 */
        "Drag item", /* 0x23 */
        "Draw container", /* 0x24 */
        "Add item to container", /* 0x25 */
        "Kick player", /* 0x26 */
        "Unable to pickup object", /* 0x27 */
        "Unable to drop object|Clear square", /* 0x28 */
        "Object dropped ok", /* 0x29 */
        "Blood mode", /* 0x2a */
        "GOD: response to on/off request", /* 0x2b */
        "Resurrection menu choice", /* 0x2c */
        "Health", /* 0x2d */
        "Character worn item", /* 0x2e */
        "Fight occurring", /* 0x2f */
        "Attack granted ", /* 0x30 */
        "Attack ended", /* 0x31 */
        "GOD: Admin command", /* 0x32 */
        "Pause/resume client", /* 0x33 */
        "Get player status", /* 0x34 */
        "Get resource type", /* 0x35 */
        "Resource type data", /* 0x36 */
        "Move object", /* 0x37 */
        "Follow move", /* 0x38 */
        "Groups", /* 0x39 */
        "Update skills", /* 0x3a */
        "Buy items", /* 0x3b */
        "Items in container", /* 0x3c */
        "Ship", /* 0x3d */
        "Version retrieval", /* 0x3e */
        "Update object chunk", /* 0x3f */
        "Update terrain chunk", /* 0x40 */
        "Update tile data", /* 0x41 */
        "Update art", /* 0x42 */
        "Update animations", /* 0x43 */
        "Update hues", /* 0x44 */
        "Version ok", /* 0x45 */
        "New art work", /* 0x46 */
        "New terrain", /* 0x47 */
        "New animation", /* 0x48 */
        "New hues", /* 0x49 */
        "Destroy art", /* 0x4a */
        "Check client version", /* 0x4b */
        "Modify script names", /* 0x4c */
        "edit script file", /* 0x4d */
        "Personal light level", /* 0x4e */
        "Global light level", /* 0x4f */
        "Bulletin board header", /* 0x50 */
        "Bulleting board message", /* 0x51 */
        "Post bulleting board message", /* 0x52 */
        "Login rejected|Idle warning", /* 0x53 */
        "Play sound effect", /* 0x54 */
        "Login complete", /* 0x55 */
        "Plot course for ships", /* 0x56 */
        "Update regions", /* 0x57 */
        "Create new region", /* 0x58 */
        "Create new effect", /* 0x59 */
        "Update effect", /* 0x5a */
        "Set time of day", /* 0x5b */
        "Restart version", /* 0x5c */
        "Select character", /* 0x5d */
        "Server list", /* 0x5e */
        "Add server", /* 0x5f */
        "Remove server", /* 0x60 */
        "Delete static", /* 0x61 */
        "Move static", /* 0x62 */
        "Load area", /* 0x63 */
        "Attempt to load area request", /* 0x64 */
        "Set weather", /* 0x65 */
        "Show book page", /* 0x66 */
        "Simped", /* 0x67 */
        "Add LS script", /* 0x68 */
        "Friends", /* 0x69 */
        "Notify friend", /* 0x6a */
        "Use key", /* 0x6b */
        "Targeting cursor", /* 0x6c */
        "Play midi music", /* 0x6d */
        "Show animation", /* 0x6e */
        "Secure trading window", /* 0x6f */
        "Play graphical effect", /* 0x70 */
        "Bulleting board commands", /* 0x71 */
        "Set war/peace mode request", /* 0x72 */
        "Ping", /* 0x73 */
        "Open buy window", /* 0x74 */
        "Rename mobile", /* 0x75 */
        "New subserver", /* 0x76 */
        "Update mobile", /* 0x77 */
        "Draw object", /* 0x78 */
        "Get resource", /* 0x79 */
        "Resource data", /* 0x7a */
        "Sequence", /* 0x7b */
        "Open dialog box|Pick object", /* 0x7c */
        "Response to dialog box|Picked object", /* 0x7d */
        "GOD: Get god view data", /* 0x7e */
        "GOD: God view data", /* 0x7f */
        "Login request", /* 0x80 */
        "Login OK", /* 0x81 */
        "Login Denied", /* 0x82 */
        "Account delete character", /* 0x83 */
        "Change account password", /* 0x84 */
        "Change character response", /* 0x85 */
        "Characters list", /* 0x86 */
        "Send resources", /* 0x87 */
        "Open paperdoll", /* 0x88 */
        "Corpse clothing", /* 0x89 */
        "Edit trigger", /* 0x8a */
        "Show sign", /* 0x8b */
        "Relay to game server", /* 0x8c */
        "UNUSED PACKET 3", /* 0x8d */
        "Move character", /* 0x8e */
        "UNUSED PACKET 4", /* 0x8f */
        "Open map plot", /* 0x90 */
        "Login to game server request", /* 0x91 */
        "Update multi", /* 0x92 */
        "Open book", /* 0x93 */
        "Alter skill", /* 0x94 */
        "Dye window", /* 0x95 */
        "GOD: Monitor game", /* 0x96 */
        "Player move", /* 0x97 */
        "Alter mobile name", /* 0x98 */
        "Targeting cursor for multi", /* 0x99 */
        "Console entry prompt|Text entry", /* 0x9a */
        "Request GM assistance|Page a GM", /* 0x9b */
        "Assitance response", /* 0x9c */
        "GM Single", /* 0x9d */
        "Sell list", /* 0x9e */
        "Sell reply", /* 0x9f */
        "Select server", /* 0xa0 */
        "Update current health", /* 0xa1 */
        "Update current mana", /* 0xa2 */
        "Update current stamina", /* 0xa3 */
        "Spy on client|Hardware info", /* 0xa4 */
        "Open URL", /* 0xa5 */
        "Tips/notices window", /* 0xa6 */
        "Request tips/notices", /* 0xa7 */
        "Game servers list", /* 0xa8 */
        "List characters and starting cities", /* 0xa9 */
        "OK/Not ok to attack", /* 0xaa */
        "Gump text entry dialog", /* 0xab */
        "Gump text entry response", /* 0xac */
        "Unicode speech (eeew 12 bit!)", /* 0xad */
        "Unicode server speech", /* 0xae */
        "Death animation", /* 0xaf */
        "Generic gump dialog", /* 0xb0 */
        "Generic gump choice", /* 0xb1 */
        "Chat message", /* 0xb2 */
        "Chat text", /* 0xb3 */
        "Target object list", /* 0xb4 */
        "Chat window", /* 0xb5 */
        "Request popup help", /* 0xb6 */
        "Display popup help", /* 0xb7 */
        "Request character profile", /* 0xb8 */
        "Enable T2A/LBR features", /* 0xb9 */
        "Quest arrow", /* 0xba */
        "Ultima messenger", /* 0xbb */
        "Season change", /* 0xbc */
        "Client version message", /* 0xbd */
        "Assist version", /* 0xbe */
        "General information", /* 0xbf */
        "Play hued graphical effect", /* 0xc0 */
        "Predefined client messages", /* 0xc1 */
        "Unicode text entry", /* 0xc2 */
        "GQ request (whatever that is)", /* 0xc3 */
        "Semi visible", /* 0xc4 */
        "Invalid map", /* 0xc5 */
        "Invalid map enable", /* 0xc6 */
        "3D particle effect", /* 0xc7 */
        "Update range change", /* 0xc8 */
        "Trip time", /* 0xc9 */
        "UTrip time", /* 0xca */
        "GQ count (eeps)", /* 0xcb */
        "Text ID and string", /* 0xcc */
        "Unused packet", /* 0xcd */
        "Unknown draw?", /* 0xce */
        "IGR Account login request", /* 0xcf */
        "Configuration File", /* 0xd0 */
        "Logout status", /* 0xd1 */
        "Extended Draw game player", /* 0xd2 */
        "Extended Draw object", /* 0xd3 */
        "Open book", /* 0xd4 */
        "Bogus packet", /* 0xd5 */
        "Property list content", /* 0xd6 */
        "Fight book/system", /* 0xd7 */
        "Custom house data", /* 0xd8 */
        "Improved system info", /* 0xd9 */
        "Mahjong board dialog", /* 0xda */
        "Character transfer data", /* 0xdb */
        "Equipment Description", /* 0xdc */
        "", /* 0xdd */
        "", /* 0xde */
        "", /* 0xdf */
        "", /* 0xe0 */
        "", /* 0xe1 */
        "", /* 0xe2 */
        "", /* 0xe3 */
        "", /* 0xe4 */
        "", /* 0xe5 */
        "", /* 0xe6 */
        "", /* 0xe7 */
        "", /* 0xe8 */
        "", /* 0xe9 */
        "", /* 0xea */
        "", /* 0xeb */
        "", /* 0xec */
        "", /* 0xed */
        "", /* 0xee */
        "", /* 0xef */
        "Custom client packet", /* 0xf0 */
        "", /* 0xf1 */
        "", /* 0xf2 */
        "", /* 0xf3 */
        "", /* 0xf4 */
        "", /* 0xf5 */
        "", /* 0xf6 */
        "", /* 0xf7 */
        "", /* 0xf8 */
        "", /* 0xf9 */
        "", /* 0xfa */
        "", /* 0xfb */
        "", /* 0xfc */
        "", /* 0xfd */
        "", /* 0xfe */
        "", /* 0xff */ /* this is what the buffer returns when the socket is closed, 4 bytes */
    };
    return packetNames[_packetID];
}

Packet* Packet::createPacket(const unsigned char *packetBuffer, unsigned short length) {
    return nullptr;
}