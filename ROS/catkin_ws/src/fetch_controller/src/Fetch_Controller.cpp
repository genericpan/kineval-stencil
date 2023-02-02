#include "Fetch_Controller.hpp"

float dist=0;
geometry_msgs::Twist m;
Fetch_Controller::Fetch_Controller(ros::NodeHandle &nh)
{
    nh_ = nh;

nh_.subscriber_ = nh.subscribe("/base_scan",1000,Laser_Scan_Callback);
nh_.publisher_ = nh.advertise("/cmd_vel",1000)
publisher_.publish(m);

    //TODO: initialize a subscriber that is set to the topic "/base_scan". Set its callback function to be Laser_Scan_Callback
    //TODO: initialize a publisher that is set to the topic "/cmd_vel"

    
}

void Fetch_Controller::Laser_Scan_Callback(const sensor_msgs::LaserScan::ConstPtr &msg_laser_scan)
{

scan.angle_min = -60*(3.14515/180)
scan.angle_max = 60*(3.14515/180)
dist=999;
ran=msg_laser_scan->ranges;
for(int i = 0; i < msg_laser_scan->ranges.size(); ++i){
		if ([i]<dist){
	dist=ran[i];
}
	}
geometry_msgs::Twist msg;
msg.linear.x = dist;
m=msg;
    /*TODO: 
    Given the incoming laser scan message, find the minimium distance of the front facing scans
    Hint: The laser scan measuring directly in front of the robot will be the scan at the middle of the array laser scans. 
    So for finding the minimum, we will ONLY consider the 120 laser scans in the middle of the array of laser scans. 
    If the minimum scan in this direction is greater than 1m, drive forward. 
    Otherwise, turn left. 
    */

}
