#!/usr/bin/env python
"""Rover state using the Phidgets 8/8/8

Measure and report the battery voltage, whether it's
considered to be depleted or not and the front and back
range to an obstacle.
"""

__author__ = 'Bill Mania <bill@manialabs.us>'
__version__ = '1'

import roslib; roslib.load_manifest('RoverState')
import rospy
from RoverState.msg import Battery, Range
from ctypes import *
from Phidgets.Devices.InterfaceKit import InterfaceKit
from Phidgets.PhidgetException import PhidgetErrorCodes, PhidgetException
from Phidgets.Events.Events import AttachEventArgs, DetachEventArgs, ErrorEventArgs, InputChangeEventArgs, OutputChangeEventArgs, SensorChangeEventArgs

interfaceKit = None
batteryInfo = Battery(batteryVoltagePercentage = 100, depleted = False)
rangeInfo = Range() 
batteryPublisher = None
rangePublisher = None
batteryVoltageChannel = None
batteryFullLevel = 1024
batteryDepletedLevel = 100
batteryRange = 0
frontRangeChannel = None
backRangeChannel = None

def attachHandler(event):
    return

def detachHandler(event):
    return

def errorHandler(event):
    return

def inputChangeHandler(event):
    return

def outputChangeHandler(event):
    return

def sensorChangeHandler(event):
    global batteryInfo, rangeInfo

#    rospy.logdebug('Sensor channel %d, value %d' % (event.index, event.value))

    if event.index == batteryVoltageChannel:
        sendBattery()
    elif event.index == frontRangeChannel:
        sendRange()
    elif event.index == backRangeChannel:
        sendRange()
    else:
        pass

    return

def calculateRange(sensorReading):
    """Return the range in centimeters based on the sensor reading"""

    if sensorReading < 200:
        # beyond the range of the IR sensor
        return 100

    if sensorReading < 300:
        return 20

    if sensorReading < 500:
        return 10

    if sensorReading < 600:
        return 5

    return 0

def sendRange():
    global rangeInfo

    newFrontRangeCm = calculateRange(interfaceKit.getSensorValue(frontRangeChannel))
    newBackRangeCm = calculateRange(interfaceKit.getSensorValue(backRangeChannel))

    publishUpdate = False

    if ((newFrontRangeCm - rangeInfo.frontRangeCm) ** 2) > 24:
        rangeInfo.frontRangeCm = newFrontRangeCm
        publishUpdate = True

    if ((newBackRangeCm - rangeInfo.backRangeCm) ** 2) > 24:
        rangeInfo.backRangeCm = newBackRangeCm
        publishUpdate = True

    if publishUpdate:
        rangePublisher.publish(rangeInfo)

    return

def sendBattery():
    global batteryInfo

    rospy.logdebug('raw battery sensor value %d' % (interfaceKit.getSensorValue(batteryVoltageChannel)))
    currentBatteryLevel = int(interfaceKit.getSensorValue(batteryVoltageChannel))
    newBatteryVoltagePercentage = int(((currentBatteryLevel - batteryDepletedLevel) / batteryRange) * 100)

    publishUpdate = False

    if newBatteryVoltagePercentage != batteryInfo.batteryVoltagePercentage:
        batteryInfo.batteryVoltagePercentage = newBatteryVoltagePercentage
        publishUpdate = True

    if (currentBatteryLevel <= batteryDepletedLevel):
        batteryInfo.depleted = True
        publishUpdate = True
    else:
        batteryInfo.depleted = False
    
    if publishUpdate:
        batteryPublisher.publish(batteryInfo)

    return

def setupSensorHandlers():
    global interfaceKit, batteryPublisher, rangePublisher
    global batteryVoltageChannel, batteryFullLevel, batteryDepletedLevel, batteryRange, frontRangeChannel, backRangeChannel
    global batteryInfo, rangeInfo

    try:
        interfaceKit = InterfaceKit()

    except RuntimeError as e:
        rospy.logfatal('Failed to create InterfaceKit: %s' % (e.details))
        rospy.signal_shutdown('Failed to connect to InterfaceKit')

    try:
        interfaceKit.setOnAttachHandler(attachHandler)
        interfaceKit.setOnDetachHandler(detachHandler)
        interfaceKit.setOnErrorhandler(errorHandler)
        interfaceKit.setOnInputChangeHandler(inputChangeHandler)
        interfaceKit.setOnOutputChangeHandler(outputChangeHandler)
        interfaceKit.setOnSensorChangeHandler(sensorChangeHandler)

    except PhidgetException as e:
        rospy.logfatal('Failed to set handlers: %i, %s' % (e.code, e.details))
        rospy.signal_shutdown('Failed to connect to InterfaceKit')

    try:
        interfaceKit.openPhidget()

    except PhidgetException as e:
        rospy.logfatal("Failed to openPhidget() %i: %s" % (e.code, e.details))
        rospy.signal_shutdown('Failed to openPhidget()')

    try:
        interfaceKit.waitForAttach(10000)

    except PhidgetException as e:
        rospy.logfatal("Failed on waitForAttach() %i: %s" % (e.code, e.details))
        interfaceKit.closePhidget()
        rospy.signal_shutdown('Failed on waitForAttach()')

    for sensor in range(interfaceKit.getSensorCount()):
        try:
            interfaceKit.setDataRate(sensor, 16)

        except PhidgetException as e:
            rospy.logwarn("Failed to setDateRate() %i: %s" % (e.code, e.details))

    batteryPublisher = rospy.Publisher('batteryInfo', Battery)
    rangePublisher = rospy.Publisher('rangeInfo', Range)

    batteryVoltageChannel = rospy.get_param('RoverState/battery/channel')
    batteryFullLevel = float(rospy.get_param('RoverState/battery/fullCharge'))
    batteryDepletedLevel = rospy.get_param('RoverState/battery/depletedCharge')
    batteryRange = batteryFullLevel - batteryDepletedLevel
    frontRangeChannel = rospy.get_param('RoverState/range/front/channel')
    backRangeChannel = rospy.get_param('RoverState/range/back/channel')

    sendRange()
    sendBattery()

    return

def processSensorInputs():

    while not rospy.is_shutdown():
        sendRange()
        sendBattery()
        rospy.sleep(5)

    interfaceKit.closePhidget()

    return

if __name__ == "__main__":
    rospy.init_node(
            'RoverState',
            log_level = rospy.DEBUG
            )

    setupSensorHandlers()

    processSensorInputs()
