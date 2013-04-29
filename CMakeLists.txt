cmake_minimum_required(VERSION 2.4.6)
include($ENV{ROS_ROOT}/core/rosbuild/rosbuild.cmake)

# Set the build type.  Options are:
#  Coverage       : w/ debug symbols, w/o optimization, w/ code-coverage
#  Debug          : w/ debug symbols, w/o optimization
#  Release        : w/o debug symbols, w/ optimization
#  RelWithDebInfo : w/ debug symbols, w/ optimization
#  MinSizeRel     : w/o debug symbols, w/ optimization, stripped binaries
set(ROS_BUILD_TYPE Debug)

rosbuild_init()

#set the default path for built executables to the "bin" directory
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
#set the default path for built libraries to the "lib" directory
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)

#uncomment if you have defined messages
#rosbuild_genmsg()
#uncomment if you have defined services
#rosbuild_gensrv()

#common commands for building c++ executables and libraries
#rosbuild_add_library(${PROJECT_NAME} src/example.cpp)
#target_link_libraries(${PROJECT_NAME} another_library)
#rosbuild_add_boost_directories()
#rosbuild_link_boost(${PROJECT_NAME} thread)
#rosbuild_add_executable(example examples/example.cpp)
#target_link_libraries(example ${PROJECT_NAME})

#rosbuild_add_boost_directories()

rosbuild_add_library(
#rosbuild_add_executable(
v_repExtyouBot
src/v_repExtyouBot.cpp 
src/v_repLib.cpp 

src/lua/GenericLuaFunctionRegistry.cpp
src/lua/GenericLuaCallback.cpp

src/VRepPluglet.cpp
src/VRepPlugletRegistry.cpp

src/ros/RosLuaCallback.cpp
src/ros/VRepRosPluglet.cpp

src/ros/callback/ClockCallback.cpp
src/ros/pluglet/ClockPluglet.cpp

src/ros/callback/LaserScanCallback.cpp
src/ros/pluglet/LaserScanPluglet.cpp

src/ros/callback/PointCloudCallback.cpp
src/ros/pluglet/PointCloudPluglet.cpp

src/ros/callback/JointControlCallback.cpp
src/ros/pluglet/JointControlPluglet.cpp

src/ros/callback/SwedishBaseControllerCallback.cpp
src/ros/pluglet/SwedishBaseControllerPluglet.cpp
) 

target_link_libraries(v_repExtyouBot pthread)
target_link_libraries(v_repExtyouBot dl)

