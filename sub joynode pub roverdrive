#!/usr/bin/env python
import rospy
from sensor_msgs.msg import Joy
from geometry_msgs.msg import Point
from numpy import interp


 #if turned on the direction is reversed

pwm=[0,0,0]
 
point = Point()

def find_pwmtest2(msg):
    dir_n = 0 
   
    pwm[2] = dir_n 
    pwmtotal=interp(msg.axes[2],[-1,1],[-255,255])
    
    if (pwmtotal < 0):
	dir_n = 1
 	pwm[2] = dir_n  
        pwmtotal=pwmtotal*-1
    if (msg.buttons[4] == 1):
       pwm[0]=pwmtotal
    if (msg.buttons[4] == 0):
       pwm[0]=0   
    if (msg.buttons[5] == 1):
       pwm[1]=pwmtotal
    if (msg.buttons[5] == 0):
       pwm[1]=0
      
    #rospy.loginfo("left  pwm %f",pwm[0])
    #rospy.loginfo("right pwm %f",pwm[1])
    rospy.loginfo(pwm)
	

def find_pwmtest1(msg): #1st case when 2 pwm valus are send for left ans right seperately
    pwm=[0,0]
    valL= msg.axes[1]
    valR= msg.axes[2]
    pwm[0]=interp(valL,[0,1],[0,255])
    pwm[1]=interp(valR,[0,1],[0,255])
    rospy.loginfo("left  pwm %f",pwm[0])
    rospy.loginfo("right pwm %f",pwm[1])

def transform():
    point.x = pwm[0] 
    point.y = pwm[1]
    point.z = pwm[2]  

def callback(msg):
    rate = rospy.Rate(100)
    find_pwmtest2(msg)
    transform()
    pub = rospy.Publisher('rover_drive', Point ,queue_size=100)  
    pub.publish(point)
    rate.sleep()
    #rospy.loginfo("I heard %f",msg.buttons[])
    

def listener():
    rospy.init_node('listener_joy', anonymous=True)
    rospy.Subscriber("joy", Joy, callback)
    rospy.spin()

if __name__ == '__main__':
    listener()
