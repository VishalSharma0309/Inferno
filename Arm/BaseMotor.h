#ifndef BaseMotor_h
#define BaseMotor_h

#include "Arduino.h"

class BaseMotor
{
   public:
        BaseMotor(int mtr1,int mtr2,int pwm);
        void errorcheck();
        void forward();
        void backward();
        int checkPot();
        void brake();
        int x;
        
    
    private:
        int mtr1;
        int mtr2;
        int pwm;
        
        
};

#endif