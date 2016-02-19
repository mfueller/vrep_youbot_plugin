/*
 * LaserScanPublisher.h
 *
 *  Created on: Jan 4, 2013
 *      Author: matthias
 */

#ifndef CLOCKPLUGLET_H_
#define CLOCKPLUGLET_H_

#include "brics_actuator/JointPositions.h"
#include "brics_actuator/JointVelocities.h"
#include "brics_actuator/JointTorques.h"

#include "vrep_plugin/VRepPluglet.h"

namespace vrep {
class ClockPluglet : public VRepPluglet {
protected:

	ros::Publisher publisher;

	std::string topicName;

	std::vector<int> handles;

public:

	ClockPluglet();

	virtual ~ClockPluglet();

	void init();

	void v_repStart_callback();

	void v_repMessage_callback();

	void v_repEnd_callback();

	void v_repSimStarts_callback();

	void v_repSimEnds_callback();

	bool is_active() {
	  return true;
	}
	const std::string& getTopicName() const {
		return topicName;
	}

	void setTopicName(const std::string& topicName) {
		this->topicName = topicName;
	}

	void setHandles(int r1, int r2, int r3, int r4) {
		handles.clear();
		handles.push_back(r1);
		handles.push_back(r2);
		handles.push_back(r3);
		handles.push_back(r4);

	}
};
}
#endif /* LASERSCANPUBLISHER_H_ */
