//
//  NetworkAdapteriOS.cpp
//  UltimaOnlineCore
//
//  Created by Hercules Junior on 8/4/16.
//  Copyright © 2016 Hercules Junior. All rights reserved.
//

#include "NetworkAdapteriOS.h"
#include "easylogging++.h"

static void readCallBack(CFReadStreamRef stream, CFStreamEventType event, void *info)
{
    switch(event) {
        case kCFStreamEventOpenCompleted:
            LOG(INFO) << "OPEN...";
        case kCFStreamEventHasBytesAvailable:
            LOG(INFO) << "HAS BYTES...";
            break;
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

static void writeCallBack(CFWriteStreamRef stream, CFStreamEventType event, void *info)
{
    switch(event) {
        case kCFStreamEventOpenCompleted:
            LOG(INFO) << "OPEN...";
        case kCFStreamEventCanAcceptBytes:
            LOG(INFO) << "WRITE BYTES...";
            break;
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
        CFReadStreamScheduleWithRunLoop(_readStream, CFRunLoopGetCurrent(), kCFRunLoopCommonModes);
    }
    
    if (!CFReadStreamOpen(_readStream)) {
        /* error handling */
        NSLog(@"A Read Stream Event End!");
    }
    
    CFWriteStreamSetClient(_writeStream, writeEvents, writeCallBack, &writeContext);
    CFWriteStreamScheduleWithRunLoop(_writeStream, CFRunLoopGetCurrent(), kCFRunLoopDefaultMode);
    if (!CFWriteStreamOpen(_writeStream)) {
        NSLog(@"A Read Stream Event End!");
    }
    return true;
}

bool core::platforms::NetworkAdapteriOS::send(const unsigned char* bytes, unsigned int length) {
    return CFWriteStreamWrite(_writeStream, bytes, length) != -1;
}


