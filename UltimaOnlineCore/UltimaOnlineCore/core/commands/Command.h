/*
 * Command.h
 *
 *  Created on: Apr 23, 2016
 *      Author: herculesjr
 */

#ifndef CORE_COMMANDS_COMMAND_H_
#define CORE_COMMANDS_COMMAND_H_

namespace core {
namespace commands {

class Command {
public:

	Command() {}
	virtual ~Command() {};

	virtual const char* getName() = 0;

	virtual bool execute(int argc, const char **args) = 0;

};

} /* namespace commands */
} /* namespace core */

#endif /* CORE_COMMANDS_COMMAND_H_ */
