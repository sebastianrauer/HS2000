int softPotUno=A0;
int softPotDos=A1;
int softPotTres=A2;
int buttonPin=6;
int ton=0;

int value;

void setup()
{
  Serial.begin(9600);
  pinMode(buttonPin, INPUT_PULLUP);
  digitalWrite(softPotUno, HIGH);
  digitalWrite(softPotDos, HIGH);
  //digitalWrite(softPotTres, HIGH);
}

void loop()
{
  int buttonVal = digitalRead(buttonPin);
  value=analogRead(softPotUno+softPotDos);
  if (digitalRead(buttonPin)==LOW)
  {
    Serial.println(value);
    value = map(value,0,1023,10,90);
    usbMIDI.sendNoteOn(value, 127, 1);
    delay(250); 
  }
  if (digitalRead(buttonPin)==HIGH)
  {
    usbMIDI.sendNoteOff(value, 0, 1);
    delay(250);
  }
}




