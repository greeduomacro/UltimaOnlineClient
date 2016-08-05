//
//  LoginRequestPacket.cpp
//  UltimaOnlineCore
//
//  Created by Hercules Junior on 8/3/16.
//  Copyright © 2016 Hercules Junior. All rights reserved.
//

#include "LoginRequestPacket.h"
#include <stdlib.h>
#include <string.h>
using namespace core::network::packet;

LoginRequestPacket::LoginRequestPacket(const char *login, const char *password) : Packet(0x80, 62) {
    _login = (char*)malloc(strlen(login)+1);
    strcpy(_login, login);
    
    _password = (char*)malloc(strlen(password)+1);
    strcpy(_password, password);
}

LoginRequestPacket::~LoginRequestPacket() {
    free(_login);
    free(_password);
}

void LoginRequestPacket::buildPacket() {
    Packet::buildPacket();
    this->packCStr(1, _login);
    this->packCStr(31, _password);
    this->pack8(61, 0xFF);
}

const char* LoginRequestPacket::getLogin() {
    return _login;
}

void LoginRequestPacket::setLogin(const char* login) {
    free(_login);
    _login = (char*)malloc(strlen(login)+1);
    strcpy(_login, login);
}

const char* LoginRequestPacket::getPassword() {
    return _password;
}

void LoginRequestPacket::setPassword(const char* password) {
    free(_password);
    _password = (char*)malloc(strlen(password)+1);
    strcpy(_password, password);
}