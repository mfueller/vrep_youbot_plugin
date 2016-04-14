// Copyright 2006-2013 Dr. Marc Andreas Freese. All rights reserved.
// marc@coppeliarobotics.com
// www.coppeliarobotics.com
//
// -------------------------------------------------------------------
// This file is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
//
// You are free to use/modify/distribute this file for whatever purpose!
// -------------------------------------------------------------------
//
// This file was automatically created for V-REP release V3.0.1 on January 20th 2013

#include "v_repLib.h"
#include "v_repExtyouBot.h"

# include "ros/ros.h"
#include <iostream>

#include <boost/any.hpp>
#include <vector>

#include "vrep_plugin/lua/GenericLuaFunctionRegistry.h"
#include "vrep_plugin/VRepPlugletRegistry.h"

vrep::GenericLuaFunctionRegistry registry;

#define PLUGIN_VERSION 2

LIBRARY vrepLib; // the V-REP library that we will dynamically load and bind

// This is the plugin start routine (called just once, just after the plugin was loaded):
VREP_DLLEXPORT unsigned char v_repStart(void* reservedPointer,int reservedInt)
{
	// Dynamically load and bind V-REP functions:
	// ******************************************
	// 1. Figure out this plugin's directory:
	char curDirAndFile[1024];
	getcwd(curDirAndFile, sizeof(curDirAndFile));

	std::string currentDirAndPath(curDirAndFile);
	// 2. Append the V-REP library's name:
	std::string temp(currentDirAndPath);
#ifdef _WIN32
	temp+="\\v_rep.dll";
#elif defined (__linux)
	temp+="/libv_rep.so";
#elif defined (__APPLE__)
	temp+="/libv_rep.dylib";
#endif /* __linux || __APPLE__ */
	// 3. Load the V-REP library:
	vrepLib=loadVrepLibrary(temp.c_str());
	if (vrepLib==NULL)
	{
		std::cout << "Error, could not find or correctly load the V-REP library. Cannot start 'youBot ROS' plugin.\n";
		return(0); // Means error, V-REP will unload this plugin
	}
	if (getVrepProcAddresses(vrepLib)==0)
	{
		std::cout << "Error, could not find all required functions in the V-REP library. Cannot start 'youBot ROS' plugin.\n";
		unloadVrepLibrary(vrepLib);
		return(0); // Means error, V-REP will unload this plugin
	}
	// ******************************************

	// Check the version of V-REP:
	// ******************************************
	int vrepVer;
	simGetIntegerParameter(sim_intparam_program_version,&vrepVer);
	if (vrepVer<20604) // if V-REP version is smaller than 2.06.04
	{
		std::cout << "Sorry, your V-REP copy is somewhat old. Cannot start 'youBot ROS' plugin.\n";
		unloadVrepLibrary(vrepLib);
		return(0); // Means error, V-REP will unload this plugin
	}
	// ******************************************


	// Here you could handle various initializations
	// Here you could also register custom Lua functions or custom Lua constants
	// etc.

	int argc = 0;
	char** argv = {};


	ros::init(argc, argv,"V_RepyouBot");

	if(!ros::master::check()) {
		std::cout << "No ROS master available - youBot Plugin not initialized" << std::endl;
			return(false);
	}

	for (unsigned int i=0; i  < registry.getCallbacks().size(); i++) {
		GenericLuaCallback* cb = registry.getCallbacks()[i];
		GenericLuaCallback::LuaDescription desc = cb->getDescription();

		GenericLuaCallback::callBackPtr pointer = cb->getPointer();

		if (pointer != 0) {
			simRegisterCustomLuaFunction(desc.name.c_str(),
					desc.tooltip.c_str(),
					desc.argTypes,
					pointer);
			std::cout << "LUA function registered: " << desc.name.c_str() << " " << std::endl;
		} else {
			std::cout << "Callback function 0 for Callback " << desc.name << std::endl;
		}

	}



	/*
	// Initialize the ROS part:
	if(!ROS_server::initialize())
	{
		std::cout << "ROS master is not running. Cannot start 'rosSkeleton' plugin.\n";
		return (0); //If the master is not running then the plugin is not loaded.
	}
	*/
	std::cout << "youBot Plugin registered"<< std::endl;
	return(PLUGIN_VERSION); // initialization went fine, we return the version number of this plugin (can be queried with simGetModuleName)
}

