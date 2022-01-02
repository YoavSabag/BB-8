
unsigned long myTime1, myTime2;
const int MOTOR1_F = 2;
const int MOTOR1_B = 3;
const int MOTOR2_F = 5;
const int MOTOR2_B = 4;

const int dt = 20;

char dir;
void MotorsStop()
{  
 digitalWrite(MOTOR1_F, LOW);
 digitalWrite(MOTOR1_B, LOW);
 digitalWrite(MOTOR2_F, LOW);
 digitalWrite(MOTOR2_B, LOW); 
}

void MoveForward()
{
  
 digitalWrite(MOTOR1_F, HIGH);
 digitalWrite(MOTOR2_F, HIGH);
 MotorsStop();
}
void MoveBack()
{
digitalWrite(MOTOR1_B, HIGH);
digitalWrite(MOTOR2_B, HIGH);
MotorsStop();  
}
void MoveRight()
{
digitalWrite(MOTOR1_F, HIGH); 
digitalWrite(MOTOR2_B, HIGH);
MotorsStop();
}
void MoveLeft()
{
digitalWrite(MOTOR1_B, HIGH);
digitalWrite(MOTOR2_F, HIGH);
MotorsStop(); 
}

void setup() {

Serial.begin(9600);
  
pinMode( MOTOR1_F,OUTPUT);
pinMode( MOTOR1_B,OUTPUT);
pinMode( MOTOR2_F,OUTPUT);
pinMode( MOTOR2_B ,OUTPUT);
 
Serial.println("START"); 
}

void loop() {

 if(Serial.available() > 0)  
  {
dir = Serial.read();

 
switch(dir)
{
case 'F':
myTime1 = millis();
MoveForward(); 
Serial.println("F");
break;

case 'B':
myTime1 = millis();
MoveBack();
Serial.println("B"); 
break;

case 'R':
myTime1 = millis();
MoveRight();
Serial.println("R"); 
break;

case 'L':
myTime1 = millis();
MoveLeft();
Serial.println("L"); 
break;

myTime2 = millis();
if(myTime2 - myTime1 < dt)
MotorsStop();

} 
  }
}
