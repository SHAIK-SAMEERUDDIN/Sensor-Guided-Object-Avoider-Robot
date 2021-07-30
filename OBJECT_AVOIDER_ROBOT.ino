void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(10,OUTPUT);
pinMode(11,OUTPUT);
pinMode(12,OUTPUT);
pinMode(13,OUTPUT);
pinMode(A0,INPUT);
pinMode(A1,INPUT);
}

void moveRobot(String motion)
{
   if(motion == "Forward")
   { digitalWrite(10,LOW);
     digitalWrite(11,HIGH);
     digitalWrite(12,LOW);
     digitalWrite(13,HIGH);
     Serial.println("Forward");
   }
   if(motion == "Backward")
   { digitalWrite(10,HIGH);
     digitalWrite(11,LOW);
     digitalWrite(12,HIGH);
     digitalWrite(13,LOW);
     Serial.println("Backward");
   }
  
   if(motion == "Left")
   { digitalWrite(10,HIGH);
     digitalWrite(11,LOW);
     digitalWrite(12,LOW);
     digitalWrite(13,HIGH);
     Serial.println("Left");
   }
   if(motion == "Right")
   { digitalWrite(10,LOW);
     digitalWrite(11,HIGH);
     digitalWrite(12,HIGH);
     digitalWrite(13,LOW);
     Serial.println("Right");
   }
   if(motion == "STOP")
   { digitalWrite(10,LOW);
     digitalWrite(11,LOW);
     digitalWrite(12,LOW);
   digitalWrite(13,LOW);
     Serial.println("STOP");
   }
   
}
void loop() {
  // put your main code here, to run repeatedly:
int Left=analogRead(A1);
int Right=analogRead(A0);
if((Right>600) && (Left>600))
{
  moveRobot("Backward");
  delay(2000);
  moveRobot("Right");
  delay(1000);
}
if((Right<600) && (Left<600))
{
  moveRobot("Forward");
}
if((Right<600) && (Left>600))
{
  moveRobot("Backward");
  delay(1000);
  moveRobot("Left");
  delay(1000);
}
if((Right>600) && (Left<600))
{ moveRobot("Backward");
  delay(1000);
  moveRobot("Right");
  delay(1000);
}
}
