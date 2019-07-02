# Made by Vishal Sharma (https://github.com/VishalSharma0309)

#! /bin/bash
# script to set a ros-master for multiple machines for ROS-kinetic 
# tested on Ubuntu 16.04.02

# ROS kinetic ONLY supports Wily (Ubuntu 15.10), Xenial (Ubuntu 16.04) and Jessie (Debian 8) for debian packages 

#use sudo to run this command
#if [ "$(id -u)" -ne 0 ]
#        then echo "Must be root"
#        exit
#fi

IP_CURR=hostname\ -I
 
read -p  "ENTER THE IP OF MASTER COMPUTER:  " IP_MASTER

if ping -q -c 1 -W 1 $IP_MASTER >/dev/null; then
  echo "IPv4 is up"
else
  echo "IPv4 is down"
  exit 1
fi

read -p "ENTER THE ROS_URI OF MASTER PC: " ROS_URI
# setting ROS_IP for the current terminal
echo "Setting up ROS_IP"
export ROS_IP=$IP_CURR
echo "done"

# setting ROS_MASTER_URI for terminal
echo "Setting up ROS_MASTER_URI"
export ROS_MASTER_URI=http://$IP_MASTER:$ROS_URI
echo "done"


