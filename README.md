# CS-207
These days everything we use is becoming smart. Like the smartphone, smart tv, smart car, smart electronics, etc. In this era of smartness should not the dustbin be smart too? Moreover, the dustbin is a part of our daily life; we all need it to throw the trash of the house. With the simple idea of making a simple dustbin into a smart dustbin I decided to do this project. On the other hand, a smart dustbin may also prove to  be useful for disabled people because the effort to open the lid by hand or leg will not be needed.





I will be replicating the same product of the admin of bestselectronicprojects.com[1] and then plan to modify it by adding another ultrasonic sensor to the dustbin which will detect the level of garbage inside it and if the garbage reaches a certain height, a sound will be made using the piezo buzzer thus the owner will understand that the bin is full.


Materials Required
According to the project website, the following materials are required:
-Arduino UNO
-Ultrasonic sensor
-Servo motor
-Trashbin
In addition, the following materials are required:
-Ultrasonic sensor
-Piezo buzzer
-Jumper wires


1)First, two pins from the Arduino, GND( ground) and, 5V  are to be connected with the breadboard’s GND (-) and 5V (+).  Breadboard view is available on APPENDIX D
2) For the first ultrasonic sensor connect -
VCC on the ultrasonic sensor to the 5V pin on the Arduino.
Connect the Trig pin on the ultrasonic sensor to pin 2 on the Arduino.
Connect the Echo pin on the ultrasonic sensor to pin 3 on the Arduino.
Connect the GND on the ultrasonic sensor to GND on the Arduino.

For the second ultrasonic sensor ...connect -
VCC on the ultrasonic sensor to the 5V pin on the Arduino.
Connect the Trig pin on the ultrasonic sensor to pin 4 on the Arduino.
Connect the Echo pin on the ultrasonic sensor to pin 5 on the Arduino.
Connect the GND on the ultrasonic sensor to GND on the Arduino.

3)The buzzer has two pins. The positive pin has to be connected with Pin 10 and the negative side with the GND.

4) The servo motor has three wires. The brown one goes to the GND, the red one goes to 5V and the yellow one goes to pin 9 of Arduino.


A reference to the website from where the project is inspired is given below-

[1]Admin. “Smart Dustbin using Arduino”. bestelectronicprojects.com. May 14, 2019.
     https://www.bestelectronicprojects.com/2019/05/smart-dustbin-using-arduino.html

