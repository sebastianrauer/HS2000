
int red = 10;
int yellow = 9;
int ton=42;
int buttonPin = 6;

boolean firstSwitchOn=false;
boolean firstSwitchOff=false;

void setup() {                
  pinMode(red, OUTPUT);     
  pinMode(yellow, OUTPUT);     
  pinMode(buttonPin, INPUT);
}

void loop(){

  if (digitalRead(buttonPin)==HIGH){

    if(firstSwitchOn==true){

      digitalWrite(red, HIGH);   // turn the LED on (HIGH is the voltage level)
      digitalWrite(yellow, LOW);
      usbMIDI.sendNoteOn(ton, 127, 1);
      firstSwitchOn=true;
      firstSwitchOff=false;      
    }
  }

  else{

    if(firstSwitchOn==true){

      digitalWrite(yellow, HIGH);    // turn the LED off by making the voltage LOW
      digitalWrite(red, LOW);
      usbMIDI.sendNoteOff(ton, 0, 1);
      firstSwitchOn=false;
      firstSwitchOff=true;
    }
  }

  delay(10);

}







