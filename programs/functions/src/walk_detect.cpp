/* This program enabled the NAO to walk around the room using its sonar without outside assistance */

// IMPROVEMENTS //
/* Walking is very basic and can easily be ruined but an object by the NAO's feet. Need to figure out
 * how to include another sensor to make the walking more effecient and functional */

// RIS INCLUDES //
#include "ros/ros.h"
#include "std_msgs/String.h"
#include "sensor_msgs/Range.h"
#include "geometry_msgs/Twist.h"
#include "std_msgs/Bool.h"
#include "nao_msgs/Bumper.h"
#include "custom_msgs/states.h"
#include "nao_interaction_msgs/AudioPlayback.h"

// Global variables to store sonar information
float rsonarr, lsonarr;

// Global variable to store onground bool
bool onground = true;

// Global variable to store the data for the bumper states
int bumperp, bumpers;

// Global variable to store the data for statepublish
custom_msgs::states controlmsgs;

// Left sonar callback function to update sonar data 
void sonarleftcb(const sensor_msgs::Range::ConstPtr& LeftSonar){
	lsonarr = LeftSonar->range;
}

// Right sonar callback function to update sonar data
void sonarrightcb(const sensor_msgs::Range::ConstPtr& RightSonar){
	rsonarr = RightSonar->range;
}

// Foot contact callback function to determine if robot is standing up
void footcb(const std_msgs::Bool Bools){
	onground = Bools.data;
}

// Bumper contact callback function to determine if the robot's feet have hit anything
void bumpercb(const nao_msgs::Bumper::ConstPtr& Bump){
	bumperp = Bump->bumper;
	bumpers = Bump->state;
}

// State callback to see if this node needs to run
void controlcb(const custom_msgs::states States){
	controlmsgs = States;
}

/* This program makes the nao walk
   to not run into things, it is subscribed to its two sonar topics
   and operates according to those */
int main(int argc, char ** argv){

	// initializing ros
	ros::init(argc, argv, "Walk_Detect");
	ros::NodeHandle n;
	ros::Rate loop_rate(50);

	// delcares the two subscribes so that it can retrieve the sonar values for each sonar
	ros::Subscriber sub_0 = n.subscribe("/nao_robot/sonar/left/sonar", 100, sonarleftcb);
	ros::Subscriber sub_1 = n.subscribe("/nao_robot/sonar/right/sonar", 100, sonarrightcb);

	// subscribes too footcontact so that it can tell if it has fallen down or not
	ros::Subscriber sub_2 = n.subscribe("/foot_contact", 100, footcb);

	// subscribes to bumpers so that it can determine if the nao's feet have hit anything
	ros::Subscriber sub_3 = n.subscribe("/bumper", 100, bumpercb);
	
	// Subscribes to control msgs to see if this node needs to be exectued
	ros::Subscriber sub_4 = n.subscribe("/control_msgs", 100, controlcb);

	// publishers to make the nao talk/move
	ros::Publisher talk = n.advertise<std_msgs::String>("/speech", 100);
	ros::Publisher move = n.advertise<geometry_msgs::Twist>("/cmd_vel", 100);

	// publsher to contr_msgs to tell node to stop/go
	ros::Publisher pub_contrl = n.advertise<custom_msgs::states>("control_msgs", 100);

        ros::ServiceClient client1 = n.serviceClient<nao_interaction_msgs::AudioPlayback>("/nao_audio/play_file");

        nao_interaction_msgs::AudioPlayback sun;

	// variable declarations
	std_msgs::String words; //file_path;
	geometry_msgs::Twist direct, stop;
	int i = 0; 
	bool firsttime = true;

	// declarations of the stop variable values so that a simple publish to stop
	// will make the robot stop
	stop.linear.x = 0;
        stop.linear.y = 0;
        stop.linear.z = 0;
        stop.angular.x = 0;
        stop.angular.y = 0;
        stop.angular.z = 0;

	// execute while not terminated
	while(ros::ok()){
		ros::spinOnce();
		loop_rate.sleep();
		if(controlmsgs.walk_detect == true){
			ros::spinOnce();
			loop_rate.sleep();
			i = 0;
			if(firsttime){
				words.data = "I can walk around freely without assistance. Watch me.";
				talk.publish(words);
				ros::Duration(5).sleep();		
				//sun.request.file_path.data = "/music/doit.ogg";
                                //ros::service::call("/nao_audio/play_file", sun);
				firsttime = false;
			}
	
			// if nothing is too close to the nao, it will just move forward
			else if(!onground){
				ROS_INFO("ROBOT IS NOT ON GROUND");
				loop_rate.sleep();
				//sun.request.file_path.data = "/music/dontit.ogg";
                                //ros::service::call("/nao_audio/play_file", sun);
				controlmsgs.walk_detect = false;
				pub_contrl.publish(controlmsgs);
				ROS_INFO("STOPPING\n");
				loop_rate.sleep();
				ros::spinOnce();
			}
			
			// if bumper is hit, make the nao move backwards
			else if((bumperp == 0 || bumperp == 1) && bumpers == 1){
				ROS_INFO("BUMPER HIT: BACKING UP\n");
				move.publish(stop);
				loop_rate.sleep();
				direct.linear.x = -0.5;
				direct.angular.z = 0.3;
				move.publish(direct);
				loop_rate.sleep();
				ros::Duration(2).sleep();
				move.publish(stop);
				ros::spinOnce();
			}

			else{
	
				// if its clearn infront, the nao will move forward
				if(rsonarr >= 0.335 && lsonarr >= 0.335){
					ROS_INFO("MOVING STRAIGHT\n");
					direct.linear.x = 0.5;
					direct.angular.z = -0.05;
					move.publish(direct);
					loop_rate.sleep();
					ros::spinOnce();
				}
	
				// if an object is too close to the right side, the nao will turn left
				else if(rsonarr < 0.335 && lsonarr > 0.335){
					ROS_INFO("RIGHT SIDE TO CLOSE");
					ROS_INFO("MOVING LEFT\n");
					loop_rate.sleep();
					direct.angular.z = 0.3;
					direct.linear.x = -0.2;
					move.publish(direct);
					loop_rate.sleep();
					ros::spinOnce();
				}
	
				// if an object is too close to the left side, the nao will turn right
				else if(rsonarr > 0.335 && lsonarr < 0.335){
					ROS_INFO("LEFT SIDE TOO CLOSE");
					ROS_INFO("MOVING RIGHT\n");
					loop_rate.sleep();
					direct.angular.z = -0.3;
					direct.linear.x = -0.2;
					move.publish(direct);
					loop_rate.sleep();
					ros::spinOnce();
				}
	
				// if an object is too close, the nao will back up
				else{
					if(rsonarr < 0.335 && lsonarr < 0.335){
						ROS_INFO("TOO CLOSE");
						ROS_INFO("BACKING UP\n");
						loop_rate.sleep();
						direct.linear.x = -0.5;
						direct.angular.z = 0;
						move.publish(direct);
						loop_rate.sleep();
						ros::spinOnce();
					}	
				}
			}
		}
		else{
			if(i == 0){
				ROS_INFO("WAITING FOR STATEPUBLISHER\n");
				firsttime = true;
				//sun.request.file_path.data = "/music/nothing.ogg";
                                //client.call(sun);
			}
			i++;
			ros::spinOnce();
			loop_rate.sleep();
		}
	}	
	return 0;
}
