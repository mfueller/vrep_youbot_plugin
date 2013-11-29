/*
 * LaserScanCallback.cpp
 *
 *  Created on: Feb 12, 2013
 *      Author: matthias
 */

#include "vrep_plugin/ros/callback/PointCloudCallback.h"

#include "vrep_plugin/ros/pluglet/PointCloudPluglet.h"

#include "vrep_plugin/VRepPlugletRegistry.h"

namespace vrep {

PointCloudCallback* PointCloudCallback::instance = 0;

PointCloudCallback::~PointCloudCallback() {

}
void PointCloudCallback::luaCall(Argslist args) {

	if (args.size() < 3) {
		std::cout << "PointCloudCallback: not enough parameters";
		return;
	}

	std::string topic = boost::any_cast<std::string>(args[0]);
	int visionHandle = boost::any_cast<int>(args[1]);
	std::string frame_id = boost::any_cast<std::string>(args[2]);


	PointCloudPluglet* pub = new PointCloudPluglet();
	pub->setFrameId(frame_id);
	pub->setTopicName(topic);
	pub->setVisionHandle(visionHandle);

	pub->init();

	vrep::VRepPlugletRegistry::getInstance()->getPluglets().push_back(pub);
}

GenericLuaCallback::LuaDescription PointCloudCallback::getDescription() {
	GenericLuaCallback::LuaDescription d;

	d.name = "rosCreatePointCloudPubslisher";
	d.tooltip = "rosCreatePointCloudPubslisher(string topicName, int visionHandle, string frame_id)";
	d.argTypes[0] = 3;
	d.argTypes[1] = sim_lua_arg_string;
	d.argTypes[2] = sim_lua_arg_int;
	d.argTypes[3] = sim_lua_arg_string;
	d.argTypes[4] = 0;

	return d;
}






} /* namespace vrep */
