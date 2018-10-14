#include "Arduino.h"
#include "BaseMotor.h"

BaseMotor::BaseMotor(int pin1,int pin2,int pin3)
{
    pinMode(pin1,OUTPUT);
    pinMode(pin2, OUTPUT);
    pinMode(pin3, OUTPUT);
    pinMode(A1,INPUT);
    mtr1=pin1;
    mtr2=pin2;
    pwm=pin3;
    
}



void BaseMotor::forward()
{
    digitalWrite(mtr1,LOW);
    digitalWrite(mtr2,HIGH);
    analogWrite(pwm,255);
}

void BaseMotor::backward()
{
    digitalWrite(mtr1,HIGH);
    digitalWrite(mtr2,LOW);
    analogWrite(pwm,255);
}

void BaseMotor::brake()
{
    digitalWrite(mtr1,LOW);
    digitalWrite(mtr2,LOW);
  
}
int BaseMotor::checkPot()
{
    int y = analogRead(A1);
    int z = map(y,0,1023,0,300); /*maps value from potentiometer to the mechanical angle of shaft */
    
    return(z);

}

void BaseMotor::errorcheck()
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

