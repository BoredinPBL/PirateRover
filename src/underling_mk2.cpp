/****************************************************************************************
 *  NOVA ROVER TEAM - URC2018 // Pirated for micro-rover usage. 
 *  This is the code executed onboard the rover to manage all driving-related aspects,
 *  such as motor speed control, motor direction control, etc.
 *  
 *  Motor model:
 *  tiny 6V bois
 *  controlled using a pimoroni explorer hat rather than dedicated PWNs
 *  
 * 
 *  Authors: Steerzy & Bruno // and DrNova
 ****************************************************************************************/

/***************************************************************************************************
* INCLUDES, DECLARATIONS AND GLOBAL VARIABLES
***************************************************************************************************/
// ________________________General includes________________________
#include "ros/ros.h"
#include <ros/console.h>
#include <math.h>
#include <stdlib.h>
#include <iostream>
#include <wiringPi.h>
#include <wiringSerial.h>
#include <string>
#include <signal.h>
using namespace std;

// __________________________ROS includes__________________________
#include <rover/DriveCmd.h>
#include <rover/RPM.h>
#include <std_msgs/Float32.h>
#include <rover/ReqRPM.h>

// __________________________Definitions___________________________
#define LOOP_HERTZ              50 // Main control loop rate
#define ON_THE_SPOT_THRESHOLD   0.2 // Highest drive percentage value before

#define NORMAL_DRIVE        0
#define ON_THE_SPOT_LEFT    1
#define ON_THE_SPOT_RIGHT   2

// Global variables
float limit_drive   = 1;
float limit_steer   = 1;
float drive_pcnt    = 0;    // Desired wheel speed percentage
float steer_pcnt    = 0;    // Desired steering speed percentage
int MAX_RPM = 1;

const float iteration_time = 1.0/LOOP_HERTZ;    // Iteration time of the main loop

int steer_mod[2]    = {1,1};    // The rotation direction of each wheel

ros::NodeHandle* n;

/***************************************************************************************************
* SET WHEEL DIRECTIONS FUNCTION
*
* This function takes in a direction for the rover to drive in (state machine: int input corresponds 
* to a different state) and applies the appropriate steering modifications.
*
* Inputs:   int direction - The desired driving direction:
                                - 0 (NORMAL DRIVE): All wheels spin in the same direction
                                - 1 (ON THE SPOT LEFT): Left wheels spin backwards, right forwards
                                - 2 (ON THE SPOT RIGHT): Right wheels spin forwards, left backwards
***************************************************************************************************/
void Set_Wheel_Directions(int direction)
{
    switch(direction)
    {
        case NORMAL_DRIVE:
            steer_mod[0] = 1;
            steer_mod[1] = 1;
            break;
        case ON_THE_SPOT_LEFT:
            steer_mod[0] = 1;
            steer_mod[1] = 0;
            break;
        case ON_THE_SPOT_RIGHT:
            steer_mod[0] = 0;
            steer_mod[1] = 1;
            break;
        default:
            // NORMAL DRIVE by default
            steer_mod[0] = 1;
            steer_mod[1] = 1;
    }

}

/***************************************************************************************************
* COMMAND DATA CALLBACK FUNCTION
*
* The callback function for the subscription to drive command topic "cmd_data". This function is 
* called whenever new "cmd_data" data is published and sets the new acceleration and 
* steering percentage for the rover via global variables.
*
* Input:    const rover::DriveCmd::ConstPtr& msg) - The message object containing the relevent data
***************************************************************************************************/
void cmd_data_cb(const rover::DriveCmd::ConstPtr& msg)
{   
    int speedL, speedR;
    // Get driving and steering commands from the mainframe
        drive_pcnt = msg->acc;
        steer_pcnt = msg->steer;

        // Check to see if we are turning on the spot
        if(fabs(drive_pcnt) < ON_THE_SPOT_THRESHOLD)
        {
            if(steer_pcnt < 0) Set_Wheel_Directions(ON_THE_SPOT_LEFT)
		speedL = drive_pcnt;
		speedR = 0;
            else Set_Wheel_Directions(ON_THE_SPOT_RIGHT);
		speedL = 0; 
            	speedR = speedL;     
        }	
        // Otherwise drive normally
        else
        {
            Set_Wheel_Directions(NORMAL_DRIVE);
            // Applies normal steering if desired. Steering is done by slowing down one side of wheels and speeding
            // up the other.
            if(steer_pcnt > 0)
            {
                speedL = limit_drive*fabs((drive_pcnt*MAX_RPM)/100)-(limit_steer*fabs(steer_pcnt*(MAX_RPM/2)/100)); 
                speedR = limit_drive*fabs((drive_pcnt*MAX_RPM)/100)+(limit_steer*fabs(steer_pcnt*(MAX_RPM/2)/100));
		    }
            else
            {
                speedL = limit_drive*fabs((drive_pcnt*MAX_RPM)/100)+(limit_steer*fabs(steer_pcnt*(MAX_RPM/2)/100)); 
                speedR = limit_drive*fabs((drive_pcnt*MAX_RPM)/100)-(limit_steer*fabs(steer_pcnt*(MAX_RPM/2)/100));
            }
        }
        //Set_Desired_Speeds(speedR, speedR, speedL, speedL); // Set new desired wheel speeds
      
}



int main(int argc, char **argv)
{
    // ********************* ROS ************************* //

    ros::init(argc, argv, "underling");
    n = new ros::NodeHandle();
    ros::Rate loop_rate(LOOP_HERTZ);
  
    // Declare publishers and subscribers
    ros::Subscriber     drivecmd_sub    = n->subscribe("cmd_data", 5, cmd_data_cb);	

    ros::Publisher	finalmotorvalues_pub = (*n)->advertise<rover::FinalMotorValues>("cmd_motors", 1);

    string state; // Holds the current parameter state
    bool drive_dir = 1; // Wheel direction
    bool standby_message_printed = 0;
  

    // ****************** VARIABLES ********************** //

    // ******************** SETUP ************************ //

    n->setParam("/MODE", "TEST"); // Make sure we start in testing mode

    // *************************** MAIN LOOP *************************** //

    while (ros::ok())
    {
        // Set new motor directions
        drive_dir = !(drive_pcnt < 0);

        // Speed control loop; loops for each wheel

	    rover::FinalMotorValues msg;

	    msg.Lwheel = Lwheel;
	    msg.Rwheel = Rwheel;

	    finalmotorvalues_pub.publish(msg)

        if(state == "STANDBY")
        {
	    rover::FinalMotorValues msg;

	    msg.Lwheel = 0;
	    msg.Rwheel = 0;

	    finalmotorvalues_pub.publish(msg)

            if(!standby_message_printed)
            {
                ROS_ERROR_STREAM("ROVER: STATE SET TO STANDBY");
                standby_message_printed = 1;
            }
        }

        // Update wheel directions and speeds //!!!!!!!
   //     for (int i = 0; i < 2; i++)
     //   {
     //       bool direction;
     //       direction = (steer_mod[i] != drive_dir);
     //       digitalWrite (dir_pins[i], direction);

      //      pwmWrite(PIN_BASE + i, drive_pwm[i]);
       // }

        ros::spinOnce();
        loop_rate.sleep();
    }
    return 0;
}
