/*
 * ClockPublisher.h
 *
 *  Created on: Jan 4, 2013
 *      Author: matthias
 */

#ifndef SWEDISCHBASECONTROLLERCALLBACK_H_
#define SWEDISCHBASECONTROLLERCALLBACK_H_

#include "vrep_plugin/ros/RosLuaCallback.h"

class SwedishBaseControllerCallback : public vrep::RosLuaCallback {
protected:

public:
	SwedishBaseControllerCallback() : RosLuaCallback(){
		SwedishBaseControllerCallback::instance = this;
	}

	virtual ~SwedishBaseControllerCallback();

	void luaCall(Argslist args);

	GenericLuaCallback::LuaDescription getDescription();

	void cleanUp();

	LUA_CALLBACK(SwedishBaseControllerCallback);



};

#endif /* CLOCKPUBLISHER_H_ */
