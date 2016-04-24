/*
 * HandlerRegistration.h
 *
 *  Created on: Apr 22, 2016
 *      Author: herculesjr
 */

#ifndef CORE_SYSTEM_EVENT_HANDLERREGISTRATION_H_
#define CORE_SYSTEM_EVENT_HANDLERREGISTRATION_H_

namespace core {
namespace system {
namespace event {

class HandlerRegistration: public Object {
public:
	virtual ~HandlerRegistration();

	virtual void removeHandler() = 0;
};

} /* namespace event */
} /* namespace system */
} /* namespace core */

#endif /* CORE_SYSTEM_EVENT_HANDLERREGISTRATION_H_ */
