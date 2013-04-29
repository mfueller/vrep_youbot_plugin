/*
 * RosLuaCallRegistry.cpp
 *
 *  Created on: Feb 9, 2013
 *      Author: matthias
 */

#include "vrep_plugin/lua/GenericLuaFunctionRegistry.h"

#include "vrep_plugin/ros/callback/ClockCallback.h"

#include "vrep_plugin/ros/callback/LaserScanCallback.h"
#include "vrep_plugin/ros/callback/PointCloudCallback.h"
#include "vrep_plugin/ros/callback/JointControlCallback.h"

namespace vrep {

GenericLuaFunctionRegistry::GenericLuaFunctionRegistry() {

	this->callbacks.push_back(new ClockCallback());
	this->callbacks.push_back(new LaserScanCallback());
	this->callbacks.push_back(new PointCloudCallback());
	this->callbacks.push_back(new JointControlCallback());

}

GenericLuaFunctionRegistry::~GenericLuaFunctionRegistry() {

}

std::vector<GenericLuaCallback*>& GenericLuaFunctionRegistry::getCallbacks() {
	return this->callbacks;
}

} /* namespace vrep */
