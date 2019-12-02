/* A sketch to see the ultrasonic sensor and piezo buzzer working simultaneously when a particle comes to close to the ultrasonic sensor. 
In the smart dustbin the work of one of the ultrasonic sensor is to emit a sound when the garbage fills up to a certain distance. Using
the sketch below we will be able to fix the distance upto which we want the garbage to be full using a serial monitor.*/
int trig_pin = 2;  // initialization of the trigger pin and echo for the ultrasonic sensor. 
                             
int echo_pin = 3;

int buzzer_pin = 10; // initialized the buzzer pin

int time;

int distance; 




void setup ( ) 
{

        Serial.begin (9600); 

        pinMode (trig_pin, OUTPUT); //trigger pin as the output pin because we will send the ultrasonic wave through that pin. 
                                  
                                 
        pinMode (echo_pin, INPUT);    // echo pin as input pin because we will receive the ultrasonic wave through the echo.

        pinMode (buzzer_pin, OUTPUT); // the buzzer gives out sound
}




void loop ( ) 
{

    digitalWrite (trig_pin, HIGH);

    delayMicroseconds (10);

    digitalWrite (trig_pin, LOW);

    time = pulseIn (echo_pin, HIGH);

    distance = (time * 0.030) / 2;

    

  if (distance <= 5) //if the distance value is less than or equal to 5, then the buzzer will start to beep. 
                      //If the distance value is greater than 5, then the buzzer will remain quiet.


        {

        Serial.println (" garbage full ");

        Serial.print (" Distance between sensor and garbage= ");              

        Serial.println (distance);        

        digitalWrite (buzzer_pin, HIGH);

        delay (1000);

        }

  else {

        Serial.println (" Space left for garbage ");

        Serial.print (" Distance between sensor and garbage= ");              

        Serial.println (distance);        

        digitalWrite (buzzer_pin, LOW);

        delay (500);        

  } 

  }
