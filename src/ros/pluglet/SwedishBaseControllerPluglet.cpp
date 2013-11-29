/*
 * JointController.cpp
 *
 *  Created on: Jan 7, 2013
 *      Author: matthias
 */

#include "vrep_plugin/ros/pluglet/SwedishBaseControllerPluglet.h"

//#include "vrep_plugin/subscriber/jointcontroller/VRepJointHelper.h"

#include "v_repLib.h"

namespace vrep {

SwedishBaseControllerPluglet::SwedishBaseControllerPluglet() {



	
	last_cmd_time = -1;
}

SwedishBaseControllerPluglet::~SwedishBaseControllerPluglet() {

}

void SwedishBaseControllerPluglet::initJoints() {

}

void SwedishBaseControllerPluglet::cmdCallback(
		const geometry_msgs::Twist::ConstPtr msg) {

	initJoints();

	float factor = R;

	float forwBackVel = msg->linear.x * factor;
	float leftRightVel = -msg->linear.y * factor;
	float rotVel = -msg->angular.z * factor;

	float vel_wheel_0 = -forwBackVel - leftRightVel - rotVel;
	float vel_wheel_1 = -forwBackVel + leftRightVel - rotVel;
	float vel_wheel_2 = -forwBackVel - leftRightVel + rotVel;
y	float vel_wheel_3 = -forwBackVel + leftRightVel + rotVel;

	simSetJointTargetVelocity(handles[0],
			vel_wheel_0);
	simSetJointTargetVelocity(handles[1],
			vel_wheel_1);
	simSetJointTargetVelocity(handles[2],
			vel_wheel_2);
	simSetJointTargetVelocity(handles[3],
			vel_wheel_3);

	last_cmd_time = simGetSimulationTime();
}


void SwedishBaseControllerPluglet::v_repMessage_callback() {
	heartBeat();
}

void SwedishBaseControllerPluglet::heartBeat() {
	simFloat now = simGetSimulationTime();

	if (last_cmd_time > 0 && now > last_cmd_time + 0.5) {
		simSetJointTargetVelocity(handles[0],
				0);
		simSetJointTargetVelocity(handles[1],
				0);
		simSetJointTargetVelocity(handles[2],
				0);
		simSetJointTargetVelocity(handles[3],
				0);
		last_cmd_time = -1;
	}
}

void SwedishBaseControllerPluglet::v_repEnd_callback() {

}

void SwedishBaseControllerPluglet::v_repSimEnds_callback() {

}

void SwedishBaseControllerPluglet::v_repSimStarts_callback() {

}

void SwedishBaseControllerPluglet::init() {
	subscriber=nodeHandle.subscribe(topicName.c_str(), 1, &SwedishBaseControllerPluglet::cmdCallback,this);
}

void SwedishBaseControllerPluglet::v_repStart_callback() {

}



} /* namespace vrep */
