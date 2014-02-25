int greenPinLeft =  10;
int greenPinRight =  9;
int ton = 0;
int knopp =0;

boolean firstSwitchOn=false;
boolean firstSwitchOff=false;

void setup()   {
  pinMode(greenPinRight, OUTPUT);
  pinMode(greenPinLeft, OUTPUT);
   Serial.begin(9600);       // use the serial port

}

int regler = 0;

void loop()                     
{

  boolean firstSwitchOn=false;

  // read the pot position
  regler = analogRead(0);

  // set all 3 pins to the desired intensity
  analogWrite(greenPinRight, regler);
  analogWrite(greenPinLeft, regler);

  delay(50);

  if (analogRead(regler)>1000){
    analogWrite(greenPinRight, HIGH);   // turn the LED on (HIGH is the voltage level)
    analogWrite(greenPinLeft, LOW);
    usbMIDI.sendNoteOn(ton, 127, 1); 
        Serial.println("geht!");         

  }
}





