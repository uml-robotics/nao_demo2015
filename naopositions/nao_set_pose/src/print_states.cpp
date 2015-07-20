#include <ros/ros.h>
#include <nao_msgs/JointAnglesWithSpeed.h>
#include <std_msgs/String.h>
#include <sensor_msgs/JointState.h>
#include <sstream>
#include <custom_msgs/states.h>

custom_msgs::states controlmsgs;

float hy_state, hp_state, lsp_state, rsp_state,
	lsr_state, rsr_state, ley_state, rey_state,
	ler_state, rer_state, lwy_state, rwy_state,
	lh_state, rh_state, lhyp_state, rhyp_state,
	lhp_state, rhp_state, lhr_state, rhr_state,
	lkp_state, rkp_state, lap_state, rap_state,
	lar_state, rar_state;

void callback(const sensor_msgs::JointState::ConstPtr& Joints){
  	hy_state = Joints->position[0];
  	hp_state = Joints->position[1];
  	lsp_state = Joints->position[2];
  	lsr_state = Joints->position[3];
  	ley_state = Joints->position[4];
  	ler_state = Joints->position[5];
  	lwy_state = Joints->position[6];
  	lh_state = Joints->position[7];
  	lhyp_state = Joints->position[8];
  	lhr_state = Joints->position[9];
  	lhp_state = Joints->position[10];
  	lkp_state = Joints->position[11];
  	lap_state = Joints->position[12];
  	lar_state = Joints->position[13];
  	rhyp_state = Joints->position[14];
  	rhr_state = Joints->position[15];
  	rhp_state = Joints->position[16];
  	rkp_state = Joints->position[17];
  	rap_state = Joints->position[18];
  	rar_state = Joints->position[19];
  	rsp_state = Joints->position[20];
  	rsr_state = Joints->position[21];
  	rey_state = Joints->position[22];
  	rer_state = Joints->position[23];
  	rwy_state = Joints->position[24];
  	rh_state = Joints->position[25];
	
}

void controlcb(const custom_msgs::states States){
	controlmsgs = States;
}

