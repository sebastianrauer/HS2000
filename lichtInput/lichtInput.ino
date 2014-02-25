int potPin = A0;
int value;

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  Serial.println(value);
  value = analogRead(potPin);
  value = map(value,300,700,0,127);
  analogWrite(potPin, value*4);
  
  usbMIDI.sendNoteOn(value,127,1);
  
  delay(200);

  usbMIDI.sendNoteOff(value,127,1);
  
  delay(100);
}

