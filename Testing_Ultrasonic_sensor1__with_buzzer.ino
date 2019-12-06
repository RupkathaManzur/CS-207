/* A sketch to see the ultrasonic sensor and piezo buzzer working simultaneously when a particle comes to close to the ultrasonic sensor. 
In the smart dustbin the work of one of the ultrasonic sensor is to emit a sound when the garbage fills up to a certain distance. Using
the sketch below we will be able to fix the distance upto which we want the garbage to be full using a serial monitor.*/


int trig_pin = 2;  
                             
int echo_pin = 3;

int buzzer_pin = 10; // initialized the buzzer pin

int time;            //variables

int distance; 




void setup ( )   // the setup function runs once when you press reset or power the board
{

        Serial.begin (9600); //initializing serial plotter

        pinMode (trig_pin, OUTPUT);  // initialize digital pin 2 (trigpin) as an output.
                                  
                                 
        pinMode (echo_pin, INPUT);    // initialize digital pin 3 (echopin) as an output.

        pinMode (buzzer_pin, OUTPUT);  // initialize digital pin 10 (buzzer_pin) as an output.
}




void loop ( )    // The loop function runs again and again
{

    digitalWrite (trig_pin, HIGH);

    delayMicroseconds (10);

    digitalWrite (trig_pin, LOW);

    time = pulseIn (echo_pin, HIGH);

    distance = (time * 0.030) / 2;

    

  if (distance <= 5) //if the distance value is less than or equal to 5, then the buzzer will start to beep. 
                      //If the distance value is greater than 5, then the buzzer will remain quiet.


        {

        Serial.println (" garbage full ");   /* the serial printer will show "garbage full" when 
                                               distace between a sensor and garge inside is less than 10*/

        Serial.print (" Distance between sensor and garbage= ");       // show the distance between garbage and sensor            

        Serial.println (distance);        

        digitalWrite (buzzer_pin, HIGH);  // the buzzer will make sound

        delay (1000);

        }

  else {

        Serial.println (" Space left for garbage ");   /* the serial printer will show "Space left for garbage" when 
                                                          distace between a sensor and garge inside is more than 10*/

        Serial.print (" Distance between sensor and garbage= ");   // show the distance between garbage and sensor
              

        Serial.println (distance);        

        digitalWrite (buzzer_pin, LOW);     //the buzzer will not make sound

        delay (500);    //delay between sounds               
       

  } 

  }
