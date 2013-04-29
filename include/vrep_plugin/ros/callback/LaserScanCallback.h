/*
 * LaserScanCallback.h
 *
 *  Created on: Feb 12, 2013
 *      Author: matthias
 */

#ifndef LASERSCANCALLBACK_H_
#define LASERSCANCALLBACK_H_

#include "vrep_plugin/ros/RosLuaCallback.h"

#include "vrep_plugin/ros/pluglet/LaserScanPluglet.h"

namespace vrep {

class LaserScanCallback: public RosLuaCallback {
protected:


public:
	LaserScanCallback() : RosLuaCallback(){
		LaserScanCallback::instance = this;
	}

	virtual ~LaserScanCallback();

	void luaCall(Argslist args);

	GenericLuaCallback::LuaDescription getDescription();

	LUA_CALLBACK(LaserScanCallback)

};

} /* namespace vrep */
#endif /* LASERSCANCALLBACK_H_ */
