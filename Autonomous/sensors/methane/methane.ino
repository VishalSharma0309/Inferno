const int AOUTpin=0;//the AOUT pin of the methane sensor goes into analog pin A0 of the arduino
const int DOUTpin=8;//the DOUT pin of the methane sensor goes into digital pin D8 of the arduino

int limit;
int value;

void setup() {
Serial.begin(9600);//sets the baud rate
}

void loop()
{
value= analogRead(AOUTpin);//reads the analaog value from the methane sensor's AOUT pin
limit= digitalRead(DOUTpin);//reads the digital value from the methane sensor's DOUT pin
Serial.print("Methane value: ");
Serial.println(value);//prints the methane value
Serial.print("Limit: ");
Serial.print(limit);//prints the limit reached as either LOW or HIGH (above or underneath)
delay(2000);

}
