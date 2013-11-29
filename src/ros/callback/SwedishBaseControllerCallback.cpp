/*
 * SwedishBaseControllerCallback.cpp
 *
 *  Created on: Jan 4, 2013
 *      Author: matthias
 */

#include "vrep_plugin/ros/callback/SwedishBaseControllerCallback.h"

#include "vrep_plugin/ros/pluglet/SwedishBaseControllerPluglet.h"
#include "vrep_plugin/VRepPlugletRegistry.h"

#include "ros/ros.h"

#include "v_repConst.h"
#include "rosgraph_msgs/Clock.h"

#include "v_repLib.h"

SwedishBaseControllerCallback* SwedishBaseControllerCallback::instance = 0;



SwedishBaseControllerCallback::~SwedishBaseControllerCallback() {

}



void SwedishBaseControllerCallback::luaCall(Argslist args) {

	if (args.size() < 3) {
		ROS_ERROR("Not enough arguments for v-rep swedish publisher");
		return;
	}

	vrep::SwedishBaseControllerPluglet* pluglet = new vrep::SwedishBaseControllerPluglet();
	pluglet->setTopicName(boost::any_cast<std::string>(args[0]));
	std::vector<boost::any> handles = boost::any_cast< std::vector<boost::any> >(args[1]);

	int r1 = boost::any_cast<int> (handles[0]);
	int r2 = boost::any_cast<int> (handles[1]);
	int r3 = boost::any_cast<int> (handles[2]);
	int r4 = boost::any_cast<int> (handles[3]);

	float R = boost::any_cast<float>(args[2]);

	pluglet->setHandles(r1,r2,r3,r4);


	pluglet->setR(R);

	pluglet->init();


	vrep::VRepPlugletRegistry::getInstance()->getPluglets().push_back(pluglet);
}

GenericLuaCallback::LuaDescription SwedishBaseControllerCallback::getDescription() {
	GenericLuaCallback::LuaDescription d;

	d.name = "rosCreateSwedishBaseController";
	d.tooltip = "rosCreateSwedishBaseControllerCallback(string topicName, int[] handles, float wheel_factor)";
	d.argTypes[0] = 3;
	d.argTypes[1] = sim_lua_arg_string;
	d.argTypes[2] = sim_lua_arg_table | sim_lua_arg_int;
	d.argTypes[3] = sim_lua_arg_float;
	d.argTypes[4] = 0;

	return d;
}



