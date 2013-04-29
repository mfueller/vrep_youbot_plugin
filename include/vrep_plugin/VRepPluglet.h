/*
 * GenericRosConnection.h
 *
 *  Created on: Apr 29, 2013
 *      Author: matthias
 */

#ifndef VREPPLUGLET_H_
#define VREPPLUGLET_H_


#include "ros/ros.h"

namespace vrep {
class VRepPluglet {
protected:

public:

	VRepPluglet();

	virtual ~VRepPluglet();

	virtual void init() = 0;

	virtual void v_repStart_callback() = 0;

	virtual void v_repMessage_callback() = 0;

	virtual void v_repEnd_callback() = 0;

	virtual void v_repSimStarts_callback() = 0;

	virtual void v_repSimEnds_callback() = 0;

	virtual bool is_active() = 0;
};

}

#endif /* GENERICROSCONNECTION_H_ */
