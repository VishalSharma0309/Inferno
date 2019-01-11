#define rpm_1 5
#define dir_1 6

int dir;
int rpm;

void change_dir(int sp, int dirn){
  update_speed(sp,0);
  if (dirn == 0){
    digitalWrite(dir_1, LOW);
    }
  else{
    digitalWrite(dir_1, HIGH);
    }
  update_speed(0,sp);
}


void update_speed(int curr, int updated) {
  if (curr > updated)
  {
    for (int i = curr; i >= updated; --i)
     {analogWrite(rpm_1, i);
     }
  }
  else {
    for (int j = curr; j <= updated; ++j)
      analogWrite(rpm_1, j);
  }
}


void forward(int x1, int y1){
    digitalWrite(dir_1, HIGH);
    update_speed(x1, y1);  
}


void backward(int x2, int y2){
    digitalWrite(dir_1, LOW);
    update_speed(x2, y2); 
}


void setup() {
  // put your setup code here, to run once:
pinMode(rpm_1, OUTPUT);
pinMode(dir_1, OUTPUT);
Serial.begin(9600);
int rpm = 0;
Serial.println("Enter the speed setting (default)");
int x = Serial.read();
if (x == 'f')
      rpm = 255;
  else if (x == 'g')
      rpm = 180;
  else if (x == 'h')
      rpm = 80;  
Serial.println("Enter the direction (default)");
int dir = Serial.parseInt();
}


void loop() {
  // put your main code here, to run repeatedly:
  if (dir == 1){
      forward(0, rpm);
    }
  else{
      backward(0, rpm);
  }
  int curr_rpm = rpm;
  
  Serial.println("Enter the speed setting");
      int rpm_mode = Serial.read();
  //1 for clockwise and 0 for ccw
  Serial.println("Enter the dir");
      int dir_new = Serial.parseInt();
      
  if (rpm_mode == 'f')
      rpm = 255;
  else if (rpm_mode == 'g')
      rpm = 180;
  else if (rpm_mode == 'h')
      rpm = 80;
  
  if (dir_new == dir) {
    if (dir == 1)
      forward(curr_rpm, rpm);
    else if (dir == 0)
      backward(curr_rpm, rpm);
    }

  else {
        change_dir(dir_new, curr_rpm);
      }
  
  dir = dir_new;
  }
