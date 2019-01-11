#define rpm_1 3
#define rpm_2 6
#define rpm_3 5
#define rpm_4 9
#define rpm_5 10
#define rpm_6 11

#define dir_1 2
#define dir_2 7
#define dir_3 4
#define dir_4 8
#define dir_5 12
#define dir_6 13

void forward(int sp){
    digitalWrite(dir_1, LOW);
    digitalWrite(dir_2, HIGH);
    digitalWrite(dir_3, LOW);
    digitalWrite(dir_4, HIGH);
    digitalWrite(dir_5, LOW);
    digitalWrite(dir_6, HIGH);
    
    analogWrite(rpm_1, sp);
    analogWrite(rpm_2, sp);
    analogWrite(rpm_3, sp);
    analogWrite(rpm_4, sp);
    analogWrite(rpm_5, sp);
    analogWrite(rpm_6, sp);
}

void backward(int sp){
    digitalWrite(dir_1, HIGH);
    digitalWrite(dir_2, LOW);
    digitalWrite(dir_3, HIGH);
    digitalWrite(dir_4, LOW);
    digitalWrite(dir_5, HIGH);
    digitalWrite(dir_6, LOW);
    
    analogWrite(rpm_1, sp);
    analogWrite(rpm_2, sp);
    analogWrite(rpm_3, sp);
    analogWrite(rpm_4, sp);
    analogWrite(rpm_5, sp);
    analogWrite(rpm_6, sp);
}
void left(int sp){
   digitalWrite(dir_1, LOW);
    digitalWrite(dir_2, LOW);
    digitalWrite(dir_3, LOW);
    digitalWrite(dir_4, LOW);
    digitalWrite(dir_5, LOW);
    digitalWrite(dir_6, LOW);
    
    analogWrite(rpm_1, sp);
    analogWrite(rpm_2, sp);
    analogWrite(rpm_3, sp);
    analogWrite(rpm_4, sp);
    analogWrite(rpm_5, sp);
    analogWrite(rpm_6, sp);
}

void right(int sp){
    digitalWrite(dir_1, HIGH);
    digitalWrite(dir_2, HIGH);
    digitalWrite(dir_3, HIGH);
    digitalWrite(dir_4, HIGH);
    digitalWrite(dir_5, HIGH);
    digitalWrite(dir_6, HIGH);
    
    analogWrite(rpm_1, sp);
    analogWrite(rpm_2, sp);
    analogWrite(rpm_3, sp);
    analogWrite(rpm_4, sp);
    analogWrite(rpm_5, sp);
    analogWrite(rpm_6, sp);  
}  
  
void stop(){

   digitalWrite(dir_1, HIGH);
    digitalWrite(dir_2, LOW);
    digitalWrite(dir_3, HIGH);
    digitalWrite(dir_4, LOW);
    digitalWrite(dir_5, HIGH);
    digitalWrite(dir_6, LOW);
    
    analogWrite(rpm_1, 0);
    analogWrite(rpm_2, 0);
    analogWrite(rpm_3, 0);
    analogWrite(rpm_4, 0);
    analogWrite(rpm_5, 0);
    analogWrite(rpm_6, 0);
  
} 

void burst_forward(){
  
}
  
void setup(){
    pinMode(rpm_1, OUTPUT);
    pinMode(rpm_2, OUTPUT);
    pinMode(rpm_3, OUTPUT);
    pinMode(rpm_4, OUTPUT);
    pinMode(rpm_5, OUTPUT);
    pinMode(rpm_6, OUTPUT);
    pinMode(dir_1, OUTPUT);
    pinMode(dir_2, OUTPUT);
    pinMode(dir_3, OUTPUT);
    pinMode(dir_4, OUTPUT);
    pinMode(dir_5, OUTPUT);
    pinMode(dir_6, OUTPUT);
    Serial.begin(9600);
  
}

void loop(){
      int x = 0;
      Serial.println("Enter the speed");
      while(!Serial.available());
      int rpm = Serial.parseInt();
      if (rpm == 0){
          stop();
      }
      Serial.println("Enter the dir");
      while(!Serial.available());
      int dir = Serial.read();
      
      //burst backward
      if (dir == 'e'){
              Serial.println("Burst backward");
              forward(rpm);
              delay(500);
      }
      //burst forward      
      if (dir == 'q'){
              Serial.println("Burst forward");
              backward(rpm);
              delay(500);
      }
      //backwards
      if (dir == 's'){
          forward(rpm);
      }
      //forward
      if (dir == 'w'){
          backward(rpm);
      }
      //left
      if (dir == 'a'){
          while(x == 0){
            
            right(rpm);
            //Serial.print("flag 1");
            delay(200);
            stop();
            delay(200);
            Serial.println("0 or 1");
           // x = Serial.parseInt();
            while(Serial.available()){
              x = Serial.parseInt();
            }
            //Serial.print("flag 2");
             
             }
      }
      //right
      if (dir == 'd'){
           while(x == 0){
            
            left(rpm);
            //Serial.print("flag 1");
            delay(200);
            stop();
            delay(200);
            Serial.println("0 or 1");
           // x = Serial.parseInt();
            while(Serial.available()){
              x = Serial.parseInt();
            }
              }

}
}
