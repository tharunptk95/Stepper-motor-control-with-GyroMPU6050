#include <Wire.h>
#include <MPU6050.h>
const int stepPin = 6;  //PUL -Pulse
const int dirPin = 7; //DIR -Direction
const int enPin = 8;  //ENA -Enable
float ang = 180;
int pul;

MPU6050 gy_521;
int16_t ax, ay, az;
int16_t gx, gy, gz;

void setup ( ){
Wire.begin( );
  pinMode(stepPin,OUTPUT); 
  pinMode(dirPin,OUTPUT);
  pinMode(enPin,OUTPUT);
  digitalWrite(enPin,LOW);
Serial.begin (9600);
Serial.println ("Initializing MPU and testing connections");
gy_521.initialize ( );
Serial.println(gy_521.testConnection( ) ? "Successfully Connected" : "Connection failed");
delay(1000);
Serial.println("Reading Values");
delay(1000);
}

void loop ( ){
gy_521.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);
/*
Serial.print (ax);
Serial.print ('\t');
Serial.print (ay);
Serial.print ('\t');
Serial.println (az);
*/
delay(200);
  pul = map(abs(ang),0,360,0,3000);
  if(az<10000)
  {
    digitalWrite(dirPin,LOW);
    Serial.println("CW");
  for(int i=0;i<=pul;i++)
    {
      digitalWrite(stepPin,HIGH); 
      delayMicroseconds(1000); 
      digitalWrite(stepPin,LOW); 
      delayMicroseconds(1000); 
      
  }
  }
    if(az>20000)
  {
    digitalWrite(dirPin,HIGH);
    Serial.println("CCW");
  for(int i=0;i<=pul;i++)
    {
      digitalWrite(stepPin,HIGH); 
      delayMicroseconds(1000); 
      digitalWrite(stepPin,LOW); 
      delayMicroseconds(1000); 
  }
  }
}
