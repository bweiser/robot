#!/usr/bin/env python
"""Phidgets HC Motor Control ROS service for CoroBot

A ROS service to request a specific acceleration and individual
side drive wheels speed.

"""

__author__ = 'Bill Mania <bmania@coroware.com>'
__version__ = '1'

import roslib; roslib.load_manifest('DriveMotors')
from DriveMotors.srv import *
import rospy
from ctypes import *
from Phidgets.Devices.MotorControl import MotorControl
from Phidgets.PhidgetException import PhidgetErrorCodes, PhidgetException

motorControl = 0
leftWheels = 0
rightWheels = 1
minAcceleration = 0
maxAcceleration = 0
minSpeed = -100
maxSpeed = 100

def move(request):
    """Cause the CoroBot to move or stop moving

    Request a common acceleration, wheel directions and wheel speeds

    """

    rospy.logdebug(
            "Left: %d:%d, Right: %d:%d, Acceleration: %d", 
            leftWheels,
            request.leftSpeed,
            rightWheels,
            request.rightSpeed,
            request.acceleration
            )
    if request.acceleration > maxAcceleration:
        acceleration = float(maxAcceleration)
    elif request.acceleration < minAcceleration:
        acceleration = float(minAcceleration)
    else: 
        acceleration = float(request.acceleration)

    if request.leftSpeed < minSpeed:
        leftSpeed = float(minSpeed)
    elif request.leftSpeed > maxSpeed:
        leftSpeed = float(maxSpeed)
    else:
        leftSpeed = float(request.leftSpeed)
    if request.rightSpeed < minSpeed:
        rightSpeed = float(minSpeed)
    elif request.rightSpeed > maxSpeed:
        rightSpeed = float(maxSpeed)
    else:
        rightSpeed = float(request.rightSpeed)

    rospy.logdebug(
            "Left: %d:%d, Right: %d:%d, Acceleration: %d", 
            leftWheels,
            leftSpeed,
            rightWheels,
            rightSpeed,
            acceleration
            )
    try:
        motorControl.setAcceleration(leftWheels, acceleration);
        motorControl.setAcceleration(rightWheels, acceleration);
    except PhidgetException as e:
        rospy.logerr("Failed in setAcceleration() %i: %s", e.code, e.details)
        return(False)

    try:
        motorControl.setVelocity(leftWheels, leftSpeed);
        motorControl.setVelocity(rightWheels, rightSpeed);
    except PhidgetException as e:
        rospy.logerr("Failed in setVelocity() %i: %s", e.code, e.details)
        return(False)

    return(True)

def mcAttached(e):
    return

def mcDetached(e):
    return

def mcError(e):
    return

def mcCurrentChanged(e):
    return

def mcInputChanged(e):
    return

def mcVelocityChanged(e):
    return

def setupMoveService():
    """Initialize the DriveMotors service

    Establish a connection with the Phidget HC Motor Control and
    then with the ROS Master as the service DriveMotors

    """

    global motorControl, minAcceleration, maxAcceleration

    try:
        motorControl = MotorControl()
    except:
        rospy.logerr("Unable to connect to Phidget HC Motor Control")
        return

    try:
	    motorControl.setOnAttachHandler(mcAttached)
	    motorControl.setOnDetachHandler(mcDetached)
	    motorControl.setOnErrorhandler(mcError)
	    motorControl.setOnCurrentChangeHandler(mcCurrentChanged)
	    motorControl.setOnInputChangeHandler(mcInputChanged)
	    motorControl.setOnVelocityChangeHandler(mcVelocityChanged)
    except:
        rospy.logerr("Unable to register the handlers")
        return

    try:
        motorControl.openPhidget()
    except PhidgetException as e:
        rospy.logerr("Fail to openPhidget() %i: %s", e.code, e.details)
        return

    try:
        motorControl.waitForAttach(10000)
    except PhidgetException as e:
        rospy.logerr("Fail to attach to Phidget %i: %s", e.code, e.details)
        return

    if motorControl.isAttached():
        rospy.loginfo(
                "Device: %s, Serial: %d, Version: %d",
                motorControl.getDeviceName(),
                motorControl.getSerialNum(),
                motorControl.getDeviceVersion()
                )

    minAcceleration = motorControl.getAccelerationMin(leftWheels)
    maxAcceleration = motorControl.getAccelerationMax(leftWheels)

    rospy.init_node(
            'DriveMotors',
            log_level = rospy.DEBUG
            )

    phidgetMotorService = rospy.Service(
            'DriveMotors',
            Move,   
            move)

    rospy.spin()

if __name__ == "__main__":
    setupMoveService()

    try:
        motorControl.closePhidget()
    except:
        pass
