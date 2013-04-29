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

class LaserScanPluglet : public VRepRosPluglet {
protected:

	int tubeHandle;
	std::string frame_id;
	std::string tubeName;
	std::string topic;

	ros::Publisher publisher;

public:

	LaserScanPluglet();

	virtual ~LaserScanPluglet();

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

	const std::string& getTopic() const {
		return topic;
	}

	void setTopic(const std::string& topic) {
		this->topic = topic;
	}

	int getTubeHandle() const {
		return tubeHandle;
	}

	void setTubeHandle(int tubeHandle) {
		this->tubeHandle = tubeHandle;
	}

	const std::string& getTubeName() const {
		return tubeName;
	}

	void setTubeName(const std::string& tubeName) {
		this->tubeName = tubeName;
	}
};

} /* namespace vrep */
#endif /* LASERSCANPUBLISHER_H_ */
