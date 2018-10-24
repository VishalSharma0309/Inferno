#define rpm_1 9
#define rpm_2 6
#define rpm_3 10
#define rpm_4 11
#define rpm_5 5
#define rpm_6 3

#define dir_1 8
#define dir_2 7
#define dir_3 13
#define dir_4 12
#define dir_5 4
#define dir_6 2

void forward(int sp){
    digitalWrite(dir_1, LOW);
    digitalWrite(dir_2, LOW);
    digitalWrite(dir_3, HIGH);
    digitalWrite(dir_4, LOW);
    digitalWrite(dir_5, HIGH);
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
    digitalWrite(dir_2, HIGH);
    digitalWrite(dir_3, LOW);
    digitalWrite(dir_4, HIGH);
    digitalWrite(dir_5, LOW);
    digitalWrite(dir_6, LOW);
    
    analogWrite(rpm_1, sp);
    analogWrite(rpm_2, sp);
    analogWrite(rpm_3, sp);
    analogWrite(rpm_4, sp);
    analogWrite(rpm_5, sp);
    analogWrite(rpm_6, sp);
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
      Serial.println("Enter the speed");
      while(!Serial.available());
      int rpm = Serial.parseInt();
      if (rpm == 0){
          analogWrite(rpm_1, 0);
          analogWrite(rpm_2, 0);
          analogWrite(rpm_3, 0);
          analogWrite(rpm_4, 0);
          analogWrite(rpm_5, 0);
          analogWrite(rpm_6, 0);
      }
      Serial.println("Enter the dir");
      while(!Serial.available());
      int dir = Serial.read();
      if (dir == 'f'){
          forward(rpm);
      }
      if (dir == 'b'){
          backward(rpm);
      }
}
