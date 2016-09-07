#!/usr/bin/env sh
# generated from catkin/cmake/templates/env.sh.in

if [ $# -eq 0 ] ; then
  /bin/echo "Entering environment at '/opt/planetxrobots/ros/RoverLaunch/build/devel', type 'exit' to leave"
  . "/opt/planetxrobots/ros/RoverLaunch/build/devel/setup.sh"
  "$SHELL" -i
  /bin/echo "Exiting environment at '/opt/planetxrobots/ros/RoverLaunch/build/devel'"
else
  . "/opt/planetxrobots/ros/RoverLaunch/build/devel/setup.sh"
  exec "$@"
fi
