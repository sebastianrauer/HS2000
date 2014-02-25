int softPotUno = A0;
int softPotDos = A1;
int softPotTres = A2;

int valueUno;
int valueDos;
int valueTres;

int buttonPin=6;

int buttonState=0;

boolean alreadySwitched=false; // speichert, ob Button schon gedrückt wurde
boolean alreadyReleased=true; // speichert, ob Button schon losgelassen wurde

void setup()
{
  Serial.begin(9600);
  pinMode(buttonPin, INPUT_PULLUP); // der interne Pull-Up Widerstand wird zugeschaltet}
  digitalWrite(softPotUno, HIGH); //enable pullup resistor Uno
  digitalWrite(softPotDos, HIGH); //enable pullup resistor Dos
  digitalWrite(softPotTres, HIGH); //enable pullup resistor Tres
}



void loop()
{
  valueUno = analogRead(softPotUno);
  valueDos = analogRead(softPotDos);
  valueTres = analogRead(softPotTres);



  if (digitalRead(buttonPin)==LOW){ // Wenn der Button gedrückt ist

    if (alreadySwitched==false){ // UND! die Variable alreadySwitched falsch ist, also der Button direkt davor noch nicht gedrückt war

      Serial.println(valueTres); 

      valueUno = map(valueUno,0,1023,5,100);
      valueDos = map(valueDos,0,1023,5,100);
      valueTres = map(valueTres,0,1023,5,100);

      if (buttonPin=HIGH){

        if (valueUno>5){
          usbMIDI.sendNoteOn(valueUno,127,1);
        }

        if (valueDos>5){
          usbMIDI.sendNoteOn(valueDos,127,1);
        }
        if (valueTres>5){
          usbMIDI.sendNoteOn(valueTres,127,1);
        }
      }

      alreadySwitched=true; // nun wurde der Button ja gedrückt, damit wird die Variable alreadySwitched auf falsch gesetzt

      //if (alreadyReleased==true){ // UND! die Variable alreadyReleased falsch ist, also der Button direkt davor gedrückt war

      usbMIDI.sendNoteOff(valueUno,127,1);
      usbMIDI.sendNoteOff(valueDos,127,1);
      usbMIDI.sendNoteOff(valueTres,127,1);


      alreadySwitched=false; // der Button wurde nicht gedrückt, deshalb ist alreadySwitched falsch
    }

    delay(250);
  }
}
















