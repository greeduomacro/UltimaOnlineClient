//
//  PacketHandler.h
//  UltimaOnlineCore
//
//  Created by Hercules Junior on 8/9/16.
//  Copyright © 2016 Hercules Junior. All rights reserved.
//

#ifndef CORE_NETWORK_PACKET_PACKETHANDLER_H
#define CORE_NETWORK_PACKET_PACKETHANDLER_H

#include "Packet.h"
#include "IPacketHandler.h"
#include <vector>

namespace core {
    namespace network {
        namespace packet {
            template <class T>
            class PacketHandler : IPacketHandler {
            public:
                typedef void (T::*Operation)(core::network::packet::Packet &packet);
                
                PacketHandler(T& target, Operation operation) : _target(target) , _operation(operation) {
                }
                
                virtual bool handlePacket(core::network::packet::Packet &packet) {
                    return (_target.*_operation)(packet);
                }
                
                virtual void setHandlerRegisterList(std::vector<IPacketHandler*> &registerList) {
                    _registerList = registerList;
                }
                
                virtual bool deregisterHandler() {
                    for (int i = 0; i < _registerList.size(); ++i) {
                        if (_registerList[i] == this) {
                            _registerList.erase(i);
                            return true;
                        }
                    }
                    return false;
                }
            private:
                T& _target;
                Operation _operation;
                std::vector<IPacketHandler> &_registerList;
            };
        }
    }
}

#endif /* CORE_NETWORK_PACKET_PACKETHANDLER_H */
