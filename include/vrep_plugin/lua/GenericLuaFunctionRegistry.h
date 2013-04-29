/*
 * RosLuaCallRegistry.h
 *
 *  Created on: Feb 9, 2013
 *      Author: matthias
 */

#ifndef ROSLUACALLREGISTRY_H_
#define ROSLUACALLREGISTRY_H_


#include <vector>
#include "GenericLuaCallback.h"

#include "ros/ros.h"

namespace vrep {

class GenericLuaFunctionRegistry {
protected:


	std::vector<GenericLuaCallback*> callbacks;

public:
	GenericLuaFunctionRegistry();
	virtual ~GenericLuaFunctionRegistry();

	std::vector<GenericLuaCallback*>& getCallbacks();

};

} /* namespace vrep */
#endif /* ROSLUACALLREGISTRY_H_ */
