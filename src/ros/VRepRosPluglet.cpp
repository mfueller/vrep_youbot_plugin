/*
 * LaserScanPublisher.cpp
 *
 *  Created on: Jan 4, 2013
 *      Author: matthias
 */


#include "vrep_plugin/ros/VRepRosPluglet.h"

#include "sensor_msgs/LaserScan.h"

#include "v_repLib.h"

namespace vrep {


VRepRosPluglet::VRepRosPluglet() : vrep::VRepPluglet(), nodeHandle() {

}

VRepRosPluglet::~VRepRosPluglet() {

}

bool VRepRosPluglet::is_active() {
	return true;
}

}
