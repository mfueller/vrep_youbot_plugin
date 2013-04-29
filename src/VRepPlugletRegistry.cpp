/*
 * RosLuaCallRegistry.cpp
 *
 *  Created on: Feb 9, 2013
 *      Author: matthias
 */

#include "vrep_plugin/VRepPlugletRegistry.h"

namespace vrep {


VRepPlugletRegistry* VRepPlugletRegistry::instance = 0;

VRepPlugletRegistry::VRepPlugletRegistry() {

}

VRepPlugletRegistry::~VRepPlugletRegistry() {

}

std::vector<VRepPluglet*>& VRepPlugletRegistry::getPluglets() {
	return this->pluglets;
}

} /* namespace vrep */
