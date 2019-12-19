#!/usr/bin/env python
# MotorCommander.py

#explorerhat must be installed, can be done through "curl http://get.pimoroni.com/explorerhat | bash" . Will only work on pi with explorer hat mounted
import explorerhat
import sys
import time
import rospy
from piraterover.msg import DriveCmd

# set speed command, int can be from -100 to 100 with 100 being full speed ahead and -100 being full speed backwards
def motorcallback(data):
    explorerhat.motor.one.speed(data.Lwheel);
    explorerhat.motor.two.speed(data.Rwheel);


def main():

#receive motor commands from overlordvia cmd_date topic
    	rospy.init_node('MotorCommander');
        sub = rospy.Subscriber("/cmd_data", DriveCmd,motorcallback);
	while not rospy.is_shutdown():
		pass
	rospy.spin()

if __name__ == "__main__":
    main()
