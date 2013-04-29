/*
 * LaserScanPublisher.cpp
 *
 *  Created on: Jan 4, 2013
 *      Author: matthias
 */

#include "vrep_plugin/ros/pluglet/PointCloudPluglet.h"

#include "sensor_msgs/LaserScan.h"

#include "v_repLib.h"

#include "sensor_msgs/Image.h"
#include "sensor_msgs/image_encodings.h"
#include "sensor_msgs/PointCloud2.h"

#include "cv_bridge/cv_bridge.h"

#include "pcl/point_cloud.h"
#include "pcl/ros/conversions.h"
#include "pcl/io/pcd_io.h"
#include "pcl/point_types.h"


namespace vrep {

PointCloudPluglet::PointCloudPluglet() : VRepRosPluglet() {
	visionHandle = 0;
}

PointCloudPluglet::~PointCloudPluglet() {

}

void PointCloudPluglet::v_repSimStarts_callback() {

	publisher =  nodeHandle.advertise<sensor_msgs::PointCloud2>(topicName, 1);

}


void PointCloudPluglet::v_repMessage_callback() {
	if (simGetSimulationState() != sim_simulation_advancing_running) {
		return;
	}


	if (visionHandle < 0) {
		return;
	}

	int res[2];

	simGetVisionSensorResolution(visionHandle, res);

	simFloat* buffer = simGetVisionSensorDepthBuffer(visionHandle);


	unsigned int resX = res[0];
	unsigned int resY = res[1];
	float pAngle = 57.0 / 180 * M_PI;

	float rangeMin = 0.01;
	float rangeMax = 3.5;

	//float fx = 25.0;
	//float fy = 26.5;

	pcl::PointCloud<pcl::PointXYZ> cloud;
	//pcl::fromROSMsg (buffer, cloud);

	for (unsigned int x = 0; x < resX; x++) {
		for (unsigned int y = 0; y < resY; y++) {
			float depth = rangeMin + buffer[x * resY + y] * rangeMax;

			if (depth < rangeMax - 0.01) {

				float ax = ((((float) x) - resX / 2.0) / resX) * pAngle;
				float ay = -((((float) y) - resY / 2.0) / resY) * pAngle;

				float px = sin(ax) * depth / 0.8875;
				float py = sin(ay) * depth / 0.8875;
				float pz = depth;

				pcl::PointXYZ p;
				p.x = py;
				p.y = px;
				p.z = pz;

				cloud.points.push_back(p);

			} else {
				//nothing
			}
		}
	}

	sensor_msgs::PointCloud2 pc;

	pcl::toROSMsg(cloud, pc);

	pc.header.stamp = ros::Time::now();
	pc.header.frame_id = frame_id;

	publisher.publish(pc);

}

void PointCloudPluglet::v_repSimEnds_callback() {

}


void PointCloudPluglet::v_repStart_callback() {

}

void PointCloudPluglet::v_repEnd_callback() {

}

void PointCloudPluglet::init() {

}

} /* namespace vrep */
