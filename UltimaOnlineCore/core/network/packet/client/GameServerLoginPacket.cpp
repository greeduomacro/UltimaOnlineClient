//
//  GameServerLoginPacket.cpp
//  UltimaOnlineCore
//
//  Created by Hercules Junior on 8/3/16.
//  Copyright © 2016 Hercules Junior. All rights reserved.
//

#include "GameServerLoginPacket.h"
#include <stdlib.h>
#include <string.h>
using namespace core::network::packet::client;

GameServerLoginPacket::GameServerLoginPacket(const char *login, const char *password, uint32_t key) : ClientPacket(0x91, 65) {
    _login = (char*)malloc(strlen(login)+1);
    strcpy(_login, login);
    
    _password = (char*)malloc(strlen(password)+1);
    strcpy(_password, password);
    
    _key = key;
}

GameServerLoginPacket::~GameServerLoginPacket() {
    free(_login);
    free(_password);
}

void GameServerLoginPacket::buildPacket() {
    Packet::initPacket();
    this->pack32(1, _key);
    this->packCStr(5, _login);
    this->packCStr(35, _password);
}

const char* GameServerLoginPacket::getLogin() {
    return _login;
}

void GameServerLoginPacket::setLogin(const char* login) {
    free(_login);
    _login = (char*)malloc(strlen(login)+1);
    strcpy(_login, login);
}

const char* GameServerLoginPacket::getPassword() {
    return _password;
}

void GameServerLoginPacket::setPassword(const char* password) {
    free(_password);
    _password = (char*)malloc(strlen(password)+1);
    strcpy(_password, password);
}

uint32_t GameServerLoginPacket::getKey() {
    return _key;
}

void GameServerLoginPacket::setKey(uint32_t key) {
    _key = key;
}