#!/usr/bin/env python
# motorcommander.py

#explorerhat must be installed, can be done through "curl http://get.pimoroni.com/explorerhat | bash" . Will only work on pi with explorer hat mounted
import explorerhat
import sys
import time
import rospy
from rover.msg import FinalMotorCommands

# set speed command, int can be from -100 to 100 with 100 being full speed ahead and -100 being full speed backwards
def setspeeds(Lwheel, Rwheel):
    explorerhat.motor.one.speed(Lwheel);
    explorerhat.motor.two.speed(Rwheel);

# stop both motors
def fullstop():
    explorerhat.motor.one.stop()
    explorerhat.motor.two.stop()

def main():

#receive motor commands from underlingmk2 on the rover
    	rospy.init_node('MotorCommander');	
    	sub = rospy.Subscriber("cmd_motors",FinalMotorCommands);
	Lwheel = 0;
	Rhweel = 0;
	while not rospy.is_shutdown():
    		Lwheel = sub.Lwheel;
    		Rwheel = sub.Rwheel;

    		if (Lwheel == 0 && Rhweel == 0):
        		fullstop()
        		print("full stop set")
    		else
        		setspeeds(Lwheel, Rhweel)
        	#print("wheel speeds set")

if __name__ == "__main__":
    main()
