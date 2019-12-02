/* TEST CODE */
const int piezoPin = 9; //the output pin
const int frequency = 70; //the pitch of the noise 
void setup() {
  // put your setup code here, to run once:
   pinMode(piezoPin, OUTPUT); 

}

void loop(){
 
  tone(piezoPin,frequency); 
  delay (500);  //the tone play time measured in milliseconds    
  
}
