/*
 * Event.h
 *
 *  Created on: Apr 22, 2016
 *      Author: herculesjr
 */

#ifndef CORE_SYSTEM_EVENT_EVENT_H_
#define CORE_SYSTEM_EVENT_EVENT_H_

#include <typeindex>
#include <typeinfo>
#include <vector>
#include <stdexcept>
#include "../../Object.h"

namespace core {
namespace system {
namespace event {
class Event: public Object {
public:
	Event(Object & sender) :
		sender(sender),
		canceled(false) {
	}
	virtual ~Event();

	bool isCanceled() const {
		return canceled;
	}

	void setCanceled(bool canceled) {
		this->canceled = canceled;
	}

	Object & getSender() {
		return sender;
	}

private:
	Object & sender;
	bool canceled;
};
}
} /* namespace system */
} /* namespace core */

#endif /* CORE_SYSTEM_EVENT_EVENT_H_ */
