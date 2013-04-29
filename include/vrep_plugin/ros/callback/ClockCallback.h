/*
 * ClockPublisher.h
 *
 *  Created on: Jan 4, 2013
 *      Author: matthias
 */

#ifndef CLOCKCALLBACK_H_
#define CLOCKCALLBACK_H_

#include "vrep_plugin/ros/RosLuaCallback.h"

namespace vrep {

class ClockCallback : public GenericLuaCallback {
protected:

public:
	ClockCallback() : GenericLuaCallback(){
		ClockCallback::instance = this;
	}

	virtual ~ClockCallback();

	void luaCall(Argslist args);

	GenericLuaCallback::LuaDescription getDescription();

	void cleanUp();

	LUA_CALLBACK(ClockCallback);

};

}
#endif /* CLOCKPUBLISHER_H_ */
