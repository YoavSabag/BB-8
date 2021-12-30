

const int MOTOR1_F = 2;
const int MOTOR1_B = 3;
const int MOTOR2_F = 5;
const int MOTOR2_B = 4;

char dir;
void MotorDelayAndStop()
{
 delay(100);
 digitalWrite(MOTOR1_F, LOW);
 digitalWrite(MOTOR1_B, LOW);
 digitalWrite(MOTOR2_F, LOW);
 digitalWrite(MOTOR2_B, LOW); 
}

void MoveForward()
{
 digitalWrite(MOTOR1_F, HIGH);
 digitalWrite(MOTOR2_F, HIGH);
 MotorDelayAndStop();
}
void MoveBack()
{
digitalWrite(MOTOR1_B, HIGH);
digitalWrite(MOTOR2_B, HIGH);
MotorDelayAndStop();  
}
void MoveRight()
{
digitalWrite(MOTOR1_F, HIGH); 
digitalWrite(MOTOR2_B, HIGH);
MotorDelayAndStop();
}
void MoveLeft()
{
digitalWrite(MOTOR1_B, HIGH);
digitalWrite(MOTOR2_F, HIGH);
MotorDelayAndStop(); 
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
MoveForward(); 
Serial.println("F");
break;

case 'B':
MoveBack();
Serial.println("B"); 
break;

case 'R':
MoveRight();
Serial.println("R"); 
break;

case 'L':
MoveLeft();
Serial.println("L"); 
break;

} 
  }
}
