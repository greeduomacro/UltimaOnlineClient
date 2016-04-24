/*
 * ExitCommand.h
 *
 *  Created on: Apr 23, 2016
 *      Author: herculesjr
 */

#ifndef CORE_COMMANDS_EXITCOMMAND_H_
#define CORE_COMMANDS_EXITCOMMAND_H_

#include "Command.h"

namespace core {
namespace commands {

class ExitCommand: public Command {
public:
	ExitCommand();
	virtual ~ExitCommand();
	const char* getName();
	bool execute(int argc, const char **args);
};

} /* namespace commands */
} /* namespace core */

#endif /* CORE_COMMANDS_EXITCOMMAND_H_ */
