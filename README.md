vrep_youbot_plugin
==================

Installation
--

1) Install robocup@work packages (including ROS, youBot packages,...) 
- https://github.com/b-it-bots/RoboCupAtWork or
- https://github.com/RM-SS2013/RoboCupAtWork
 

2) Install v-rep (http://www.v-rep.eu/) into i.e. /opt/v-rep


3) clone the repository into your ros workspace

4) compile

$ rosmake

5) copy the compiled library libv_repExtyouBot.so into your /opt/v-rep directory


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
1) You can run the test script (test//test_joint_position.sh) in order to check if your are able to control the v-rep youBot using ROS


Have fun!






