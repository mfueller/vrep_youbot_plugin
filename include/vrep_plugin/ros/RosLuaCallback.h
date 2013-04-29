/*
 * RosLuaCallback.h
 *
 *  Created on: Apr 29, 2013
 *      Author: matthias
 */

#ifndef ROSLUACALLBACK_H_
#define ROSLUACALLBACK_H_

#include "vrep_plugin/lua/GenericLuaCallback.h"

#include "ros/ros.h"

namespace vrep {
class RosLuaCallback : public GenericLuaCallback {
protected:
	//ros::NodeHandle* nodeHandle;

public:
	RosLuaCallback();
	virtual ~RosLuaCallback();

	virtual void luaCall(Argslist args) = 0;

	virtual LuaDescription getDescription() = 0;

	virtual callBackPtr getPointer() = 0;
};
}
#endif /* ROSLUACALLBACK_H_ */
