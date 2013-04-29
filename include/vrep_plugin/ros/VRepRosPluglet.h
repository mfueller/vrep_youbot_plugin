/*
 * LaserScanPublisher.h
 *
 *  Created on: Jan 4, 2013
 *      Author: matthias
 */

#ifndef VREPROSPLUGLET_H_
#define VREPROSPLUGLET_H_

#include "brics_actuator/JointPositions.h"
#include "brics_actuator/JointVelocities.h"
#include "brics_actuator/JointTorques.h"

#include "vrep_plugin/VRepPluglet.h"

namespace vrep {
class VRepRosPluglet : public VRepPluglet {
protected:

	ros::NodeHandle nodeHandle;

public:

	VRepRosPluglet();

	virtual ~VRepRosPluglet();

	bool is_active();

};

}
#endif /* LASERSCANPUBLISHER_H_ */
