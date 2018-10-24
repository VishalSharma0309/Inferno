#include "Arduino.h"
#include "Invkin.h"

#include "Math.h"



//int Invkin::angle[3];
int Invkin::calctheta1(int x,int y, int z){

  
    int X = x;
    
    int Y = y;
    
    int Z = z;
    
    int theta1 = ((atan(Y/X))*180/(22/7));

    return theta1 ;

}


int Invkin::calctheta2(int x,int y, int z){
    
    
    
    int r3 ; 
    
    int X = x;
    
    int Y = y;
    
    int Z = z;
    
    r3 = sqrt(X*X + Y*Y + (Z-a1)*(Z-a1));

    int theta2 = (atan((Z-a1)/(sqrt(X*X+Y*Y)))-acos((a2*a2 + r3*r3-a3*a3)/(2*a2*r3)))*180/(22/7);
    
   

    return theta2 ;

}


int Invkin::calctheta3(int x,int y, int z){
    
    
    
    int r3 ; 
    
    int X = x;
    
    int Y = y;
    
    int Z = z;
    
    r3 = sqrt(X*X + Y*Y + (Z-a1)*(Z-a1));
   
    
    int theta3 = ((22/7)- acos((a3*a3 + a2*a2 - r3*r3)/(2*a2*a3)))*180/(22/7);   
   

    return theta3 ;
}



//int setRoboticArm(){
    
    
//}





    
    
