/*This sketch is for the second ultrasonic sensor to control the servo. 
When the ultrasonic sensor senses motion it initiates the servo which helps to open the the lid of the smart dustbin.*/
#include <Servo.h> //servo library

Servo myServo;

int trigPin = 4; // Initializing the pins of the ultrasonic sensor
int echoPin = 5;

long distance;   //variables
long duration;
 
void setup()      // the setup function runs once when you press reset or power the board

{
   
  myServo.attach(9);           // servo attached to pin9
 pinMode(trigPin, OUTPUT);    // initialize digital pin 4 (trigpin) as an output.
 pinMode(echoPin, INPUT);    // initialize digital pin 5 (echopin) as an output.
}


 
void loop()     // The loop function runs again and again
{
  ultra();
  myServo.write(0);
  if(distance <= 10) // the servo will open the lid when it senses motion in less than 10 cm
  {
  myServo.write(180);  // the servo moves 180 degrees
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

  /* This code is from the main project of the Smart Dustbin of the guys bestelectronicsproject.com with a few changes made according to the size and feature of the dustbin.
  citation
  Admin. “Smart Dustbin using Arduino”. bestelectronicsprojects.com. May 14, 2019.*/
