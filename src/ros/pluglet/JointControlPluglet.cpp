/*
 * LaserScanPublisher.cpp
 *
 *  Created on: Jan 4, 2013
 *      Author: matthias
 */

#include "vrep_plugin/ros/pluglet/JointControlPluglet.h"

#include "sensor_msgs/LaserScan.h"

#include "v_repLib.h"


JointControlPluglet::JointControlPluglet() : VRepRosPluglet() {

}

JointControlPluglet::~JointControlPluglet() {

}

void JointControlPluglet::init() {

	std::stringstream ss_pos;
	ss_pos << topicName << "/position_command";

	std::stringstream ss_vel;
	ss_vel << topicName << "/velocity_command";

	std::stringstream ss_force;
	ss_force << topicName << "/force_command";


	arm_ctl_pos_subscriber = nodeHandle.subscribe(ss_pos.str().c_str(),1,
			&JointControlPluglet::positionCallback,this);;

	arm_ctl_vel_subscriber = nodeHandle.subscribe(ss_vel.str().c_str(),1,
				&JointControlPluglet::velocityCallback,this);

	arm_ctl_torque_subscriber = nodeHandle.subscribe(ss_force.str().c_str(),1,
					&JointControlPluglet::torqueCallback,this);

}


void JointControlPluglet::v_repMessage_callback() {
	if (simGetSimulationState() != sim_simulation_advancing_running) {
		return;
	}

}

void JointControlPluglet::v_repSimEnds_callback() {

}


void JointControlPluglet::positionCallback(
		const brics_actuator::JointPositions msg) {


	//if (ctl_state != Position) {

	//ctl_state = Position;
	//}

	for (unsigned int i = 0; i < msg.positions.size(); i++) {

		if (!controlledJoint(msg.positions[i].joint_uri)) {
			continue;
		}
		int handle = simGetObjectHandle(msg.positions[i].joint_uri.c_str());

		if (handle > 0) {

			simSetObjectIntParameter(handle, 2000, 1);
			simSetObjectIntParameter(handle, 2001, 1);

			simSetJointTargetPosition(handle,
						msg.positions[i].value);

		}
	}

}

void JointControlPluglet::velocityCallback(
		const brics_actuator::JointVelocities msg) {


	//ctl_state = Velocity;
	//}

	for (unsigned int i = 0; i < msg.velocities.size(); i++) {

		if (!controlledJoint(msg.velocities[i].joint_uri)) {
			continue;
		}
		int handle = simGetObjectHandle(msg.velocities[i].joint_uri.c_str());

		if (handle > 0) {

			if (std::fabs(msg.velocities[i].value) < 0.0000001) {

				brics_actuator::JointPositions msg_single;
				msg_single.poisonStamp = msg.poisonStamp;
				brics_actuator::JointValue value = msg.velocities[i];
				value.unit = "rad";
				float dval = 0.0;
				simGetJointPosition(handles[i], &dval);
				value.value = dval;
				msg_single.positions.push_back(value);
				//positionCallback(msg_single);
				simSetObjectIntParameter(handle, 2000, 1);
				simSetObjectIntParameter(handle, 2001, 1);

				simSetJointTargetPosition(handle, dval);
			} else {

				simSetObjectIntParameter(handle, 2000, 1);
				simSetObjectIntParameter(handle, 2001, 0);
				simSetObjectIntParameter(handle, 1000, 1);

				simSetJointTargetVelocity(handle, static_cast<float>(msg.velocities[i].value));
			}
		}
	}

}

void JointControlPluglet::torqueCallback(
		const brics_actuator::JointTorques msg) {



	for (unsigned int i = 0; i < msg.torques.size(); i++) {

		if (!controlledJoint(msg.torques[i].joint_uri)) {
			continue;
		}
		int handle = simGetObjectHandle(msg.torques[i].joint_uri.c_str());

		if (handle > 0) {

			simSetObjectIntParameter(handle, 2000, 1);
			simSetObjectIntParameter(handle, 2001, 0);
			simSetObjectIntParameter(handle, 1000, 2);


			simSetJointForce(handle,
					msg.torques[i].value);
		}
	}
}

bool JointControlPluglet::controlledJoint(std::string name) {
	int handle = simGetObjectHandle(name.c_str());

	for (size_t i=0; i<handles.size(); i++) {
		if (handle == handles[i]) {
			return true;
		}
	}

	return false;
}


void JointControlPluglet::v_repStart_callback() {

}

void JointControlPluglet::v_repSimStarts_callback() {

}
void JointControlPluglet::v_repEnd_callback() {

}
