/*
 * RosLuaCallRegistry.h
 *
 *  Created on: Feb 9, 2013
 *      Author: matthias
 */

#ifndef VREPPLUGLETREGISTRY_H_
#define VREPPLUGLETREGISTRY_H_


#include <vector>
#include "VRepPluglet.h"

#include "ros/ros.h"

namespace vrep {


class VRepPlugletRegistry {
protected:

	std::vector<VRepPluglet*> pluglets;

	static VRepPlugletRegistry* instance;

public:

	VRepPlugletRegistry();

	virtual ~VRepPlugletRegistry();

	std::vector<VRepPluglet*>& getPluglets();

	static VRepPlugletRegistry* getInstance() {
		if (!VRepPlugletRegistry::instance) {
			instance = new VRepPlugletRegistry();
		}

		return instance;
	}

};

} /* namespace vrep */
#endif /* ROSLUACALLREGISTRY_H_ */
