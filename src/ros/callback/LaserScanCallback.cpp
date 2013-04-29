/*
 * LaserScanCallback.cpp
 *
 *  Created on: Feb 12, 2013
 *      Author: matthias
 */

#include "vrep_plugin/ros/callback/LaserScanCallback.h"

#include "vrep_plugin/VRepPlugletRegistry.h"
namespace vrep {

LaserScanCallback* LaserScanCallback::instance = 0;

LaserScanCallback::~LaserScanCallback() {

}
void LaserScanCallback::luaCall(Argslist args) {

	if (args.size() < 3) {
		std::cout << "LaserScanCallBack: not enough parameters";
		return;
	}

	std::string topic = boost::any_cast<std::string>(args[0]);
	std::string tubeName = boost::any_cast<std::string>(args[1]);
	std::string frame_id = boost::any_cast<std::string>(args[2]);


	LaserScanPluglet* pub = new LaserScanPluglet();
	pub->setFrameId(frame_id);
	pub->setTopic(topic);
	pub->setTubeName(tubeName);

	pub->init();

	VRepPlugletRegistry::getInstance()->getPluglets().push_back(pub);


}

GenericLuaCallback::LuaDescription LaserScanCallback::getDescription() {
	GenericLuaCallback::LuaDescription d;

	d.name = "rosCreateLaserScanPubslisher";
	d.tooltip = "rosCreateLaserScanPubslisher(string topicName, string tubeName, string frame_id)";
	d.argTypes[0] = 3;
	d.argTypes[1] = sim_lua_arg_string;
	d.argTypes[2] = sim_lua_arg_string;
	d.argTypes[3] = sim_lua_arg_string;
	d.argTypes[4] = 0;

	return d;
}






} /* namespace vrep */
