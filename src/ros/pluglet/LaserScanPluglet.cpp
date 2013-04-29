/*
 * LaserScanPublisher.cpp
 *
 *  Created on: Jan 4, 2013
 *      Author: matthias
 */

#include "vrep_plugin/ros/pluglet/LaserScanPluglet.h"

#include "sensor_msgs/LaserScan.h"

#include "v_repLib.h"

namespace vrep {

LaserScanPluglet::LaserScanPluglet() : VRepRosPluglet() {
	tubeHandle = 0;
}

LaserScanPluglet::~LaserScanPluglet() {

}

void LaserScanPluglet::init() {

	tubeHandle = simTubeOpen(tubeHandle, tubeName.c_str(),1, false);
	publisher =  nodeHandle.advertise<sensor_msgs::LaserScan>(topic,1);

}


void LaserScanPluglet::v_repMessage_callback() {
	if (simGetSimulationState() != sim_simulation_advancing_running) {
		return;
	}

	int packNumRead;
	int packNumWrite;

	simTubeStatus(tubeHandle, &packNumRead, &packNumWrite);

	if (packNumRead > 0) {
		int dlength = 0;
		float* packet = (float*)simTubeRead(tubeHandle, &dlength);

		float pos[3];

		int size = dlength / sizeof(float);

		int scan_size = size / 3;

		sensor_msgs::LaserScan scan;

		scan.header.frame_id = frame_id;

		scan.header.stamp = ros::Time::now();

		scan.angle_min = -240 * M_PI / 180 / 2;
		scan.angle_max = -scan.angle_min;

		scan.angle_increment = 2 * M_PI / 1024;
		scan.range_min = 0.05;
		scan.range_max = 4.5;

		scan.scan_time = 0.05;

		scan.intensities.resize(scan_size, 0.0);
		scan.ranges.resize(scan_size, 0.0);

		int scancounter = 0;

		//simFloat matrix[12];

		//simGetObjectMatrix(publishers[pubI].auxInt1, -1, matrix);
		//simInvertMatrix(matrix);

		for (int i=0; i<size-3; i+=3) {
			pos[0] = packet[i+0];
			pos[1] = packet[i+1];
			pos[2] = packet[i+2];


			//simTransformVector(matrix, pos);

			//std::cout << "Tubedata received: " << pos[0] << ", " << pos[1] << ", " << pos[2] << ", "  << std::endl;
			float d = sqrt(pos[0]*pos[0] + pos[1]*pos[1]);

			scan.ranges[scancounter++] = d;
		}

		publisher.publish(scan);

		simReleaseBuffer((char*)packet);
	} else {
		//std::cout << "No Tubedata received" << std::endl;

	}


}

void LaserScanPluglet::v_repSimEnds_callback() {
	simTubeClose(tubeHandle);
	tubeHandle= 0;
	std::cout << "Tube closed" << std::endl;
}

void LaserScanPluglet::v_repSimStarts_callback() {

}

void LaserScanPluglet::v_repStart_callback() {

}

void LaserScanPluglet::v_repEnd_callback() {

}

} /* namespace vrep */
