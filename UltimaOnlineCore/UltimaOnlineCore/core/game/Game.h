//
//  Game.h
//  UltimaOnlineCore
//
//  Created by Hercules Junior on 8/10/16.
//  Copyright © 2016 Hercules Junior. All rights reserved.
//

#ifndef CORE_GAME_GAME_H
#define CORE_GAME_GAME_H

#include "Packet.h"

namespace core {
    namespace game {
        class Game {
        public:
            static Game& getInstance();
        private:
            Game();
            ~Game();
            
            //Handlers
            bool handleLoginDenied(core::network::packet::Packet &packet);
        };
    }
}

#endif /* CORE_GAME_GAME_H */
