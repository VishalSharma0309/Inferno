#ifndef Invkin_h 

#define Invkin_h


#include "Arduino.h"

class Invkin 
{
    public:
    
        
       
        int calctheta1(int  , int , int );
        
        int calctheta2(int  , int , int );
        
        int calctheta3(int  , int , int );
        
    private :
    
            int  a1 = 250;

            int  a2 = 400;

            int  a3 = 300;
            
            //SetRoboticArm();
        
        

};

#endif

