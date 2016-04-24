/*
 * ConsoleSystem.h
 *
 *  Created on: Apr 23, 2016
 *      Author: herculesjr
 */

#ifndef CORE_SYSTEM_CONSOLE_CONSOLESYSTEM_H_
#define CORE_SYSTEM_CONSOLE_CONSOLESYSTEM_H_

#include <string>
#include <unordered_map>
#include "../../commands/Command.h"

namespace core {
namespace system {
namespace console {

class ConsoleSystem {
public:
	ConsoleSystem();
	virtual ~ConsoleSystem();

	bool inputRawCommand(const char* rawCommand) const;
private:
	std::unordered_map<std::string, core::commands::Command*> commandList;
};

}
} /* namespace system */
} /* namespace core */

#endif /* CORE_SYSTEM_CONSOLE_CONSOLESYSTEM_H_ */
