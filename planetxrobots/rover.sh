#!/bin/bash

source /opt/ros/kinetic/setup.bash

roverDir=/opt/planetxrobots/ros
roverMaster=rovercontrol4

export ROS_PACKAGE_PATH=${roverDir}:$ROS_PACKAGE_PATH
export ROS_MASTER_URI=http://${roverMaster}:11311/

roscd RoverLaunch
roslaunch --wait RoverLaunch RoverLaunch.launch

exit 0
