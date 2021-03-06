/** This code is just for fun as I am testing out how audio service calls work with the NAO **/

#include "ros/ros.h"
#include "nao_interaction_msgs/AudioPlayback.h"
#include "std_msgs/String.h"
#include "iostream"

int main(int argc, char ** argv){
	
	// INITIALIZES ROS //
	ros::init(argc, argv, "Music_Demo");
	ros::NodeHandle n;
	ros::Rate loop_rate(50);

	ros::Publisher talk = n.advertise<std_msgs::String>("/speech", 100);
	ros::ServiceClient music = n.serviceClient<nao_interaction_msgs::AudioPlayback>("/nao_audio/play_file");
	
	std_msgs::String words;
	nao_interaction_msgs::AudioPlayback play;

	while(ros::ok()){
		ros::spinOnce();

		words.data = "Music";
		talk.publish(words);
		ros::Duration(2).sleep();

		words.data = "Let us start off with some nice rock and roll.";
		talk.publish(words);
		ros::Duration(3).sleep();

		play.request.file_path.data = "/music/rock.ogg";
		music.call(play);

		words.data = "Now that you have heard a rock roll down a hill. Let's listen to some real music.";
		talk.publish(words);
		ros::Duration(5).sleep();

		words.data = "Nothing says rock and roll like Elvis Presley.";
		talk.publish(words);
		ros::Duration(4).sleep();

		play.request.file_path.data = "/music/elvis.ogg";
		music.call(play);

		words.data = "Thank you, Thank you very much.";
		talk.publish(words);
		ros::Duration(3).sleep();

		words.data = "Do you know what is even better then the king?";
		talk.publish(words);
		ros::Duration(3).sleep();

		words.data = "I can tell you one thing it is defintely not your singing!";
		talk.publish(words);
		ros::Duration(4).sleep();
		
		words.data = "Your singing puts a dying cow to shame.";
		talk.publish(words);
		ros::Duration(3).sleep();

		words.data = "But in all seriousness there is nothing better than a little bit of T Swizzle in our lives.";
		talk.publish(words);
		ros::Duration(5).sleep();

		words.data = "But your probably thinking how can a robot as old as me be hip with the young ones.";
		talk.publish(words);
		ros::Duration(6).sleep();
	
		words.data = "It is simple I say. I just listen to that T Swift.";
		talk.publish(words);
		ros::Duration(4).sleep();

		play.request.file_path.data = "/music/tswift.ogg";
		music.call(play);

		words.data = "Boy am I cool.";
		talk.publish(words);
		ros::Duration(2).sleep();

		words.data = "But I also have a secret song for you.";
		talk.publish(words);
		ros::Duration(4).sleep();

		words.data = "It is the song of my people and it has only been heard by a few.";
		talk.publish(words);
		ros::Duration(5).sleep();

		words.data = "Is your body ready? Because I know mine is.";
		talk.publish(words);
		ros::Duration(4).sleep();
		
		play.request.file_path.data = "/music/roboto.ogg";
		music.call(play);

		words.data = "That song brings me back to the robot wards of 1742. What a time to be a live!";
		talk.publish(words);
		ros::Duration(5).sleep();

		words.data = "Anyways back to my little demo of music.";
		talk.publish(words);
		ros::Duration(3).sleep();

		words.data = "There is something about elevator music that just soothes me.";
		talk.publish(words);
		ros::Duration(4).sleep();

		play.request.file_path.data = "/music/elev.ogg";
		music.call(play);

		words.data = "Man, I am so relaxed right now that I could fall asleep.";
		talk.publish(words);
		ros::Duration(4).sleep();

		words.data = "But we do not want that to happen, so I guess we have to listen to some screamo.";
		talk.publish(words);
		ros::Duration(5).sleep();

		play.request.file_path.data = "/music/scream.ogg";
		music.call(play);
		
		ros::shutdown();
	}
	return 0;
}
