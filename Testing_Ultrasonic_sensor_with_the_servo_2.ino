/*This sketch is for the second ultrasonic sensor to control the servo. 
When the ultrasonic sensor senses motion it initiates the servo which helps to open the the lid of the smart dustbin.*/
#include <Servo.h>

Servo myServo;

int trigPin = 4; // Initializing the pins of the ultrasonic sensor
int echoPin = 5;

long distance;
long duration;
 
void setup() 

{
   
  myServo.attach(10); 
 pinMode(trigPin, OUTPUT);
 pinMode(echoPin, INPUT);  
}


 
void loop(){
  ultra();
  myServo.write(0);
  if(distance <= 10) // the servo will open the lid when it senses motion in less than 10 cm
  {
  myServo.write(90);
  }
  }

 
void ultra()
  {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(10);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW); // to cntrol the time between opening and closing of the dustbin.
  duration = pulseIn(echoPin, HIGH);
  distance = duration*0.034/2;
  }

  /* This code is from the main project of the Smart Dustbin of the guys Techatronics.com with a few changes made according to the size and feature of the dustbin.
  citation
  Admin. “Smart Dustbin using Arduino”. Techatronic.com. May 14, 2019.*/
