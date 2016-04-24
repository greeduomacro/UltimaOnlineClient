/*
 * ConsoleSystem.cpp
 *
 *  Created on: Apr 23, 2016
 *      Author: herculesjr
 */

#include "ConsoleSystem.h"
#include <stdlib.h>
#include <iostream>
#include <vector>

#include "../../commands/ExitCommand.h"

namespace core {
namespace system {
namespace console {

ConsoleSystem::ConsoleSystem() {
	// TODO Auto-generated constructor stub
	core::commands::Command *command = nullptr;
	command = new core::commands::ExitCommand();
	commandList[std::string(command->getName())] = command;
}

ConsoleSystem::~ConsoleSystem() {
	// TODO Auto-generated destructor stub
}

bool ConsoleSystem::inputRawCommand(const char *rawCommand) const {
	int len = strlen(rawCommand);
	if (len == 0)
		return false;

	char *cmd = nullptr;
	int argc = 0;
	std::vector<char*> *args = new std::vector<char*>();
	bool lastSpace = true;
	int firstCharIdx = 0;
	bool tokenAvailable = false;

	core::commands::Command *command = nullptr;

	for(unsigned int i = 0; i < len; ++i) {
		if(rawCommand[i] == ' ') {
			if (!lastSpace) {
				tokenAvailable = true;
			}
			lastSpace = true;
		} else if (i+1 == len) {
			if (lastSpace) {
				firstCharIdx = i;
			}
			lastSpace = false;
			tokenAvailable = true;
		} else {
			if (lastSpace) {
				firstCharIdx = i;
			}
			lastSpace = false;
		}
		if (tokenAvailable) {
			int tokenLen = i-firstCharIdx+1;
			if (lastSpace) {
				--tokenLen;
			}
			char *token = new char[tokenLen+1];
			memset(token, '\0', tokenLen+1);
			strncpy(token, rawCommand+firstCharIdx, tokenLen);

			if (cmd == nullptr) {
				cmd = token;
				std::string str(cmd);
				try {
					command = commandList.at(str);
				} catch (const std::out_of_range& oor) {
					delete cmd;
					return false;
				}
			} else {
				char *arg = token;
				args->push_back(arg);
				++argc;
			}
			tokenAvailable = false;
		}
	}
	if (cmd)
		delete cmd;
	if (!command) {
		return false;
	}
	char **cmdArgs = new char*[args->size()];
	int i = -1;
	for (char *arg : *args) {
		cmdArgs[++i] = arg;
	}
	command->execute(args->size(), (const char**)cmdArgs);
	for (char *arg : *args)
		delete arg;
	delete[] cmdArgs;
	if (args) {
		args->clear();
		delete args;
	}
	return true;
}

}
} /* namespace system */
} /* namespace core */
