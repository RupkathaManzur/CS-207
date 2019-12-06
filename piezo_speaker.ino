/* TEST CODE */
/* ONE CANUSE THIS CODE TO CHECK THE CONNECTIONS OF THE BUZZER */
const int piezoPin = 10; //the output pin
const int frequency = 70; //the pitch of the noise 
void setup() {
  // put your setup code here, to run once:
   pinMode(piezoPin, OUTPUT); //SETTING UP PIN

}

void loop(){
 
  tone(piezoPin,frequency); 
  delay (500);  //the tone play time measured in milliseconds    
  
}
