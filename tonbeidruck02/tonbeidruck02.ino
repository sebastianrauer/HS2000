#include <Bounce.h>

int softPotUno = A0;
int softPotDos = A1;
int softPotTres = A2;

int valueUno;
int valueDos;
int valueTres;

int BUTTON=6;

// Instantiate a Bounce object with a 5 millisecond debounce time
Bounce bouncer = Bounce( BUTTON,100); 

void setup() {
  Serial.begin(9600);
  pinMode(BUTTON, INPUT); // der interne Pull-Up Widerstand wird zugeschaltet}
  digitalWrite(softPotUno, HIGH); //enable pullup resistor Uno
  digitalWrite(softPotDos, HIGH); //enable pullup resistor Dos
  digitalWrite(softPotTres, HIGH); //enable pullup resistor Tres
}

void loop() {
 // Update the debouncer
  bouncer.update ( );

 // Get the update value
 int value = bouncer.read();
 
  valueUno = analogRead(softPotUno);
  valueDos = analogRead(softPotDos);
  valueTres = analogRead(softPotTres);

 // Turn on or off the LED
 if ( value == LOW) {
   
      Serial.println(valueTres); 
      
      valueUno = map(valueUno,0,1023,0,127);
      valueDos = map(valueDos,0,1023,0,127);
      valueTres = map(valueTres,0,1023,0,127);
      
      //analogWrite(softPotUno, valueUno);

      usbMIDI.sendNoteOn(valueTres,100,1);
      usbMIDI.sendNoteOn(valueDos,100,1);
      usbMIDI.sendNoteOn(valueUno,100,1);


     // alreadySwitched=true; // nun wurde der Button ja gedrückt, damit wird die Variable alreadySwitched auf falsch gesetzt
   // }
 } else {
      usbMIDI.sendNoteOff(valueTres,100,1);
 }

}
