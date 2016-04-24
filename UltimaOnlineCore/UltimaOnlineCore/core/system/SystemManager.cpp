/*
 * SystemManager.cpp
 *
 *  Created on: Apr 22, 2016
 *      Author: herculesjr
 */

#include "SystemManager.h"

namespace core {
namespace system {

SystemManager::SystemManager() {
	// TODO Auto-generated constructor stub

}

SystemManager::~SystemManager() {
	// TODO Auto-generated destructor stub
}

SystemManager& SystemManager::getInstance() {
	static SystemManager instance; // Guaranteed to be destroyed.
	// Instantiated on first use.
	return instance;
}

} /* namespace system */
} /* namespace core */
