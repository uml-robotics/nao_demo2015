/** This program takes advantage of the NAO's ability to play sound files
  * by playing a creepy laugh to make it appear as though the NAO
  * is in a horror movie */

// ROS INCLUDES //
#include <ros/ros.h>
#include <nao_msgs/JointAnglesWithSpeed.h>
#include <nao_msgs/TactileTouch.h>
#include <nao_msgs/FadeRGB.h>
#include <nao_interaction_msgs/AudioPlayback.h>
#include <geometry_msgs/Twist.h>
#include <std_msgs/String.h>
#include <std_msgs/Bool.h>
#include <sstream>

int button_number, button_state;

void callback( const nao_msgs::TactileTouch::ConstPtr& button ) {

  button_number = button->button;
  button_state = button->state;

}

int main(int argc, char **argv) {

  ros::init(argc, argv, "horror");
  ros::NodeHandle node;

  //All the publishers
  ros::Publisher pub_narration = node.advertise<std_msgs::String>("speech", 100);
  ros::Publisher pub_move = node.advertise<nao_msgs::JointAnglesWithSpeed>("joint_angles", 100);
  ros::Publisher pub_walk = node.advertise<geometry_msgs::Twist>("cmd_vel", 100);
  ros::Publisher pub_sing_command = node.advertise<std_msgs::Bool>("horror", 100);
  ros::Publisher pub_eye_color = node.advertise<nao_msgs::FadeRGB>("fade_rgb", 100);

  //All the subscribers
  ros::Subscriber sub_head_sensors = node.subscribe("tactile_touch", 100, callback);

  //All the services
  ros::ServiceClient client = node.serviceClient<nao_interaction_msgs::AudioPlayback>("nao_audio/play_file");

  //All the message declarations
  std_msgs::String narration;
  geometry_msgs::Twist walk;
  nao_msgs::FadeRGB leds;
  nao_interaction_msgs::AudioPlayback play;
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

    ros::spinOnce();
    loop_rate.sleep();
    
      /************************************************/
        
      //narration.data = "Stand up.";
      //pub_narration.publish(narration);
  
      walk.linear.x = 1;
      pub_walk.publish(walk);
  
      ros::Duration(1).sleep();
  
      walk.linear.x = 0;
      pub_walk.publish(walk);
  
      ros::Duration(1).sleep();
      
      /************************************************/
      
      //narration.data = "Stand up.";
      //pub_narration.publish(narration);
  
      walk.linear.x = 1;
      pub_walk.publish(walk);
  
      ros::Duration(1).sleep();
  
      walk.linear.x = 0;
      pub_walk.publish(walk);
  
      ros::Duration(3).sleep();
      
      /************************************************/
           
      //narration.data = "Reset eye color.";
      //pub_narration.publish(narration);
  
      leds.led_name = "AllLeds";
      leds.color.r = 0.0;
      leds.color.g = 0.0;
      leds.color.b = 100.0;
      leds.fade_duration.sec = 1;
       
      /************************************************/

      //narration.data = "Look forward.";
      //pub_narration.publish(narration);

      hy.joint_angles[0] = 0.0;
      hy.speed = 0.5;
      pub_move.publish(hy);

      hp.joint_angles[0] = 0.0;
      hp.speed = 0.5;
      pub_move.publish(hp);
         
      /************************************************/
     
      //narration.data = "Extend arm to grab knife.";
      //pub_narration.publish(narration);
  
      lsp.joint_angles[0] = 0.0;
      lsp.speed = 0.5;
      pub_move.publish(lsp);
  
      ley.joint_angles[0] = -1.5;
      ley.speed = 0.5;
      pub_move.publish(ley);
  
      lwy.joint_angles[0] = -1.5;
      lwy.speed = 0.5;
      pub_move.publish(lwy);
  
      lh.joint_angles[0] = 1.0;
      lh.speed = 0.5;
      pub_move.publish(lh);
  
      ros::Duration(1).sleep();
  
      narration.data = "Put the knife in my hand please!  I promise I will be careful.";
      pub_narration.publish(narration);
  
      ros::Duration(5).sleep();
      
      /************************************************/
      
      //narration.data = "Grab knife.";
      //pub_narration.publish(narration);

      lh.joint_angles[0] = 0.0;
      lh.speed = 0.5;
      pub_move.publish(lh);
   
      narration.data = "You fool!  I am secretly evil.  Now I am armed to destroy you!";
      pub_narration.publish(narration);
 
      ros::Duration(3).sleep();
      
      /************************************************/
      //narration.data = "Turn Red.";
      //pub_narration.publish(narration);
  
      leds.led_name = "AllLeds";
      leds.color.r = 100.0;
      leds.color.g = 0.0;
      leds.color.b = 0.0;
      leds.fade_duration.sec = 1;
       
      /************************************************/
      //narration.data = "Arranging arms.";
      //pub_narration.publish(narration);
  
      lsp.joint_angles[0] = -1.0;
      lsp.speed = 0.1;
      pub_move.publish(lsp);

      lsr.joint_angles[0] = 0.25;
      lsr.speed = 0.1;
      pub_move.publish(lsr);

      ley.joint_angles[0] = -0.55;
      ley.speed = 0.1;
      pub_move.publish(ley);

      ler.joint_angles[0] = -0.75;
      ler.speed = 0.1;
      pub_move.publish(ler);
  
      lwy.joint_angles[0] = -1.5;
      lwy.speed = 0.1;
      pub_move.publish(lwy);


      rsp.joint_angles[0] = 1.8;
      rsp.speed = 0.1;
      pub_move.publish(rsp);
  
      rsr.joint_angles[0] = 0.0;
      rsr.speed = 0.1;
      pub_move.publish(rsr);
  
      rey.joint_angles[0] = 2.0;
      rey.speed = 0.1;
      pub_move.publish(rey);
  
      rer.joint_angles[0] = 1.5;
      rer.speed = 0.1;
      pub_move.publish(rer);
  
      rh.joint_angles[0] = 0.0;
      rh.speed = 0.1;
      pub_move.publish(rh);
  
      ros::Duration(3).sleep();
          
      /************************************************/
   
      //narration.data = "Look at hand.";
      //pub_narration.publish(narration);

      hy.joint_angles[0] = 0.55;
      hy.speed = 0.1;
      pub_move.publish(hy);

      hp.joint_angles[0] = -0.65;
      hp.speed = 0.1;
      pub_move.publish(hp);
 
      ros::Duration(2).sleep();
   
      /************************************************/
   
      //narration.data = "Evil laugh.";
      //pub_narration.publish(narration);
   
	pub_eye_color.publish(leds);
      play.request.file_path.data = "/music/evil_laugh.wav";
      client.call(play);
  
      ros::Duration(2).sleep();
 
      /************************************************/
  
      //narration.data = "Look forward.";
      //pub_narration.publish(narration);

      hy.joint_angles[0] = 0.0;
      hy.speed = 0.3;
      pub_move.publish(hy);

      hp.joint_angles[0] = 0.0;
      hp.speed = 0.3;
      pub_move.publish(hp);
 
      ros::Duration(1).sleep();
        
      /************************************************/

      //narration.data = "Arranging arms.";
      //pub_narration.publish(narration);
  
      lsp.joint_angles[0] = -1.0;
      lsp.speed = 0.1;
   
      //narration.data = "Lower knife.";
      //pub_narration.publish(narration);

      lsp.joint_angles[0] = 1.6;
      lsp.speed = 0.5;
      pub_move.publish(lsp);

      lsr.joint_angles[0] = 0.0;
      lsr.speed = 0.5;
      pub_move.publish(lsr);

      ley.joint_angles[0] = 0.0;
      ley.speed = 0.5;
      pub_move.publish(ley);

      ler.joint_angles[0] = 0.0;
      ler.speed = 0.5;
      pub_move.publish(ler);
   
      //lwy.joint_angles[0] = -1.5;
      //lwy.speed = 0.5;
      //pub_move.publish(lwy);
      lwy.joint_angles[0] = -0.5;
      lwy.speed = 0.5;
      pub_move.publish(lwy);

      rsp.joint_angles[0] = 1.6;
      rsp.speed = 0.5;
      pub_move.publish(rsp);

      rsr.joint_angles[0] = 0.0;
      rsr.speed = 0.5;
      pub_move.publish(rsr);
  
      rey.joint_angles[0] = 0.0;
      rey.speed = 0.5;
      pub_move.publish(rey);
  
      rer.joint_angles[0] = 0.0;
      rer.speed = 0.5;
      pub_move.publish(rer);
  
      rh.joint_angles[0] = 0.0;
      rh.speed = 0.5;
      pub_move.publish(rh);
  
      ros::Duration(2).sleep();

      /************************************************/
      //narration.data = "Walk.";
      //pub_narration.publish(narration);
  
        leds.led_name = "AllLeds";
        leds.color.r = 100.0;
        leds.color.g = 0.0;
        leds.color.b = 0.0;
        leds.fade_duration.sec = 1;
        pub_eye_color.publish(leds);
        walk.linear.x = 1;
        pub_walk.publish(walk);
  
        /************************************************/
       
        /************************************************/
       
        /************************************************/
 
        //narration.data = "Walk.";
        //pub_narration.publish(narration);

        walk.linear.x = 0.3;
        pub_walk.publish(walk);
 
	play.request.file_path.data = "/music/creep.ogg";
        client.call(play);
     
        ros::Duration(8).sleep();

        walk.linear.x = 0;
        pub_walk.publish(walk);
       
        ros::Duration(2).sleep();
     
        narration.data = "Prepare to die!.";
        pub_narration.publish(narration);
	ros::Duration(1).sleep();
	//play.request.file_path.data = "/music/evil_laugh.wav";
    	//client.call(play);
 

        /************************************************/
 
        //narration.data = "Raise knife.";
        //pub_narration.publish(narration);
  
        lsp.joint_angles[0] = -1.0;
        lsp.speed = 0.4;
        pub_move.publish(lsp);
  
        lsr.joint_angles[0] = 0.25;
        lsr.speed = 0.1;
        pub_move.publish(lsr);

        ley.joint_angles[0] = -0.55;
        ley.speed = 0.1;
        pub_move.publish(ley);

        ler.joint_angles[0] = -0.75;
        ler.speed = 0.1;
        pub_move.publish(ler);
  
        lwy.joint_angles[0] = -0.5;
        lwy.speed = 0.1;
        pub_move.publish(lwy);


        rsp.joint_angles[0] = 1.8;
        rsp.speed = 0.1;
        pub_move.publish(rsp);
  
        rsr.joint_angles[0] = 0.0;
        rsr.speed = 0.1;
        pub_move.publish(rsr);
  
        rey.joint_angles[0] = 2.0;
        rey.speed = 0.1;
        pub_move.publish(rey);
  
        rer.joint_angles[0] = 1.5;
        rer.speed = 0.1;
        pub_move.publish(rer);
  
        rh.joint_angles[0] = 0.0;
        rh.speed = 0.1;
        pub_move.publish(rh);
  
        ros::Duration(1).sleep();
            
        /************************************************/
    
        //narration.data = "Look at hand.";
        //pub_narration.publish(narration);

        hy.joint_angles[0] = 0.55;
        hy.speed = 0.1;
        pub_move.publish(hy);
 
        hp.joint_angles[0] = -0.65;
        hp.speed = 0.1;
        pub_move.publish(hp);
 
        /************************************************/
           
        //narration.data = "Turn Red.";
        //pub_narration.publish(narration);
  
        leds.led_name = "AllLeds";
        leds.color.r = 100.0;
        leds.color.g = 0.0;
        leds.color.b = 0.0;
        leds.fade_duration.sec = 1;
        pub_eye_color.publish(leds);
       
        /************************************************/
  
        //narration.data = "Evil laugh.";
        //pub_narration.publish(narration);
     
        play.request.file_path.data = "/music/evil_laugh.wav";
        client.call(play);
  
        ros::Duration(1).sleep();
 
        /************************************************/
   
        //narration.data = "Look forward.";
        //pub_narration.publish(narration);

        hy.joint_angles[0] = 0.0;
        hy.speed = 0.3;
        pub_move.publish(hy);

        hp.joint_angles[0] = 0.0;
        hp.speed = 0.3;
        pub_move.publish(hp);
 
        ros::Duration(1).sleep();
        
        /************************************************/
  	
        lsp.joint_angles[0] = 1.6;
        lsp.speed = 0.9;
        pub_move.publish(lsp);

        lsr.joint_angles[0] = 0.0;
        lsr.speed = 0.5;
        pub_move.publish(lsr);

        ley.joint_angles[0] = 0.0;
        ley.speed = 0.5;
        pub_move.publish(ley);

        ler.joint_angles[0] = 0.0;
        ler.speed = 0.5;
        pub_move.publish(ler);
   
        lwy.joint_angles[0] = -0.5;
        lwy.speed = 0.5;
        pub_move.publish(lwy);


        rsp.joint_angles[0] = 1.6;
        rsp.speed = 0.5;
        pub_move.publish(rsp);
  
        rsr.joint_angles[0] = 0.0;
        rsr.speed = 0.5;
        pub_move.publish(rsr);
  
        rey.joint_angles[0] = 0.0;
        rey.speed = 0.5;
        pub_move.publish(rey);
  
        rer.joint_angles[0] = 0.0;
        rer.speed = 0.5;
        pub_move.publish(rer);
  
        rh.joint_angles[0] = 0.0;
        rh.speed = 0.5;
        pub_move.publish(rh);

	ros::Duration(0.25).sleep(); 
 
	play.request.file_path.data = "/music/knife_sound.ogg";
        client.call(play);
	
	ros::Duration(1).sleep();

	narration.data = "So long.";
        pub_narration.publish(narration);

        /************************************************/
 
	ros::shutdown();

        //narration.data = "Walk.";
        //pub_narration.publish(narration);

        //walk.linear.x = 0.3;
        //pub_walk.publish(walk);
      
        //ros::Duration(4).sleep();

        //walk.linear.x = 0;
        //pub_walk.publish(walk);
       
        //ros::Duration(2).sleep();
     
        /************************************************/
  }


  return 0;

}
