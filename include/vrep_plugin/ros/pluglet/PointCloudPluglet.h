/*
 * LaserScanPublisher.h
 *
 *  Created on: Jan 4, 2013
 *      Author: matthias
 */

#ifndef LASERSCANPLUGLET_H_
#define LASERSCANPLUGLET_H_

#include "vrep_plugin/VRepPluglet.h"

#include "vrep_plugin/ros/VRepRosPluglet.h"

namespace vrep {

class PointCloudPluglet : public VRepRosPluglet {
protected:

	std::string topicName;
	std::string frame_id;
	int visionHandle;
	ros::Publisher publisher;

public:

	PointCloudPluglet();

	virtual ~PointCloudPluglet();

	void init();

	void v_repStart_callback();

	void v_repMessage_callback();

	void v_repEnd_callback();

	void v_repSimStarts_callback();

	void v_repSimEnds_callback();

	const std::string& getFrameId() const {
		return frame_id;
	}

	void setFrameId(const std::string& frameId) {
		frame_id = frameId;
	}

	const std::string& getTopicName() const {
		return topicName;
	}

	void setTopicName(const std::string& topicName) {
		this->topicName = topicName;
	}

	int getVisionHandle() const {
		return visionHandle;
	}

	void setVisionHandle(int visionHandle) {
		this->visionHandle = visionHandle;
	}
};

} /* namespace vrep */
#endif /* LASERSCANPUBLISHER_H_ */
