cmake_minimum_required(VERSION 2.8.3)
project(vrep_youbot_plugin)

# Set the build type.  Options are:
#  Coverage       : w/ debug symbols, w/o optimization, w/ code-coverage
#  Debug          : w/ debug symbols, w/o optimization
#  Release        : w/o debug symbols, w/ optimization
#  RelWithDebInfo : w/ debug symbols, w/ optimization
#  MinSizeRel     : w/o debug symbols, w/ optimization, stripped binaries

find_package(catkin REQUIRED)
find_package(PCL 1.7 REQUIRED)
catkin_package(LIBRARIES v_repExtyouBot
               CATKIN_DEPENDS roscpp std_msgs sensor_msgs cv_bridge tf brics_actuator
               DEPENDS opencv pthread dl PCL)


include_directories(include ${catkin_INCLUDE_DIRS} ${PCL_INCLUDE_DIRS})
message("catkin Include DIRS" ${catkin_INCLUDE_DIRS})
message("PCL Include DIRS" ${PCL_INCLUDE_DIRS})

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

#rosbuild_add_executable(
add_library(
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

