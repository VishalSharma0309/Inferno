# Made by Vishal Sharma (https://github.com/VishalSharma0309)

#! /bin/bash
# script to install ROS-kinetic directly into a linux system
# tested on Ubuntu 16.04.02

# ROS kinetic ONLY supports Wily (Ubuntu 15.10), Xenial (Ubuntu 16.04) and Jessie (Debian 8) for debian packages 

#use sudo to run this command
if [ "$(id -u)" -ne 0 ]
        then echo "Must be root"
        exit
fi

# check for entries in ~/bash.c

# check for cmake file and delete it 

# Setup your sources.list
sudo sh -c 'echo "deb http://packages.ros.org/ros/ubuntu $(lsb_release -sc) main" > /etc/apt/sources.list.d/ros-latest.list' 

# Set up your keys 
sudo apt-key adv --keyserver 'hkp://keyserver.ubuntu.com:80' --recv-key C1CF6E31E6BADE8868B172B4F42ED6FBAB17C654

# Installation
sudo apt-get update
sudo apt-get install ros-kinetic-desktop-full 

# Initialize rosdep
sudo rosdep init
rosdep update

# Environment setup
echo "source /opt/ros/kinetic/setup.bash" >> ~/.bashrc
source ~/.bashrc

# Dependencies for building packages
sudo apt install python-rosinstall python-rosinstall-generator python-wstool build-essential 




