/*
 * SwedishBaseController.h
 *
 *  Created on: Jan 7, 2013
 *      Author: matthias
 */

#ifndef SWEDISHBASEONTROLLERPLUGLET_H_
#define SWEDISHBASEONTROLLERPLUGLET_H_


#include "geometry_msgs/Twist.h"

#include "vrep_plugin/ros/VRepRosPluglet.h"

//#include "jointcontroller/VRepJointVector.h"

namespace vrep {

class SwedishBaseControllerPluglet: public VRepRosPluglet {
protected:
	//util::VRepJointVector handles;

	float last_cmd_time;

	std::string topicName;

	ros::Subscriber subscriber;

	std::vector<int> handles;

	float R;

public:
	SwedishBaseControllerPluglet();

	virtual ~SwedishBaseControllerPluglet();

	void init();

	void v_repStart_callback();

	void v_repMessage_callback();

	void v_repEnd_callback();

	void v_repSimStarts_callback();

	void v_repSimEnds_callback();

	void initJoints();

	void cmdCallback(const geometry_msgs::Twist::ConstPtr msg);

	void heartBeat();

	const std::string& getTopicName() const {
		return topicName;
	}

	void setTopicName(const std::string& topicName) {
		this->topicName = topicName;
	}

	void setHandles(int r1, int r2, int r3, int r4) {
		this->handles.clear();
		this->handles.push_back(r1);
		this->handles.push_back(r2);
		this->handles.push_back(r3);
		this->handles.push_back(r4);

	}

	float getR() const {
		return R;
	}

	void setR(float r) {
		R = r;
	}
};

} /* namespace vrep */
#endif /* JOINTCONTROLLER_H_ */
