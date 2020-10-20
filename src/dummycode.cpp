#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
#include <turtlesim/TeleportAbsolute.h>
#include <turtlesim/SetPen.h>
#include <iostream>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[]) {
  ros::init(argc, argv, "move_turtlesim");
  srand(time(NULL));

  int randomNumber1 = 0;
  int randomNumber2 = 0;
  int randomNumber3 = 0;
  float first_Float {5.0f};

  randomNumber1 = rand() %100+1;
  randomNumber2 = rand() %100+2;
  randomNumber3 = rand() %100+3;
  randomNumber1 *= 2;
  randomNumber2 *= 2;
  randomNumber3 *= 2;

  std::cout << "Hello, welcome back. Please select a box-type by typing either 1, 2, 3 or 4:";
  std::cin >> first_Float;
  std::cout << "Thanks, the changes are now applied.:" << std::endl;

  float box_size = ros::param::param("~box_size", first_Float);

  ros::NodeHandle nh;

  ros::service::waitForService("/turtle1/teleport_absolute", -1);

  ros::ServiceClient teleport_client = nh.serviceClient<turtlesim::TeleportAbsolute>("/turtle1/teleport_absolute");
  ros::ServiceClient pen_client = nh.serviceClient<turtlesim::SetPen>("/turtle1/set_pen");

   ros::Duration(2.0).sleep();

  turtlesim::SetPen pen_srv;
  pen_srv.request.off = true;
  pen_client.call(pen_srv);

  turtlesim::TeleportAbsolute srv;

  if(first_Float==1){ 
  srv.request.x = 5.5;
  srv.request.y = 5.5;
  teleport_client.call(srv);

  pen_srv.request.off = false;
  pen_srv.request.width = 10;
  pen_srv.request.r = randomNumber1;
  pen_srv.request.g = randomNumber2;
  pen_srv.request.b = randomNumber3;
  pen_client.call(pen_srv);

  srv.request.x = 0;
  srv.request.y = 5.5;
  teleport_client.call(srv);

  srv.request.x = 5.5;
  srv.request.y = 11;
  teleport_client.call(srv);

  srv.request.x = 11;
  srv.request.y = 5.5;
  teleport_client.call(srv);

  srv.request.x = 5.5;
  srv.request.y = 5.5;
  teleport_client.call(srv);

  pen_srv.request.off = true;
  pen_client.call(pen_srv);

  srv.request.x = 5.5;
  srv.request.y = 5.5;
  teleport_client.call(srv);

  pen_srv.request.off = false;
  pen_srv.request.width = 4;
  pen_srv.request.r = randomNumber1;
  pen_srv.request.g = randomNumber2;
  pen_srv.request.b = randomNumber3;
  pen_client.call(pen_srv);
  }
  if(first_Float==2){ 
  srv.request.x = 5.5;
  srv.request.y = 2.5;
  teleport_client.call(srv);

  pen_srv.request.off = false;
  pen_srv.request.width = 10;
  pen_srv.request.r = randomNumber1;
  pen_srv.request.g = randomNumber2;
  pen_srv.request.b = randomNumber3;
  pen_client.call(pen_srv);

  srv.request.x = 4;
  srv.request.y = 2.5;
  teleport_client.call(srv);

  srv.request.x = 2.5;
  srv.request.y = 4.5;
  teleport_client.call(srv);

  srv.request.x = 2.5;
  srv.request.y = 6.5;
  teleport_client.call(srv);

  srv.request.x = 4;
  srv.request.y = 8.5;
  teleport_client.call(srv);

  srv.request.x = 7;
  srv.request.y = 8.5;
  teleport_client.call(srv);

  srv.request.x = 8.5;
  srv.request.y = 6.5;
  teleport_client.call(srv);

  srv.request.x = 8.5;
  srv.request.y = 4.5;
  teleport_client.call(srv);

  srv.request.x = 7;
  srv.request.y = 2.5;
  teleport_client.call(srv);

  srv.request.x = 5.5;
  srv.request.y = 2.5;
  teleport_client.call(srv);

  pen_srv.request.off = true;
  pen_client.call(pen_srv);

  srv.request.x = 5.5;
  srv.request.y = 2.5;
  teleport_client.call(srv);

  pen_srv.request.off = false;
  pen_srv.request.width = 4;
  pen_srv.request.r = randomNumber1;
  pen_srv.request.g = randomNumber2;
  pen_srv.request.b = randomNumber3;
  pen_client.call(pen_srv);
  }
  if(first_Float==3){ 
  srv.request.x = 5.5-box_size/2;
  srv.request.y = 5.5-box_size/2;
  teleport_client.call(srv);

  pen_srv.request.off = false;
  pen_srv.request.width = 10;
  pen_srv.request.r = randomNumber1;
  pen_srv.request.g = randomNumber2;
  pen_srv.request.b = randomNumber3;
  pen_client.call(pen_srv);

  srv.request.x = 5.5-box_size/2;
  srv.request.y = 5.5+box_size/2;
  teleport_client.call(srv);

  srv.request.x = 5.5+box_size/2;
  srv.request.y = 5.5+box_size/2;
  teleport_client.call(srv);

  srv.request.x = 5.5+box_size/2;
  srv.request.y = 5.5-box_size/2;
  teleport_client.call(srv);

  srv.request.x = 5.5-box_size/2;
  srv.request.y = 5.5-box_size/2;
  teleport_client.call(srv);

  pen_srv.request.off = true;
  pen_client.call(pen_srv);

  srv.request.x = 5.5;
  srv.request.y = 5.5;
  teleport_client.call(srv);

  pen_srv.request.off = false;
  pen_srv.request.width = 4;
  pen_srv.request.r = randomNumber1;
  pen_srv.request.g = randomNumber2;
  pen_srv.request.b = randomNumber3;
  pen_client.call(pen_srv);
  }
  
  if(first_Float==4){ 
  srv.request.x = 0;
  srv.request.y = 0;
  teleport_client.call(srv);

  pen_srv.request.off = false;
  pen_srv.request.width = 100;
  pen_srv.request.r = randomNumber1;
  pen_srv.request.g = randomNumber2;
  pen_srv.request.b = randomNumber3;
  pen_client.call(pen_srv);

  srv.request.x = 0;
  srv.request.y = 11;
  teleport_client.call(srv);

  srv.request.x = 11;
  srv.request.y = 11;
  teleport_client.call(srv);

  srv.request.x = 11;
  srv.request.y = 0;
  teleport_client.call(srv);

  srv.request.x = 0;
  srv.request.y = 0;
  teleport_client.call(srv);

  pen_srv.request.off = true;
  pen_client.call(pen_srv);

  srv.request.x = 5.5;
  srv.request.y = 5.5;
  teleport_client.call(srv);

  pen_srv.request.off = false;
  pen_srv.request.width = 4;
  pen_srv.request.r = randomNumber1;
  pen_srv.request.g = randomNumber2;
  pen_srv.request.b = randomNumber3;
  pen_client.call(pen_srv);
  }

  return 0;
}