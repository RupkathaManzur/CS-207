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
long duration, dist, average;   // declaring of variables for servo measurement.
long aver[3];   //array for average

 int buzzerPin= 10;
 int time;    // declaring variables for controlling buzzer.
 int distance;

void setup() // the setup function runs once when you press reset or power the board
{       
    Serial.begin(9600); // Serial plotter

    pinMode(trigPin1, OUTPUT);    // initialize digital pin 2 (trigpin1) as an output.
    pinMode(echoPin1, INPUT);     // initialize digital pin 3 (echopin1) as an iutput.
    pinMode(buzzerPin, OUTPUT);   // initialize digital pin 10 (bizzerPin) as an output.
     

    servo.attach(servoPin);  // setup pinmodes
    pinMode(trigPin2, OUTPUT);  // initialize digital pin 4 (trigpin2) as an output.
    pinMode(echoPin2, INPUT);   // initialize digital pin 5 (trigpin2) as an input.
    servo.write(0);         //close cap on power on
    delay(100);             // delay time is in microseconds
    servo.detach(); 

    
 } 


void measure()     // a function measure is introduced for distance measurement 
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




void loop()         // The loop function runs again and again
{
digitalWrite (trigPin1, HIGH);

    delayMicroseconds (10);

    digitalWrite (trigPin1, LOW);

    time = pulseIn (echoPin1, HIGH);

    distance = (time * 0.030) / 2;

    

  if (distance <= 10) //if the distance value is less than or equal to 10, then the buzzer will start to beep. 
                      //If the distance value is greater than 10, then the buzzer will remain quiet.


        {

        Serial.println (" garbage full "); /* the serial printer will show "garbage full" when 
                                               distace between a sensor and garge inside is less than 10*/

        Serial.print (" Distance between sensor and garbage= ");  // show the distance between garbage and sensor            

        Serial.println (distance);        

        digitalWrite (buzzerPin, LOW);    //the buzzer will not make sound

        delay (500);    //delay between sounds in millisecods but here will be no sound as the buzzerpin is set low.

        }

  else {

        Serial.println (" Space left for garbage ");      /* the serial printer will show "Space left for garbage" when 
                                                          distace between a sensor and garge inside is more than 10*/

        Serial.print (" Distance between sensor and garbage= ");     // show the distance between garbage and sensor
   
        Serial.println (distance);        

        digitalWrite (buzzerPin, HIGH);      //the buzzer will make sound               
   
        delay (500);   //  //delay between sounds in millisecods   

  } 

  



  for (int i=0;i<=2;i++) {   //average distance
    measure();               
   aver[i]=dist;            
    delay(10);              //delay between measurements
  }
 dist=(aver[0]+aver[1]+aver[2])/3;    

if ( dist< 30 ) // setting condition for the lid to open and close with the measurement of the distance
{

 servo.attach(servoPin); // servo moves to open the lid
  delay(30);              // Wait for 30 milliseconds
 servo.write(0);  
 delay(3000);          //    // Wait for 3000 milliseconds or 3 seconds 
 servo.write(150);    // servo comes back to the previous position closing the lid.
 delay(1000);         //// Wait for 1000 milliseconds or 1 seconds
 servo.detach();      
}
Serial.print(dist);
}

/* Part of the code to control the servo is taken from bestschoolprojects.com

Admin. “Smart Dustbin using Arduino”. bestschoolprojects.com. May 14, 2019.*/

