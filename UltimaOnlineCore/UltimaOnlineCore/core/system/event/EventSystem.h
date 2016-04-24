/*
 * EventSystem.h
 *
 *  Created on: Apr 22, 2016
 *      Author: herculesjr
 */

#ifndef CORE_SYSTEM_EVENT_EVENTSYSTEM_H_
#define CORE_SYSTEM_EVENT_EVENTSYSTEM_H_

#include <list>
#include <unordered_map>
#include <typeindex>

#include "Event.h"
#include "EventHandler.h"
#include "HandlerRegistration.h"

namespace core {
namespace system {
namespace event {

class EventSystem {
public:
	EventSystem() {}
	virtual ~EventSystem() {};

	void postEvent(event::Event &event) {
		Registrations* registrations = handlers[typeid(event)];

		// If the registrations list is null, then no handlers have been registered for this event
		if (registrations == nullptr) {
			return;
		}

		// Iterate through all the registered handlers and dispatch to each one if the sender
		// matches the source or if the sender is not specified
		for (auto & reg : *registrations) {
			if ((reg->getSender() == nullptr) || (reg->getSender() == &event.getSender())) {

				// This is where some magic happens. The void * handler is statically cast to an event handler
				// of generic type Event and dispatched. The dispatch function will then do a dynamic
				// cast to the correct event type so the matching onEvent method can be called
				static_cast<event::EventHandler<event::Event>*>(reg->getHandler())->dispatch(event);
			}
		}
	}

	template <class T>
	bool const addEventHandler(event::EventHandler<T> &handler, Object &sender) {
		// Fetch the list of event pairs unique to this event type
		Registrations* registrations = handlers[typeid(T)];

		// Create a new collection instance for this type if it hasn't been created yet
		if (registrations == nullptr) {
			registrations = new Registrations();
			handlers[typeid(T)] = registrations;
		}

		EventRegistration* registration = new EventRegistration(static_cast<void*>(&handler), registrations, &sender);

		// Add the registration object to the collection
		registrations->push_back(registration);

		return registration;
	}

	template <class T>
		bool const addEventHandler(event::EventHandler<T> &handler) {
			// Fetch the list of event pairs unique to this event type
			Registrations* registrations = handlers[typeid(T)];

			// Create a new collection instance for this type if it hasn't been created yet
			if (registrations == nullptr) {
				registrations = new Registrations();
				handlers[typeid(T)] = registrations;
			}

			EventRegistration* registration = new EventRegistration(static_cast<void*>(&handler), registrations);

			// Add the registration object to the collection
			registrations->push_back(registration);

			return registration;
		}

private:
	class EventRegistration : public event::HandlerRegistration {
	public:
		typedef std::list<EventRegistration*> Registrations;

		/**
		 * \brief Represents a registration object for a registered event handler
		 *
		 * This object is stored in a collection with other handlers for the event type.
		 *
		 * @param handler The event handler
		 * @param registrations The handler collection for this event type
		 * @param sender The registered sender object
		 */
		EventRegistration(void * const handler, Registrations * const registrations, Object * const sender = 0 ) :
			handler(handler),
			registrations(registrations),
			sender(sender),
			registered(true)
		{ }


		/**
		 * \brief Empty virtual destructor
		 */
		virtual ~EventRegistration() { }


		/**
		 * \brief Gets the event handler for this registration
		 *
		 * @return The event handler
		 */
		void * const getHandler() {
			return handler;
		}


		/**
		 * \brief Gets the sender object for this registration
		 *
		 * @return The registered sender object
		 */
		Object* const getSender() {
			return sender;
		}


		/**
		 * \brief Removes an event handler from the registration collection
		 *
		 * The event handler will no longer receive events for this event type
		 */
		virtual void removeHandler() {
			if (registered) {
				registrations->remove(this);
				registered = false;
			}
		}

	private:
		void * const handler;
		Registrations* const registrations;
		Object* const sender;

		bool registered;
	};

	typedef std::list<EventRegistration*> Registrations;
	typedef std::unordered_map<std::type_index, std::list<EventRegistration*>*> TypeMap;

	TypeMap handlers;
};

}
} /* namespace system */
} /* namespace core */

#endif /* CORE_SYSTEM_EVENT_EVENTSYSTEM_H_ */
