# Made by Vishal Sharma (https://github.com/VishalSharma0309)

#!/bin/bash
# script to uninstall ROS from the system completely and saving the current workspace in the process

#use sudo to run this command
if [ "$(id -u)" -ne 0 ]
        then echo "Must be root"
        exit
fi

echo "Removing ROS-melodic" 
sudo apt-get purge ros-* 

echo "Removing configuration files"
sudo apt-get autoremove

echo "Rebooting Device"
sudo reboot -h now

