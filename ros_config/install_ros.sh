# Made by Vishal Sharma (https://github.com/VishalSharma0309)

#! /bin/bash
# script to install ROS-melodic directly into a linux system
# tested on Ubuntu 18.04.02

#use sudo to run this command
if [ "$(id -u)" -ne 0 ]
        then echo "Must be root"
        exit
fi

# Setup your computer to accept software from packages.ros.org
sudo sh -c 'echo "deb http://packages.ros.org/ros/ubuntu $(lsb_release -sc) main" > /etc/apt/sources.list.d/ros-latest.list'

# Setting up the keys
sudo apt-key adv --keyserver 'hkp://keyserver.ubuntu.com:80' --recv-key C1CF6E31E6BADE8868B172B4F42ED6FBAB17C654

#else
#hpk://pgp.mit.edu:80
#or 
#hkp://keyserver.ubuntu.com:80

# Installation
sudo apt-get update
# Full-Desktop Install
sudo apt install ros-melodic-desktop-full

# Initialize rosdep
sudo rosdep init
rosdep update

# Environment setup
echo "source /opt/ros/melodic/setup.bash" >> ~/.bashrc
source ~/.bashrc

# Dependencies for building packages
sudo apt install python-rosinstall python-rosinstall-generator python-wstool build-essential


