/*
 * SystemManager.h
 *
 *  Created on: Apr 22, 2016
 *      Author: herculesjr
 */

#ifndef CORE_SYSTEM_SYSTEMMANAGER_H_
#define CORE_SYSTEM_SYSTEMMANAGER_H_

#include "event/EventSystem.h"
#include "console/ConsoleSystem.h"

namespace core {
namespace system {

class SystemManager {
public:
	SystemManager();
	virtual ~SystemManager();

	static SystemManager& getInstance();

	const event::EventSystem& getEventSystem() const {
		return eventSystem;
	}

	const console::ConsoleSystem& getConsoleSystem() const {
		return consoleSystem;
	}

private:
	console::ConsoleSystem consoleSystem;
	event::EventSystem eventSystem;
};

} /* namespace system */
} /* namespace core */

#endif /* CORE_SYSTEM_SYSTEMMANAGER_H_ */
