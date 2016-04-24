/*
 * ExitCommand.cpp
 *
 *  Created on: Apr 23, 2016
 *      Author: herculesjr
 */

#include <iostream>
#include "ExitCommand.h"

namespace core {
namespace commands {

ExitCommand::ExitCommand() {
	// TODO Auto-generated constructor stub

}

ExitCommand::~ExitCommand() {
	// TODO Auto-generated destructor stub
}

const char* ExitCommand::getName() {
	return "exit";
}

bool ExitCommand::execute(int argc, const char **args) {
	exit(0);
	return true;
}

} /* namespace commands */
} /* namespace core */
