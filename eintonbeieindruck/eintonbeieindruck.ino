int potPin = A8;
int value;
int buttonPin=6;

int minValue = 200;
int maxValue = 700;

int buttonState=0;

boolean alreadySwitched=false; // speichert, ob Button schon gedrückt wurde
boolean alreadyReleased=true; // speichert, ob Button schon losgelassen wurde

void setup()
{
  Serial.begin(9600);
  pinMode(buttonPin, INPUT_PULLUP); // der interne Pull-Up Widerstand wird zugeschaltet}
}

void loop()
{
  value = analogRead(potPin);

  if (value<minValue) 
  {
    value=minValue;
  }  
  if 
    (value>maxValue) {
    value=maxValue;
  } 

  if (digitalRead(buttonPin)==LOW){ // Wenn der Button gedrückt ist

    if (alreadySwitched==false){ // UND! die Variable alreadySwitched falsch ist, also der Button direkt davor noch nicht gedrückt war

      Serial.println(value); 

      analogWrite(potPin, value);

      value = map(value,minValue,maxValue,0,127);

      usbMIDI.sendControlChange(1, value, 1);

      alreadySwitched=true; // nun wurde der Button ja gedrückt, damit wird die Variable alreadySwitched auf falsch gesetzt
    }
  }
  else {
    if (alreadyReleased==true){ // UND! die Variable alreadyReleased falsch ist, also der Button direkt davor gedrückt war

      usbMIDI.sendNoteOff(value,127,1);

      alreadySwitched=false; // der Button wurde nicht gedrückt, deshalb ist alreadySwitched falsch
    }
  }
  delay(50);
}








