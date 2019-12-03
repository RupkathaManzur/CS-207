/*Main code for CS 207 Project
 * This sketch is the demonstration of the two ultrasonic sensor working simultaneously with the servo and buzzer. 
 * The two codes shown previously are merged here and with a few changes made in the code .*/


#include <Servo.h>   //servo library
Servo servo;     
int trigPin1 = 2;    //Initializing ultrasonic sensor 1
int echoPin1 = 3; 
int trigPin2 = 4;    //Initialing ultrasonic sensor 2
int echoPin2 = 5; 


int servoPin = 9;    //Initialize servo pin
long duration, dist, average;   // declaring of fuctions for servo measurement.
long aver[3];   //array for average

 int buzzerPin= 10;
 int time;    // declaring functions for controlling buzzer.
 int distance;

void setup() 
{       
    Serial.begin(9600); // Serial plotter

    pinMode(trigPin1, OUTPUT);   
    pinMode(echoPin1, INPUT);
    pinMode(buzzerPin, OUTPUT); // the buzzer will give out sound.
     

    servo.attach(servoPin);  
    pinMode(trigPin2, OUTPUT);  
    pinMode(echoPin2, INPUT);  
    servo.write(0);         //close cap on power on
    delay(100);
    servo.detach(); 

    
 } 


void measure() 
{  
 digitalWrite(10,HIGH);
digitalWrite(trigPin2, LOW);
delayMicroseconds(5);
digitalWrite(trigPin2, HIGH);
delayMicroseconds(15);
digitalWrite(trigPin2, LOW);
pinMode(echoPin2, INPUT);
duration = pulseIn(echoPin2, HIGH);
dist = (duration/2) / 29.1;    //obtain distance
}




void loop()
{
digitalWrite (trigPin1, HIGH);

    delayMicroseconds (10);

    digitalWrite (trigPin1, LOW);

    time = pulseIn (echoPin1, HIGH);

    distance = (time * 0.030) / 2;

    

  if (distance <= 10) //if the distance value is less than or equal to 10, then the buzzer will start to beep. 
                      //If the distance value is greater than 10, then the buzzer will remain quiet.


        {

        Serial.println (" garbage full ");

        Serial.print (" Distance between sensor and garbage= ");              

        Serial.println (distance);        

        digitalWrite (buzzerPin, LOW);

        delay (500);

        }

  else {

        Serial.println (" Space left for garbage ");

        Serial.print (" Distance between sensor and garbage= ");              

        Serial.println (distance);        

        digitalWrite (buzzerPin, HIGH);

        delay (500);        

  } 

  



  for (int i=0;i<=2;i++) {   //average distance
    measure();               
   aver[i]=dist;            
    delay(10);              //delay between measurements
  }
 dist=(aver[0]+aver[1]+aver[2])/3;    

if ( dist< 30 ) 
{

 servo.attach(servoPin); // servo moves to open the lid
  delay(1);
 servo.write(0);  
 delay(3000);       
 servo.write(150);    // servo comes back to the previous position closing the lid.
 delay(1000);
 servo.detach();      
}
Serial.print(dist);
}

/* Part of the code to control the servo is taken from bestschoolprojects.com

Admin. “Smart Dustbin using Arduino”. bestschoolprojects.com. May 14, 2019.*/

