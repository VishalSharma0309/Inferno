#! /bin/bash

#use sudo to run this command
if [ "$(id -u)" -ne 0 ]
	then echo "Must be root"
	exit
fi

#enabling ssh headlessly 
#you have to create a extentionless file named ssh in the boot partion of the sd card mounted with raspbian os

read -p "Enter your username as in username@device_name on your terminal: " USERNAME

if [ ! -d "/media/"$USERNAME"/boot" ] 
	# Control will enter here if $DIRECTORY doesn't exist.
	then echo "Device not connected"
	exit
fi

cd /media/"$USERNAME"/boot
touch ssh
echo "ssh file created!"

#making ethernet ip static
#host-address is a random number between 2 and 250

HOST_ADD=$(shuf -i 2-250 -n 1)
ETH0="interface eth0
       static ip_address=192.168.1.$HOST_ADD/24
       static routers=192.168.1.1
       static domain_name_servers=192.168.1.1"
if [ ! -d "/media/"$USERNAME"/rootfs/etc" ]
	# Control will enter here if $DIRECTORY doesn't exist.
	then echo "Device not connected!"
	exit
fi
cd /media/"$USERNAME"/rootfs/etc
echo "inside /rootfs/etc"

#sudo sh -c 'cat $ETH0> dhcpcd.conf'
echo "$ETH0" >> dhcpcd.conf
echo "eth0 now static! with IP 192.168.1.$HOST_ADD"