// This is the plugin end routine (called just once, when V-REP is ending, i.e. releasing this plugin):
VREP_DLLEXPORT void v_repEnd()
{
	// Here you could handle various clean-up tasks

	for (unsigned int i=0; i  < vrep::VRepPlugletRegistry::getInstance()->getPluglets().size(); i++) {
		if (vrep::VRepPlugletRegistry::getInstance()->getPluglets()[i]->is_active())
						vrep::VRepPlugletRegistry::getInstance()->getPluglets()[i]->v_repEnd_callback();
	}

	//ROS_server::shutDown();	// shutdown the ROS_server
	unloadVrepLibrary(vrepLib); // release the library
}

// This is the plugin messaging routine (i.e. V-REP calls this function very often, with various messages):
VREP_DLLEXPORT void* v_repMessage(int message,int* auxiliaryData,void* customData,int* replyData)
{
	// This is called quite often. Just watch out for messages/events you want to handle
	// Keep following 4 lines at the beginning and unchanged:
	int errorModeSaved;
	simGetIntegerParameter(sim_intparam_error_report_mode,&errorModeSaved);
	simSetIntegerParameter(sim_intparam_error_report_mode,sim_api_errormessage_ignore);
	void* retVal=NULL;

	// Here we can intercept many messages from V-REP (actually callbacks). Only the most important messages are listed here:

	if (message==sim_message_eventcallback_instancepass)
	{
		// This message is sent each time the scene was rendered (well, shortly after) (very often)
		// When a simulation is not running, but you still need to execute some commands, then put some code here

		//ROS_server::instancePass();

		if (simGetSimulationState() == sim_simulation_advancing_running) {

			for (unsigned int i=0; i  < vrep::VRepPlugletRegistry::getInstance()->getPluglets().size(); i++) {
				if (vrep::VRepPlugletRegistry::getInstance()->getPluglets()[i]->is_active())
								vrep::VRepPlugletRegistry::getInstance()->getPluglets()[i]->v_repMessage_callback();
			}
		}

	}

	if (message==sim_message_eventcallback_mainscriptabouttobecalled)
	{
		// Main script is about to be run (only called while a simulation is running (and not paused!))
		//
		// This is a good location to execute simulation commands

		//ROS_server::mainScriptAboutToBeCalled();
	}

	if (message==sim_message_eventcallback_simulationabouttostart)
	{
	    // Simulation is about to start

		//ROS_server::simulationAboutToStart();

		for (unsigned int i=0; i  < vrep::VRepPlugletRegistry::getInstance()->getPluglets().size(); i++) {
			if (vrep::VRepPlugletRegistry::getInstance()->getPluglets()[i]->is_active())
				vrep::VRepPlugletRegistry::getInstance()->getPluglets()[i]->v_repSimStarts_callback();
		}

	}

	if (message==sim_message_eventcallback_simulationended)
	{
		// Simulation just ended

		//ROS_server::simulationEnded();

		for (unsigned int i=0; i  < vrep::VRepPlugletRegistry::getInstance()->getPluglets().size(); i++) {
			if (vrep::VRepPlugletRegistry::getInstance()->getPluglets()[i]->is_active())
							vrep::VRepPlugletRegistry::getInstance()->getPluglets()[i]->v_repSimEnds_callback();
		}

	}

	// Keep following unchanged:
	simSetIntegerParameter(sim_intparam_error_report_mode,errorModeSaved); // restore previous settings
	return(retVal);
}

int main() {
	return 0;
}
