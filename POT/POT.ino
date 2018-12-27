#include <MotorPID.h>
#include <Invkin.h>


MotorPID motor1(7,26,A0,30);

MotorPID motor2(3,22,A3,30);

Invkin IK(50,0,23);

float gr_eb = 4 ;
float gr_sh = 5.5 ;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  motor1.setPID(0.35,-0.01,-0.002);
  motor2.setPID(0.39,0.01,-0.002);

}

void loop() {
  // put your main code here, to run repeatedly:
  IK.transform();
  // for theta2 =0 ,pot angle 1378 and theta 3 = 0  pot angle = 2296
  motor1.x = 1378 ;//(IK.theta2)*5.5   ;
  motor2.x = 2346-50  ; //(IK.theta3)*4 ;
  
  Serial.println(IK.theta3);
  Serial.println(IK.theta2);
  
  Serial.println("------Motor 1----"); 
  Serial.println("Setpoint: ");
  Serial.println(motor1.x);
  motor1.errorcheck();
  
  Serial.println("-----Motor2-----");
  Serial.println("Setpoint: ");
  Serial.println(motor2.x);
  motor2.errorcheck();
  
  delay(1000);
  
}
