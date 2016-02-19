/*
 * ClockPublisher.cpp
 *
 *  Created on: Jan 4, 2013
 *      Author: matthias
 */

#include "vrep_plugin/ros/callback/ClockCallback.h"

#include "vrep_plugin/ros/pluglet/ClockPluglet.h"
#include "vrep_plugin/VRepPlugletRegistry.h"

#include "ros/ros.h"

#include "v_repConst.h"
#include "rosgraph_msgs/Clock.h"

#include "v_repLib.h"

namespace vrep {

ClockCallback* ClockCallback::instance = 0;



ClockCallback::~ClockCallback() {

}



void ClockCallback::luaCall(Argslist args) {

	if (args.size() < 1) {
		ROS_ERROR("Not enough arguments for v-rep clock publisher");
		return;
	}

	
	ClockPluglet* pluglet = new ClockPluglet();
	pluglet->setTopicName(boost::any_cast<std::string>(args[0]));

	vrep::VRepPlugletRegistry::getInstance()->getPluglets().push_back(pluglet);

}

GenericLuaCallback::LuaDescription ClockCallback::getDescription() {
	GenericLuaCallback::LuaDescription d;

	d.name = "rosCreateClockPubslisher";
	d.tooltip = "rosCreateClockPubslisher(string topicName)";
	d.argTypes[0] = 1;
	d.argTypes[1] = sim_lua_arg_string;
	d.argTypes[2] = 0;

	return d;
}

}
