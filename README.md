This is the ros kinetic package that I have built to control my little 3d printed rover.

It is designed to be used on my virtual linux PC.

Things to do to make it do things:
1. Install ros kinetic and be running a version of ubuntu that supports it
2. The explorerhat must be installed, can be done through "curl http://get.pimoroni.com/explorerhat | bash"
2. Ensure your ROS_MASTER_URI is set to the IP of the mainframe
3. run "catkin_make" in the ws_ folder
4. run "source devel/setup.bash" to ensure ros can access the package
5. run "rosrun piraterover MotorCommander.py"



# MotorCommander.py
turns the xbox commands into wheel motions. It doesn't do much, just receives the pre-procesed wheel percentages from the mainframe and applies it to the motors

### Subscriptions

Topic:       **cmd_data**<br />
Msg type:    rover/DriveCmd (custom)<br />
Description: Sends speed and steering commands to the rover.
