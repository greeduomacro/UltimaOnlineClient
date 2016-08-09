//
//  NetworkAdapteriOS.cpp
//  UltimaOnlineCore
//
//  Created by Hercules Junior on 8/4/16.
//  Copyright © 2016 Hercules Junior. All rights reserved.
//

#include "NetworkAdapteriOS.h"
#include "easylogging++.h"
#include "LoginRequestPacket.h"
#include "NetworkManager.h"

static CFReadStreamRef *readStream;
static CFWriteStreamRef *writeStream;

static void readCallBack(CFReadStreamRef stream, CFStreamEventType event, void *info) {
    switch(event) {
        case kCFStreamEventOpenCompleted: {
            ((core::platforms::NetworkAdapteriOS*)core::network::NetworkAdapter::getInstance())->setReadStreamOpened(true);
            break;
        }
        case kCFStreamEventHasBytesAvailable: {
            unsigned char buf[NETWORK_BUFSIZE];
            int len = (int)CFReadStreamRead(stream, buf, NETWORK_BUFSIZE);
            while (len > 0) {
                core::network::NetworkAdapter::getInstance()->parsePacket(buf, len);
                len = (int)CFReadStreamRead(stream, buf, NETWORK_BUFSIZE);
            }
            break;
        }
        case kCFStreamEventErrorOccurred:
            NSLog(@"A Read Stream Error Has Occurred!");
            break;
        case kCFStreamEventEndEncountered:
            NSLog(@"A Read Stream Event End!");
            break;
        default:
            break;
    }
}

static void writeCallBack(CFWriteStreamRef stream, CFStreamEventType event, void *info) {
    switch(event) {
        case kCFStreamEventOpenCompleted:
            ((core::platforms::NetworkAdapteriOS*)core::network::NetworkAdapter::getInstance())->setWriteStreamOpened(true);
            break;
        case kCFStreamEventCanAcceptBytes: {
            break;
        }
        case kCFStreamEventErrorOccurred:
            NSLog(@"A Read Stream Error Has Occurred!");
            break;
        case kCFStreamEventEndEncountered:
            NSLog(@"A Read Stream Event End!");
            break;
        default:
            break;
    }
}

core::platforms::NetworkAdapteriOS::NetworkAdapteriOS() {
}

bool core::platforms::NetworkAdapteriOS::connect(const char* host, unsigned int port) {
    
    networkQueue = dispatch_queue_create("network", DISPATCH_QUEUE_SERIAL);
    CFStreamCreatePairWithSocketToHost(NULL, (__bridge CFStringRef)[NSString stringWithUTF8String:host], port, &_readStream, &_writeStream);
    
    CFStreamClientContext readContext = {
        0,
        _readStream,
        (void *(*)(void *info))CFRetain,
        (void (*)(void *info))CFRelease,
        (CFStringRef (*)(void *info))CFCopyDescription
    };
    
    CFStreamClientContext writeContext = {
        0,
        _writeStream,
        (void *(*)(void *info))CFRetain,
        (void (*)(void *info))CFRelease,
        (CFStringRef (*)(void *info))CFCopyDescription
    };
    
    CFOptionFlags readEvents = kCFStreamEventOpenCompleted | kCFStreamEventHasBytesAvailable | kCFStreamEventErrorOccurred | kCFStreamEventEndEncountered;
    CFOptionFlags writeEvents = kCFStreamEventOpenCompleted | kCFStreamEventCanAcceptBytes| kCFStreamEventEndEncountered |
    kCFStreamEventErrorOccurred ;
    
    
    if(CFReadStreamSetClient(_readStream, readEvents, readCallBack, &readContext)) {
        CFReadStreamSetDispatchQueue(_readStream, networkQueue);
    }
    
    if (!CFReadStreamOpen(_readStream)) {
        /* error handling */
        NSLog(@"A Read Stream Event End!");
    }
    
    CFWriteStreamSetClient(_writeStream, writeEvents, writeCallBack, &writeContext);
    CFWriteStreamSetDispatchQueue(_writeStream, networkQueue);
    if (!CFWriteStreamOpen(_writeStream)) {
        NSLog(@"A Write Stream Event End!");
    }
    
    writeStream = &_writeStream;
    readStream = &_readStream;
    
    std::unique_lock<std::mutex> lck(mtx);
    while(!_readStreamOpened && !_writeStreamOpened) { cv.wait(lck); }
    
    _connected = true;
    
    return true;
}

bool core::platforms::NetworkAdapteriOS::send(const unsigned char* bytes, unsigned int length) {
    dispatch_sync(networkQueue, ^{
        CFWriteStreamWrite(_writeStream, bytes, length);
    });
    return true;
}

void core::platforms::NetworkAdapteriOS::setReadStreamOpened(bool isOpen) {
    _readStreamOpened = isOpen;
    cv.notify_all();
}

bool core::platforms::NetworkAdapteriOS::getReadStreamOpened() {
    return _readStreamOpened;
}

void core::platforms::NetworkAdapteriOS::setWriteStreamOpened(bool isOpen) {
    _writeStreamOpened = isOpen;
    cv.notify_all();
}

bool core::platforms::NetworkAdapteriOS::getWriteStreamOpened() {
    return _writeStreamOpened;
}


