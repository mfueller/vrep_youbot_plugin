/*
 * LaserScanPublisher.cpp
 *
 *  Created on: Jan 4, 2013
 *      Author: matthias
 */

#include "vrep_plugin/ros/pluglet/ClockPluglet.h"

#include "sensor_msgs/LaserScan.h"

#include "v_repLib.h"

#include "rosgraph_msgs/Clock.h"

namespace vrep {

ClockPluglet::ClockPluglet() : VRepPluglet() {

}

ClockPluglet::~ClockPluglet() {

}

void ClockPluglet::init() {

}

void ClockPluglet::v_repStart_callback() {

}

void ClockPluglet::v_repMessage_callback() {
	float simtime = simGetSimulationTime();
	rosgraph_msgs::Clock rosclock;

	ros::Time time;
	time.sec = simtime;
	time.nsec = (simtime - ((int) simtime)) * 1000000;

	rosclock.clock = time;

	publisher.publish(rosclock);
}

void ClockPluglet::v_repEnd_callback() {

}

void ClockPluglet::v_repSimStarts_callback() {
	if (publisher.getTopic().length() > 0) {
		return;
	}
	ros::NodeHandle nodeHandle;
	publisher =  nodeHandle.advertise<rosgraph_msgs::Clock>(this->topicName, 1);

}

void ClockPluglet::v_repSimEnds_callback() {
	publisher.shutdown();
}

}
