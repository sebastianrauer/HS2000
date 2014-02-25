/*
 Piezo
 
 This example shows how to run a Piezo Buzzer on pin 9
 using the analogWrite() function.
 
 It beeps 3 times fast at startup, waits a second then beeps continuously
 at a slower pace
 
 */

int buttonPin = 6;

void setup()  { 
  // declare pin 9 to be an output:
  pinMode(9, OUTPUT);
  beep(50);
  beep(50);
  beep(50);
  delay(1000);
  pinMode(buttonPin, INPUT);

} 

void loop()  { 
  beep(100); 
}

void beep(unsigned char delayms){
  if (digitalRead(buttonPin)==HIGH){

    analogWrite(9, 20);      // Almost any value can be used except 0 and 255
    // experiment to get the best tone
    delay(delayms);          // wait for a delayms ms
    analogWrite(9, 0);       // 0 turns it off
    delay(delayms);          // wait for a delayms ms   
  }
}  