int main(int argc, char **argv) {

	ros::init(argc, argv, "set_pose");
  	ros::NodeHandle node;

  	//All the publishers
  	ros::Publisher pub_narration = node.advertise<std_msgs::String>("speech", 100);
  	ros::Publisher pub_move = node.advertise<nao_msgs::JointAnglesWithSpeed>("joint_angles", 100);
  	ros::Publisher pub_contrl = node.advertise<custom_msgs::states>("/control_msgs", 100);

  	//All the subscribers
  	ros::Subscriber sub_joints = node.subscribe("joint_states", 100, callback);
  	ros::Subscriber sub_ctrl = node.subscribe("/control_msgs", 100, controlcb);
	
  	//All the message declarations
  	std_msgs::String narration;
  	nao_msgs::JointAnglesWithSpeed hy;
  	nao_msgs::JointAnglesWithSpeed hp;
  	nao_msgs::JointAnglesWithSpeed lsp;
  	nao_msgs::JointAnglesWithSpeed rsp;
  	nao_msgs::JointAnglesWithSpeed lsr;
  	nao_msgs::JointAnglesWithSpeed rsr;
  	nao_msgs::JointAnglesWithSpeed ley;
  	nao_msgs::JointAnglesWithSpeed rey;
  	nao_msgs::JointAnglesWithSpeed ler;
  	nao_msgs::JointAnglesWithSpeed rer;
  	nao_msgs::JointAnglesWithSpeed lwy;
  	nao_msgs::JointAnglesWithSpeed rwy;
  	nao_msgs::JointAnglesWithSpeed lh;
  	nao_msgs::JointAnglesWithSpeed rh;
  	nao_msgs::JointAnglesWithSpeed lhyp;
  	nao_msgs::JointAnglesWithSpeed rhyp;
  	nao_msgs::JointAnglesWithSpeed lhp;
  	nao_msgs::JointAnglesWithSpeed rhp;
  	nao_msgs::JointAnglesWithSpeed lhr;
  	nao_msgs::JointAnglesWithSpeed rhr;
  	nao_msgs::JointAnglesWithSpeed lkp;
  	nao_msgs::JointAnglesWithSpeed rkp;
  	nao_msgs::JointAnglesWithSpeed lap;
  	nao_msgs::JointAnglesWithSpeed rap;
  	nao_msgs::JointAnglesWithSpeed lar;
  	nao_msgs::JointAnglesWithSpeed rar;

  	//All check variable declarations
  	bool all_good = false, hy_check = false, hp_check = false,
       		lsp_check = false, rsp_check = false, lsr_check = false,
       		rsr_check = false, ley_check = false, rey_check = false,
       		ler_check = false, rer_check = false, lwy_check = false,
       		rwy_check = false, lh_check = false, rh_check = false,
       		lhyp_check = false, rhyp_check = false, lhp_check = false,
       		rhp_check = false, lhr_check = false, rhr_check = false,
       		lkp_check = false, rkp_check = false, lap_check = false,
       		rap_check = false, lar_check = false, rar_check = false;

	int i = 0;

  	//All joint name statements
  	hy.joint_names.push_back("HeadYaw");
  	hp.joint_names.push_back("HeadPitch");
  	lsp.joint_names.push_back("LShoulderPitch");
  	rsp.joint_names.push_back("RShoulderPitch");
  	lsr.joint_names.push_back("LShoulderRoll");
  	rsr.joint_names.push_back("RShoulderRoll");
  	ley.joint_names.push_back("LElbowYaw");
  	rey.joint_names.push_back("RElbowYaw");
  	ler.joint_names.push_back("LElbowRoll");
  	rer.joint_names.push_back("RElbowRoll");
  	lwy.joint_names.push_back("LWristYaw");
  	rwy.joint_names.push_back("RWristYaw");
  	lh.joint_names.push_back("LHand");
  	rh.joint_names.push_back("RHand");
  	lhyp.joint_names.push_back("LHipYawPitch");
  	rhyp.joint_names.push_back("RHipYawPitch");
  	lhp.joint_names.push_back("LHipPitch");
  	rhp.joint_names.push_back("RHipPitch");
  	lhr.joint_names.push_back("LHipRoll");
  	rhr.joint_names.push_back("RHipRoll");
  	lkp.joint_names.push_back("LKneePitch");
  	rkp.joint_names.push_back("RKneePitch");
  	lap.joint_names.push_back("LAnklePitch");
  	rap.joint_names.push_back("RAnklePitch");
  	lar.joint_names.push_back("LAnkleRoll");
  	rar.joint_names.push_back("RAnkleRoll");
	
  	//All joint angle statements
  	hy.joint_angles.push_back(0);
  	hp.joint_angles.push_back(0);
  	lsp.joint_angles.push_back(0);
  	rsp.joint_angles.push_back(0);
  	lsr.joint_angles.push_back(0);
  	rsr.joint_angles.push_back(0);
  	ley.joint_angles.push_back(0);
  	rey.joint_angles.push_back(0);
  	ler.joint_angles.push_back(0);
  	rer.joint_angles.push_back(0);
  	lwy.joint_angles.push_back(0);
  	rwy.joint_angles.push_back(0);
  	lh.joint_angles.push_back(0);
  	rh.joint_angles.push_back(0);
  	lhyp.joint_angles.push_back(0);
  	rhyp.joint_angles.push_back(0);
  	lhp.joint_angles.push_back(0);
  	rhp.joint_angles.push_back(0);
  	lhr.joint_angles.push_back(0);
  	rhr.joint_angles.push_back(0);
  	lkp.joint_angles.push_back(0);
  	rkp.joint_angles.push_back(0);
  	lap.joint_angles.push_back(0);
  	rap.joint_angles.push_back(0);
  	lar.joint_angles.push_back(0);
  	rar.joint_angles.push_back(0);

  	ros::Rate loop_rate(10); 

	while (ros::ok()) {

		ros::spinOnce();
		loop_rate.sleep();

    		/************************************************/
    
  		ROS_INFO("HeadYaw State: [ %.2f ]\t", hy_state);
  		ROS_INFO("HeadPitch State: [ %.2f ]\n", hp_state);
  		ROS_INFO("LShoulderPitch State: [ %.2f ]\t", lsp_state);
  		ROS_INFO("RShoulderPitch State: [ %.2f ]\r", rsp_state);
  		ROS_INFO("LShoulderRoll State: [ %.2f ]\t", lsr_state);
  		ROS_INFO("RShoulderRoll State: [ %.2f ]\r", rsr_state);
  		ROS_INFO("LElbowYaw State: [ %.2f ]\t", ley_state);
  		ROS_INFO("RElbowYaw State: [ %.2f ]\r", rey_state);
  		ROS_INFO("LElbowRoll State: [ %.2f ]\t", ler_state);
  		ROS_INFO("RElbowRoll State: [ %.2f ]\r", rer_state);
  		ROS_INFO("LWristYaw State: [ %.2f ]\t", lwy_state);
  		ROS_INFO("RWristYaw State: [ %.2f ]\r", rwy_state);
  		ROS_INFO("LHand State: [ %.2f ]\t", lh_state);
  		ROS_INFO("RHand State: [ %.2f ]\r", rh_state);
  		ROS_INFO("LHipYawPitch State: [ %.2f ]\t", lhyp_state);
  		ROS_INFO("RHipYawPitch State: [ %.2f ]\r", rhyp_state);
  		ROS_INFO("LHipPitch State: [ %.2f ]\t", lhp_state);
  		ROS_INFO("RHipPitch State: [ %.2f ]\r", rhp_state);
  		ROS_INFO("LHipRoll State: [ %.2f ]\t", lhr_state);
  		ROS_INFO("RHipRoll State: [ %.2f ]\r", rhr_state);
  		ROS_INFO("LKneePitch State: [ %.2f ]\t", lkp_state);
  		ROS_INFO("RKneePitch State: [ %.2f ]\r", rkp_state);
  		ROS_INFO("LAnklePitch State: [ %.2f ]\t", lap_state);
  		ROS_INFO("RAnklePitch State: [ %.2f ]\r", rap_state);
  		ROS_INFO("LAnkleRoll State: [ %.2f ]\t", lar_state);
  		ROS_INFO("RAnkleRoll State: [ %.2f ]\r", rar_state);

  		/************************************************/

 	}


 	return 0;

}