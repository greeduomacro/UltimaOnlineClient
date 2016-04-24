/*
 * EventHandler.h
 *
 *  Created on: Apr 22, 2016
 *      Author: herculesjr
 */

#ifndef CORE_SYSTEM_EVENT_EVENTHANDLER_H_
#define CORE_SYSTEM_EVENT_EVENTHANDLER_H_

#include <type_traits>
#include "../../Object.h"
#include "Event.h"

namespace core {
namespace system {
namespace event {

template <class T>
class EventHandler: public Object {
public:
	EventHandler() {
		// An error here indicates you're trying to implement EventHandler with a type that is not derived from Event
		static_assert(std::is_base_of<Event, T>::value, "EventHandler<T>: T must be a class derived from Event");
	}
	virtual ~EventHandler();

	virtual void onEvent(T &) = 0;

	void dispatch(Event & e) {
		onEvent(dynamic_cast<T &>(e));
	}
};

} /* namespace event */
} /* namespace system */
} /* namespace core */

#endif /* CORE_SYSTEM_EVENT_EVENTHANDLER_H_ */
