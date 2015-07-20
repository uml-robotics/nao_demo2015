#include "ros/ros.h"
#include "std_msgs/String.h"
#include <iostream>
#include <sstream>

int main(int argc, char ** argv){
	ros::init(argc, argv, "Mathmateical");
	ros::NodeHandle n;
	ros::Rate loop_rate(10);

	ros::Publisher talk = n.advertise<std_msgs::String>("speech", 100);
	
	std_msgs::String words;
	
	std::ostringstream os1, os2, os3;

	int val1, val2, add, sub, mult, div, menu;

	while(ros::ok()){
		std::cout << "Please enter what type of math you would like me to computer\n";
		std::cout << "1 for Addition\t\t2 for Subtraction\n3 for Multiplication\t4 for Division\n";
		std::cin >> menu;
		std::cout << "\n\n";
		switch(menu){
			case 1:
				std::cout << "Please enter the first number you'd like me to add:\n";
				std::cin >> val1;
				os1 << val1;
				std::cout << "Please enter the second number you'd like me to add:\n";
				std::cin >> val2;
				os2 << val2;
				ros::Duration(2).sleep();
				std::cout << "You entered " << val1 << " and " << val2 << "\n";
				add = val1 + val2;
				os3 << add;
				std::cout << val1 << " + " << val2 << " = " << add << "\n";
				words.data = os1.str();
				talk.publish(words);
				words.data = "plus";
				talk.publish(words);
				words.data = os2.str();
				talk.publish(words);
				words.data = "equals";
				talk.publish(words);
				words.data = os3.str();
				talk.publish(words);
				ros::Duration(2).sleep();
				os1.clear();
				os1.str("");
				os2.clear();
				os2.str("");
				os3.clear();
				os3.str("");
				break;

			case 2:
				std::cout << "Please enter the first number you'd like me to subtract:\n";
				std::cin >> val1;
				os1 << val1;
				std::cout << "Please enter the second number you'd like me to subtract:\n";
				std::cin >> val2;
				os2 << val2;
				ros::Duration(2).sleep();
				std::cout << "You entered " << val1 << " and " << val2 << "\n";
				sub = val1 - val2;
				os3 << sub;
				std::cout << val1 << " - " << val2 << " = " << sub << "\n";
				words.data = os1.str();
				talk.publish(words);
				words.data = "minus";
				talk.publish(words);
				words.data = os2.str();
				talk.publish(words);
				words.data = "equals";
				talk.publish(words);
				words.data = os3.str();
				talk.publish(words);
				ros::Duration(2).sleep();
				os1.clear();
				os1.str("");
				os2.clear();
				os2.str("");
				os3.clear();
				os3.str("");
				break;

			case 3:
				std::cout << "Please enter the first number you'd like me to multiply:\n";
				std::cin >> val1;
				os1 << val1;
				std::cout << "Please enter the second number you'd like me to multiply:\n";
				std::cin >> val2;
				os2 << val2;
				ros::Duration(2).sleep();
				std::cout << "You entered " << val1 << " and " << val2 << "\n";
				mult = val1 * val2;
				os3 << mult;
				std::cout << val1 << " * " << val2 << " = " << mult << "\n";
				words.data = os1.str();
				talk.publish(words);
				words.data = "times";
				talk.publish(words);
				words.data = os2.str();
				talk.publish(words);
				words.data = "equals";
				talk.publish(words);
				words.data = os3.str();
				talk.publish(words);
				ros::Duration(2).sleep();
				os1.clear();
				os1.str("");
				os2.clear();
				os2.str("");
				os3.clear();
				os3.str("");
				break;

			case 4:
				std::cout << "Please enter the first number you'd like me to divide:\n";
				std::cin >> val1;
				os1 << val1;
				std::cout << "Please enter the second number you'd like me to divide:\n";
				std::cin >> val2;
				os2 << val2;
				ros::Duration(2).sleep();
				std::cout << "You entered " << val1 << " and " << val2 << "\n";
				div = val1 / val2;
				os3 << div;
				std::cout << val1 << " / " << val2 << " = " << div << "\n";
				words.data = os1.str();
				talk.publish(words);
				words.data = "divided by";
				talk.publish(words);
				words.data = os2.str();
				talk.publish(words);
				words.data = "equals";
				talk.publish(words);
				words.data = os3.str();
				talk.publish(words);
				ros::Duration(2).sleep();
				os1.clear();
				os1.str("");
				os2.clear();
				os2.str("");
				os3.clear();
				os3.str("");
				break;
		}
	}		
	return 0;
}
