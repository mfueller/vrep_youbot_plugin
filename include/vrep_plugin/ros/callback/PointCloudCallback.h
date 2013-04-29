/*
 * LaserScanCallback.h
 *
 *  Created on: Feb 12, 2013
 *      Author: matthias
 */

#ifndef POINTCLOUDCALLBACK_H_
#define POINTCLOUDCALLBACK_H_

#include "vrep_plugin/ros/RosLuaCallback.h"

#include "vrep_plugin/ros/pluglet/PointCloudPluglet.h"

namespace vrep {

class PointCloudCallback: public RosLuaCallback {
protected:


public:
	PointCloudCallback() : RosLuaCallback(){
		PointCloudCallback::instance = this;
	}

	virtual ~PointCloudCallback();

	void luaCall(Argslist args);

	GenericLuaCallback::LuaDescription getDescription();

	LUA_CALLBACK(PointCloudCallback)

};

} /* namespace vrep */
#endif /* LASERSCANCALLBACK_H_ */
