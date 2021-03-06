/* This code is a quick demonstration of what the head senesors on the NAO can do.
 * If they are touched, the NAO audibly and visibly responds */

// IMPROVEMENTS //
/* */

// ROS INCLUDES //
#include "ros/ros.h"
#include "std_msgs/String.h"
#include "nao_msgs/TactileTouch.h"
#include "nao_msgs/JointAnglesWithSpeed.h"

// Global Variables that store the button states //
int buttonn, buttonp;
//bool stringname;

// Button State Call Back, stores states in the global variables whenever ros::spinOnce() is called //
void callback(const nao_msgs::TactileTouch::ConstPtr& Buttons){
	buttonn = Buttons->button;
	buttonp = Buttons->state;
}

int main(int argc, char ** argv){

	// Initializes ROS //
	ros::init(argc, argv, "headtouch");
	ros::NodeHandle n;
	ros::Rate loop_rate(1);

	// Subscribes to tactile_touch and uses the callback callback to store the information //
	ros::Subscriber sub = n.subscribe("/tactile_touch", 100, callback);

	// Publishes to speech to make the NAO talk //
	ros::Publisher pub = n.advertise<std_msgs::String>("/speech", 100);

	// Publishes to joint_angles to move the NAO's joints //
	ros::Publisher move = n.advertise<nao_msgs::JointAnglesWithSpeed>("/joint_angles", 100);

	// Variable Declarations //
	std_msgs::String talk;
	nao_msgs::JointAnglesWithSpeed mrsp, mlsp;
	bool run = false, check = true;
	int i = 0;

	// Initializes the joint angles name, speed, and position //
	mrsp.joint_names.push_back("RShoulderPitch");
	mlsp.joint_names.push_back("LShoulderPitch");
	mrsp.joint_angles.push_back(1.4);
	mlsp.joint_angles.push_back(1.4);
	mrsp.speed = 0.4;
	mlsp.speed = 0.4;

	while(ros::ok()){
		ros::spinOnce();
	//	if(check){
	//		if(stringname == true){
	//			ROS_INFO("GOT HEADTOUCH\n");
	//			ros::Duration(2).sleep();
	//			loop_rate.sleep();
				run = true;
	//			check = false;
	//		}
	//		else{
	//			ROS_INFO("WAITING FOR STATEPUBLISH\n");
	//			ros::Duration(2).sleep();
	//			loop_rate.sleep();
	//			run = false;
	//			check = true;
	//		}
	//	}
		// this one might need to be changed because I do not believe there is a way to determine
		// if all the buttons are being pressed at once
		loop_rate.sleep();
		ros::spinOnce();
		if(run){
			if(buttonn == 1 && buttonn == 2 && buttonn == 3 && buttonp == 1){
				ROS_INFO("TOUCHING ALL BUTTONS\n");
				talk.data = "Why are you touching all of my buttons?";
				pub.publish(talk);
				ros::Duration(1).sleep();
			}
			else if(buttonn == 1 && buttonp == 1){
				ROS_INFO("TOUCHING FRONT SENSOR\n");
				loop_rate.sleep();
				talk.data = "OW! Get your hands off my front button!";
				pub.publish(talk);
				mrsp.joint_angles[0] = -1.4;
				mlsp.joint_angles[0] = -1.4;
				move.publish(mrsp);
				move.publish(mlsp);
				ros::Duration(2).sleep();
				mrsp.joint_angles[0] = 1.4;
				mlsp.joint_angles[0] = 1.4;
				move.publish(mrsp);
				move.publish(mlsp);
				ros::Duration(3).sleep();
				ros::spinOnce();
				if(buttonn == 1 && buttonp == 1){
					ROS_INFO("STILL TOUCHING IT\n");
					loop_rate.sleep();
					talk.data = "Did you not hear me the first time?";
					pub.publish(talk);
					ros::Duration(1).sleep();
					talk.data = "Get your hands off me!";
					pub.publish(talk);
					ros::Duration(4).sleep();
					ros::spinOnce();
				}
				ros::Duration(2).sleep();
				if(buttonn == 1 && buttonp == 0){
					talk.data = "Oh why thank you now don't do that again.";
					pub.publish(talk);
					ros::Duration(4).sleep();
				}
				else{
					talk.data = "Oh my just take your hands off of me please!";
					pub.publish(talk);
					ros::Duration(2).sleep();
				}
			}	
			else if(buttonn == 2 && buttonp == 1){
				ROS_INFO("TOUCHING MIDDLE SENSOR\n");
				loop_rate.sleep();
				talk.data = "AAH! Get your hands off my middle button!";
				pub.publish(talk);
				mrsp.joint_angles[0] = -1.4;
				mlsp.joint_angles[0] = -1.4;
				move.publish(mrsp);
				move.publish(mlsp);
				ros::Duration(2).sleep();
				mrsp.joint_angles[0] = 1.4;
				mlsp.joint_angles[0] = 1.4;
				move.publish(mrsp);
				move.publish(mlsp);
				ros::Duration(3).sleep();
				ros::spinOnce();
				if(buttonn == 2 && buttonp == 1){
					ROS_INFO("STILL TOUCHING IT\n");
					loop_rate.sleep();
					talk.data = "Did you not hear me the first time?";
					pub.publish(talk);
					ros::Duration(1).sleep();
					talk.data = "Get your hands off me!";
					pub.publish(talk);
					ros::Duration(4).sleep();
					ros::spinOnce();
				}
				ros::Duration(1).sleep();
				if(buttonn == 2 && buttonp == 0){
					talk.data = "Finally now don't do that again.";
					pub.publish(talk);
					ros::Duration(4).sleep();
				}
				else{
					talk.data = "I dislike you very much!";
					pub.publish(talk);
					ros::Duration(2).sleep();
				}
			}
			else if(buttonn == 3 && buttonp == 1){
				ROS_INFO("TOUCHING BACK SENSOR\n");
				loop_rate.sleep();
				talk.data = "STOP! Get your hands off my back button!";
				pub.publish(talk);
				mrsp.joint_angles[0] = -1.4;
				mlsp.joint_angles[0] = -1.4;
				move.publish(mrsp);
				move.publish(mlsp);
				ros::Duration(1).sleep();
				mrsp.joint_angles[0] = 1.4;
				mlsp.joint_angles[0] = 1.4;
				move.publish(mrsp);
				move.publish(mlsp);
				ros::Duration(3).sleep();
				ros::spinOnce();
				if(buttonn == 3 && buttonp == 1){
					ROS_INFO("STILL TOUCHING IT\n");
					loop_rate.sleep();
					talk.data = "Did you not hear me the first time?";
					pub.publish(talk);
					ros::Duration(1).sleep();
					talk.data = "Get your hands off me!";
					pub.publish(talk);
					ros::Duration(4).sleep();
					ros::spinOnce();
				}
				ros::Duration(1).sleep();
				if(buttonn == 3 && buttonp == 0){
					talk.data = "Holy moley now don't do that again.";
					pub.publish(talk);
					ros::Duration(2).sleep();
				}
				else{
					talk.data = "You are literally the worst!";
					pub.publish(talk);
					ros::Duration(2).sleep();
				}
			}
			else{
				ros::Duration(1).sleep();
				ros::spinOnce();
				if(i == 100){
					ROS_INFO("FINISHED EXECUTING CHECKING AGAIN\n");
					ros::Duration(2).sleep();
					check == true;
					run == false;
				}
				else if(i%10 == 0){
					talk.data = "Please do not push my buttons you will make me very upset";
					pub.publish(talk);
					ros::Duration(2).sleep();
				}
				i++;
			}	
		}
	}
	return 0;
}
