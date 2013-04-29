/*
 * LaserScanPublisher.h
 *
 *  Created on: Jan 4, 2013
 *      Author: matthias
 */

#ifndef JOINTCONTROLPLUGLET_H_
#define JOINTCONTROLPLUGLET_H_

#include "brics_actuator/JointPositions.h"
#include "brics_actuator/JointVelocities.h"
#include "brics_actuator/JointTorques.h"

#include "vrep_plugin/ros/VRepRosPluglet.h"

class JointControlPluglet : public vrep::VRepRosPluglet {
protected:

	std::vector<int> handles;

	ros::Subscriber arm_ctl_pos_subscriber;

	ros::Subscriber arm_ctl_vel_subscriber;

	ros::Subscriber arm_ctl_torque_subscriber;

	std::string topicName;

public:

	JointControlPluglet();

	virtual ~JointControlPluglet();

	void init();

	void v_repStart_callback();

	void v_repMessage_callback();

	void v_repEnd_callback();

	void v_repSimStarts_callback();

	void v_repSimEnds_callback();

	void velocityCallback(
			const brics_actuator::JointVelocities msg);

	void positionCallback(
			const brics_actuator::JointPositions msg);

	void torqueCallback(
			const brics_actuator::JointTorques msg);

	bool controlledJoint(std::string name);

	std::vector<int>& getHandles() {
		return handles;
	}

	void setHandles(const std::vector<int>& handles) {
		this->handles = handles;
	}

	const std::string& getTopicName() const {
		return topicName;
	}

	void setTopicName(const std::string& topicName) {
		this->topicName = topicName;
	}
};

#endif /* LASERSCANPUBLISHER_H_ */
