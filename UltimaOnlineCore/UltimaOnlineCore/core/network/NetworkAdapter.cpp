//
//  NetworkAdapter.cpp
//  UltimaOnlineCore
//
//  Created by Hercules Junior on 8/4/16.
//  Copyright © 2016 Hercules Junior. All rights reserved.
//

#include "NetworkAdapter.h"
#include "NetworkAdapteriOS.h"

core::network::NetworkAdapter* core::network::NetworkAdapter::createNetworkAdapter() {
    return (NetworkAdapter*)new platforms::NetworkAdapteriOS();
}
