/*
 * ClockPublisher.cpp
 *
 *  Created on: Jan 4, 2013
 *      Author: matthias
 */

#include "vrep_plugin/ros/callback/JointControlCallback.h"

#include "ros/ros.h"

#include "v_repConst.h"
#include "rosgraph_msgs/Clock.h"

#include "v_repLib.h"

#include "vrep_plugin/ros/pluglet/JointControlPluglet.h"

JointControlCallback* JointControlCallback::instance = 0;



JointControlCallback::~JointControlCallback() {

}



void JointControlCallback::luaCall(Argslist args) {

	if (args.size() < 2) {
		ROS_ERROR("Not enough arguments for v-rep JointControlCallbackr");
		return;
	}

	std::string topicName = boost::any_cast<std::string>(args[0]);
	std::vector<boost::any> handles = boost::any_cast< std::vector<boost::any> >(args[1]);

	JointControlPluglet* sub = new JointControlPluglet();

	sub->setTopicName(topicName);

	for (size_t i=0; i< handles.size(); i++) {
		int val = boost::any_cast<int>(handles[i]);
		sub->getHandles().push_back(val);
	}

	sub->init();


}

GenericLuaCallback::LuaDescription JointControlCallback::getDescription() {
	GenericLuaCallback::LuaDescription d;

	d.name = "rosCreateJointControllerSubscriber";
	d.tooltip = "rosCreateJointControllerSubscriber(string topicBase, int[] handles)";
	d.argTypes[0] = 2;
	d.argTypes[1] = sim_lua_arg_string;
	d.argTypes[2] = sim_lua_arg_table | sim_lua_arg_int;
	d.argTypes[3] = 0;

	return d;
}


