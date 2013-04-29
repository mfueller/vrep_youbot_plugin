/*
 * ClockPublisher.h
 *
 *  Created on: Jan 4, 2013
 *      Author: matthias
 */

#ifndef JOINTCONTROLCALLBACK_H_
#define JOINTCONTROLCALLBACK_H_

#include "vrep_plugin/ros/RosLuaCallback.h"
#include "vrep_plugin/ros/callback/JointControlCallback.h"



class JointControlCallback : public vrep::RosLuaCallback {
protected:

public:
	JointControlCallback() : RosLuaCallback(){
		JointControlCallback::instance = this;
	}
	virtual ~JointControlCallback();

	void luaCall(Argslist args);

	GenericLuaCallback::LuaDescription getDescription();

	LUA_CALLBACK(JointControlCallback);



};

#endif /* CLOCKPUBLISHER_H_ */
