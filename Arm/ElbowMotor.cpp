#include "Arduino.h"
#include "ElbowMotor.h"

ElbowMotor::ElbowMotor(int pin1,int pin3 )
{
    pinMode(pin1,OUTPUT);
    //pinMode(pin2, OUTPUT);
    pinMode(pin3, OUTPUT);
    pinMode(A1,INPUT);
    dir1=pin1;
    //dir2=pin2;
    pwm=pin3;
    
}



void ElbowMotor::forward()
{
    digitalWrite(dir1,LOW);
    //digitalWrite(dir2,HIGH);
    analogWrite(pwm,255);
}

void ElbowMotor::backward()
{
    digitalWrite(dir1,HIGH);
    //digitalWrite(dir2,LOW);
    analogWrite(pwm,255);
}

void ElbowMotor::brake()
{
    digitalWrite(dir1,LOW);
    //digitalWrite(dir2,LOW);
    analogWrite(pwm,0);
  
}
int ElbowMotor::checkPot()
{
    int y = analogRead(A1);
    int z = map(y,0,1023,0,3600); /*maps value from potentiometer to the mechanical angle of shaft */
    
    return(z);

}

void ElbowMotor::errorcheck()
{
    int Error;  
    
    int modError ;
    
    int c;
    
    Serial.println(x);
    
    while(1)
    {
        c = checkPot();
        Serial.println(c);
        Error = c - x ;
        Serial.println(Error);
        modError = abs(c-x);
        while(!(modError<5))
        {
            if(c<x-5){
                forward();
                Serial.println("going forward");
                delay(100);
                c = checkPot();
                modError = abs(c-x);
            }
            else if(c>x+5){
                backward();
                Serial.println("going backward");
                delay(100);
                c = checkPot();
                modError = abs(c-x);
            }
            c = checkPot();
            modError = abs(c-x);

        }
        brake();
        c = checkPot();
        modError = abs(c-x);
        delay(100);
        if(modError<5){
            
            Serial.println(x);
            break ;
        }
    }
}

