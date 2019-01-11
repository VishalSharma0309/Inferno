#ifndef ElbowMotor_h

#define ElbowMotor_h



#include "Arduino.h"



class ElbowMotor

{

   public:

        ElbowMotor(int dir1,int pwm);

        void errorcheck();

        void forward();

        void backward();

        int checkPot();

        void brake();

        int x;

        

    

    private:

        int dir1;

        //int dir2;

        int pwm;

        

        

};



#endif