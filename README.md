vrep_youbot_plugin
==================

Installation
--

1) Install youBot ROS packages
- e.g.  $ sudo apt-get install ros-indigo-youbot-driver-ros-interface

2) Install v-rep (http://www.v-rep.eu/) into i.e. /opt/v-rep

3) clone the repository into your catkin workspace

4) Copy vrep_common and vrep_plugin ros packages to your catkin workspace

    $ cp -r /opt/v-rep/programming/ros_packages/vrep_plugin ~/catkin_ws/src/
    $ cp -r /opt/v-rep/programming/ros_packages/vrep_common ~/catkin_ws/src/

5) compile

    $ catkin_make

6) copy the compiled libraries libv_repExtyouBot.so and libv_repExtRos.so into your /opt/v-rep directory

    $ sudo cp ~/catkin_ws/devel/lib/libv_repExt* /opt/v-rep

Usage
--

1) Start ros

    $ roscore

2) load v-rep bringup launchfile

    $ roslaunch vrep_youbot_plugin vrep_youbot.launch

3) start v-rep

    $ /opt/v-rep/v-rep.sh

4) Load the scene file in v-rep (.../vrep_youbot_plugin/scenes/...)

5) Start the simulation

Note: the simulation must be running before you can control the youBot!


Test ROS plugin
--
1) You can run the test scripts (test//test_joint_position.sh, test_gripper_position.sh, test_base.sh) in order to check if your are able to control the v-rep youBot using ROS


Have fun!
