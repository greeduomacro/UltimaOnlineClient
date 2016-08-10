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
            class PacketHandler : public IPacketHandler {
            public:
                /* delegate method signature
                 @return TRUE if wants to process packet in others QUEUES, otherwise FALSE */
                typedef bool (T::*Operation)(core::network::packet::Packet &packet);
                
                PacketHandler(T& target, Operation operation) : _target(target) , _operation(operation) {
                    _registerList = nullptr;
                }
                
                virtual bool handlePacket(core::network::packet::Packet &packet) {
                    return (_target.*_operation)(packet);
                }
                
                virtual void setHandlerRegisterList(PacketHandlerList &registerList) {
                    _registerList = &registerList;
                }
                
                virtual bool deregisterHandler() {
                    if (this->_registerList != nullptr) {
                        auto endInterator = this->_registerList->end();
                        auto i = std::find(this->_registerList->begin(), endInterator, this);
                        if (i != endInterator) {
                            this->_registerList->erase(i);
                            return true;
                        }
                    }
                    return false;
                }
                
//                friend inline bool operator==(const IPacketHandler &a, const PacketHandler<T>& that){
//                    const PacketHandler<T> &obj = dynamic_cast<const PacketHandler<T>&>(a);
//                    return obj == that;
//                }
//                
//                inline bool operator==(const PacketHandler<T>& that){
//                    return &this->_target == &that._target &&
//                        &this->_operation == &that._operation &&
//                        this->_registerList == that._registerList;
//                }
//                inline bool operator!=(const PacketHandler<T>& that){
//                    return !(this == that);
//                }
            private:
                T& _target;
                Operation _operation;
                PacketHandlerList *_registerList;
            };
        }
    }
}

#endif /* CORE_NETWORK_PACKET_PACKETHANDLER_H */
