
#include <Servo.h>

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

int pos = 0;    // variable to store the servo position
int move ;   // for incoming serial data

void setup() {
  Serial.begin(9600);
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
}



void loop() {

          Serial.println("move??");

        // send data only when you receive data:
        while(!Serial.available()); 
                // read the incoming byte:
                move = Serial.parseInt();

                // say what you got:
                if(move==0){
                  
                }

                if(move==1){

                myservo.write(75);
                for(int i=90;i>=0;i=i-4)
                {/*
                  myservo.write(i);
                  delay(10);
                */
                 delay(1300);
                 myservo.write(90);
                 break ;
                }
                

                }
                if(move==2)myservo.write(90);
                if(move==3)
                {/*
                  for(int j=100;j<180;j=j+4)
                    myservo.write(j);
                    delay(20);
                */
                myservo.write(110);
                delay(800);
                myservo.write(90);
                while(1){ 
                  break;
                  } 
                }
                
              
                  
                 
        }

  
 
