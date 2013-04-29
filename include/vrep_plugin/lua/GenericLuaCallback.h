/*
 * GenericCallback.h
 *
 *  Created on: Feb 8, 2013
 *      Author: matthias
 */

#ifndef GENERICCALLBACK_H_
#define GENERICCALLBACK_H_


#include "v_repLib.h"
#include <iostream>

#include <vector>

#include "ros/ros.h"

#include <boost/any.hpp>

typedef boost::any Arg;
typedef std::vector<boost::any> Argslist;


#define LUA_CALLBACK(cl) static cl* instance; \
		GenericLuaCallback::callBackPtr getPointer() { \
		return cl::luaCallFunction; \
	} \
    static void luaCallFunction(SLuaCallBack* p) { \
    		Argslist a = cl::instance->LuaArgumentParser(p); \
    		cl::instance->luaCall(a); \
    }


class GenericLuaCallback {
/*
protected:
	ros::NodeHandle* nodeHandle;

	std::vector<GenericRosConnection*> connections;
*/
public:

	typedef void (*callBackPtr)(SLuaCallBack*) ;

	struct LuaDescription {
		std::string name;
		std::string tooltip;
		int argTypes[10];

	};

	GenericLuaCallback();

	virtual ~GenericLuaCallback();

	Argslist LuaArgumentParser(SLuaCallBack* p);

	virtual void luaCall(Argslist args) = 0;

	virtual LuaDescription getDescription() = 0;

	virtual callBackPtr getPointer() = 0;

};




#endif /* GENERICCALLBACK_H_ */
