#ifndef Invkin_h

#define Invkin_h



#include "Arduino.h"



class Invkin

{

   public:
   
    Invkin(float,float,float);

    void transform();    
    
    int alpha, alpha1,alpha2,beta,gamma;
    
    
    
    private:
    
    void trigono_xyz(float x, float y, float z);
    
    const float cx=2; //cox a
    const float fm=6.2; //femur
    const float tb=8.3; // tibia
    
    float L, L1;
    

    
};



#endif