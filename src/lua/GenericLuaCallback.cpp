/*
 * GenericCallback.cpp
 *
 *  Created on: Feb 8, 2013
 *      Author: matthias
 */

#include "vrep_plugin/lua/GenericLuaCallback.h"


GenericLuaCallback::GenericLuaCallback() {

}



GenericLuaCallback::~GenericLuaCallback() {

}


Argslist GenericLuaCallback::LuaArgumentParser(SLuaCallBack* p)
{
	Argslist args;


	std::cout << "publisher callback" << std::endl;


	int ptr[8];
	for (int i=0; i<8;i++) {
		ptr[i] = 0;
	}

	int size = p->inputArgCount*2;
	for (int i=0; i<size;i+=2) {
		Arg arg;


		bool bool_val = false;
		int int_val = 0;
		float float_val = 0;
		std::string str_val = "";

		int type = p->inputArgTypeAndSize[i];
		int table_size = p->inputArgTypeAndSize[i+1];

		switch(type) {
		case sim_lua_arg_nil:
				break;
		case sim_lua_arg_bool:
				bool_val = p->inputBool[ptr[sim_lua_arg_bool]];
				arg = bool_val;
				ptr[sim_lua_arg_bool]++;
				break;
		case sim_lua_arg_int:
			int_val = p->inputInt[ptr[sim_lua_arg_int]];
			arg = int_val;
			ptr[sim_lua_arg_int]++;
			break;

		case sim_lua_arg_float:
			float_val = p->inputFloat[ptr[sim_lua_arg_float]];
			arg = float_val;
			ptr[sim_lua_arg_float]++;
			break;

		case sim_lua_arg_string:
				str_val = (p->inputChar+ptr[sim_lua_arg_string]);
				arg = str_val;
				ptr[sim_lua_arg_string] += str_val.length() + 1;
				std::cout << "arg " << i << ": "
						<< boost::any_cast<std::string> (arg) << std::endl;
				break;
		default:
				if ((type & sim_lua_arg_table) == sim_lua_arg_table) {

					if ((type & sim_lua_arg_int) == sim_lua_arg_int) {
						std::vector<Arg> handles;

						for (int i=0; i<table_size; i++) {
							int_val = p->inputInt[ptr[sim_lua_arg_int]];
							arg = int_val;
							ptr[sim_lua_arg_int]++;

							handles.push_back(arg);
						}

						arg = handles;
					}


				} else {
					std::cout << "ERROR: argument " << i+1 << " not valid" << std::endl;
				}
				break;
		}

		args.push_back(arg);

	}

	return args;
}
/*
void GenericLuaCallback::cleanUp() {
	for (size_t i=0; i<connections.size(); i++) {
		connections[i]->cleanUp();
		delete connections[i];
	}

	connections.clear();
}

void GenericLuaCallback::spinOnce() {
	for (size_t i=0; i<connections.size(); i++) {
		connections[i]->spinOnce();
	}
}

void GenericLuaCallback::init() {
	/*
	for (size_t i=0; i<connections.size(); i++) {
		connections[i]->init();
	}
	*/
/*
GenericCallback::callBackPtr GenericCallback::getPointer() {
	return 0;
}
*/
/*
VRepPlugletConnection::~VRepPlugletConnection() {

}
*/
