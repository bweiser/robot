#!/usr/bin/env sh
# generated from catkin/cmake/templates/env.sh.in

if [ $# -eq 0 ] ; then
  /bin/echo "Entering environment at '/opt/planetxrobots/ros/DriveMotors/build/catkin_generated', type 'exit' to leave"
  . "/opt/planetxrobots/ros/DriveMotors/build/catkin_generated/setup_cached.sh"
  "$SHELL" -i
  /bin/echo "Exiting environment at '/opt/planetxrobots/ros/DriveMotors/build/catkin_generated'"
else
  . "/opt/planetxrobots/ros/DriveMotors/build/catkin_generated/setup_cached.sh"
  exec "$@"
fi
