#include <ros/ros.h>
#include <nao_msgs/JointAnglesWithSpeed.h>
#include <std_msgs/String.h>
#include <sstream>


int main(int argc, char **argv) {

  ros::init(argc, argv, "move_robot");
  ros::NodeHandle node;

  //All the publishers
  ros::Publisher pub_narration = node.advertise<std_msgs::String>("speech", 100);
  ros::Publisher pub_move = node.advertise<nao_msgs::JointAnglesWithSpeed>("joint_angles", 100);

  //All the message declarations
  std_msgs::String narration;
  //nao_msgs::JointAnglesWithSpeed hy;
  //nao_msgs::JointAnglesWithSpeed hp;
  //nao_msgs::JointAnglesWithSpeed lsp;
  //nao_msgs::JointAnglesWithSpeed rsp;
  //nao_msgs::JointAnglesWithSpeed lsr;
  //nao_msgs::JointAnglesWithSpeed rsr;
  //nao_msgs::JointAnglesWithSpeed ley;
  //nao_msgs::JointAnglesWithSpeed rey;
  //nao_msgs::JointAnglesWithSpeed ler;
  //nao_msgs::JointAnglesWithSpeed rer;
  //nao_msgs::JointAnglesWithSpeed lwy;
  //nao_msgs::JointAnglesWithSpeed rwy;
  //nao_msgs::JointAnglesWithSpeed lh;
  //nao_msgs::JointAnglesWithSpeed rh;
  //nao_msgs::JointAnglesWithSpeed lhyp;
  //nao_msgs::JointAnglesWithSpeed rhyp;
  nao_msgs::JointAnglesWithSpeed lhr;
  nao_msgs::JointAnglesWithSpeed rhr;
  nao_msgs::JointAnglesWithSpeed lhp;
  nao_msgs::JointAnglesWithSpeed rhp;
  nao_msgs::JointAnglesWithSpeed lkp;
  nao_msgs::JointAnglesWithSpeed rkp;
  nao_msgs::JointAnglesWithSpeed lap;
  nao_msgs::JointAnglesWithSpeed rap;
  nao_msgs::JointAnglesWithSpeed lar;
  nao_msgs::JointAnglesWithSpeed rar;

  //All joint name statements
  //hy.joint_names.push_back("HeadYaw");
  //hp.joint_names.push_back("HeadPitch");
  //lsp.joint_names.push_back("LShoulderPitch");
  //rsp.joint_names.push_back("RShoulderPitch");
  //lsr.joint_names.push_back("LShoulderRoll");
  //rsr.joint_names.push_back("RShoulderRoll");
  //ley.joint_names.push_back("LElbowYaw");
  //rey.joint_names.push_back("RElbowYaw");
  //ler.joint_names.push_back("LElbowRoll");
  //rer.joint_names.push_back("RElbowRoll");
  //lwy.joint_names.push_back("LWristYaw");
  //rwy.joint_names.push_back("RWristYaw");
  //lh.joint_names.push_back("LHand");
  //rh.joint_names.push_back("RHand");
  //lhyp.joint_names.push_back("LHipYawPitch");
  //rhyp.joint_names.push_back("RHipYawPitch");
  lhr.joint_names.push_back("LHipRoll");
  rhr.joint_names.push_back("RHipRoll");
  lhp.joint_names.push_back("LHipPitch");
  rhp.joint_names.push_back("RHipPitch");
  lkp.joint_names.push_back("LKneePitch");
  rkp.joint_names.push_back("RKneePitch");
  lap.joint_names.push_back("LAnklePitch");
  rap.joint_names.push_back("RAnklePitch");
  lar.joint_names.push_back("LAnkleRoll");
  rar.joint_names.push_back("RAnkleRoll");

  //All joint angle statements
  //hy.joint_angles.push_back(0);
  //hp.joint_angles.push_back(0);
  //lsp.joint_angles.push_back(0);
  //rsp.joint_angles.push_back(0);
  //lsr.joint_angles.push_back(0);
  //rsr.joint_angles.push_back(0);
  //ley.joint_angles.push_back(0);
  //rey.joint_angles.push_back(0);
  //ler.joint_angles.push_back(0);
  //rer.joint_angles.push_back(0);
  //lwy.joint_angles.push_back(0);
  //rwy.joint_angles.push_back(0);
  //lh.joint_angles.push_back(0);
  //rh.joint_angles.push_back(0);
  //lhyp.joint_angles.push_back(0);
  //rhyp.joint_angles.push_back(0);
  lhr.joint_angles.push_back(0);
  rhr.joint_angles.push_back(0);
  lhp.joint_angles.push_back(0);
  rhp.joint_angles.push_back(0);
  lkp.joint_angles.push_back(0);
  rkp.joint_angles.push_back(0);
  lap.joint_angles.push_back(0);
  rap.joint_angles.push_back(0);
  lar.joint_angles.push_back(0);
  rar.joint_angles.push_back(0);


  ros::Rate loop_rate(15); 
  while (ros::ok()) {

   /************************************************/
    
    //ros::Duration(3).sleep();

   /************************************************/

    //narration.data = "Lean right.";
    pub_narration.publish(narration);

    lhr.joint_angles[0] = 0.3;
    lar.joint_angles[0] = -0.3;
    lhr.speed = 0.1;
    lar.speed = 0.1;
    pub_move.publish(lhr);
    pub_move.publish(lar);

    rhr.joint_angles[0] = 0.0;
    rar.joint_angles[0] = 0.0;
    rhr.speed = 0.1;
    rar.speed = 0.1;
    pub_move.publish(rhr);
    pub_move.publish(rar);

    ros::Duration(2).sleep();
 
   /************************************************/

    //narration.data = "Stomp left.";
    pub_narration.publish(narration);

    lhp.joint_angles[0] = -0.5;
    lhp.speed = 0.1;
    pub_move.publish(lhp);

    lkp.joint_angles[0] = 1.2;
    lkp.speed = 0.1;
    pub_move.publish(lkp);

    lap.joint_angles[0] = -0.7;
    lap.speed = 0.1;
    pub_move.publish(lap);

    ros::Duration(0.2).sleep();


    lhp.joint_angles[0] = -0.2;
    lhp.speed = 0.1;
    pub_move.publish(lhp);

    lkp.joint_angles[0] = 0.4;
    lkp.speed = 0.1;
    pub_move.publish(lkp);

    lap.joint_angles[0] = -0.2;
    lap.speed = 0.1;
    pub_move.publish(lap);

    ros::Duration(0.2).sleep();
 
   /************************************************/

    //narration.data = "Lean left.";
    pub_narration.publish(narration);

    lhr.joint_angles[0] = 0.0;
    lar.joint_angles[0] = 0.0;
    lhr.speed = 0.1;
    lar.speed = 0.1;
    pub_move.publish(lhr);
    pub_move.publish(lar);

    rhr.joint_angles[0] = -0.3;
    rar.joint_angles[0] = 0.3;
    rhr.speed = 0.1;
    rar.speed = 0.1;
    pub_move.publish(rhr);
    pub_move.publish(rar);

    ros::Duration(2).sleep();
 
   /************************************************/

    //narration.data = "Stomp right.";
    pub_narration.publish(narration);

    rhp.joint_angles[0] = -0.5;
    rhp.speed = 0.1;
    pub_move.publish(rhp);

    rkp.joint_angles[0] = 1.2;
    rkp.speed = 0.1;
    pub_move.publish(rkp);

    rap.joint_angles[0] = -0.7;
    rap.speed = 0.1;
    pub_move.publish(rap);

    ros::Duration(0.2).sleep();


    rhp.joint_angles[0] = -0.2;
    rhp.speed = 0.1;
    pub_move.publish(rhp);

    rkp.joint_angles[0] = 0.4;
    rkp.speed = 0.1;
    pub_move.publish(rkp);

    rap.joint_angles[0] = -0.2;
    rap.speed = 0.1;
    pub_move.publish(rap);

    ros::Duration(0.2).sleep();
 
   /************************************************/
 
    //ros::Duration(3).sleep();

   /************************************************/
   
    ros::spinOnce();
    loop_rate.sleep();

  }


  return 0;

}