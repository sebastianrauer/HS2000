int potPin = A0;
int value;

int maxValue = 700;
int minValue = 300;

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  value = analogRead(potPin);
  
  Serial.println(value);
  
  if(value<minValue) value=minValue; // geht auch: value=constrain(value,minValue,maxValue)
  if(value>maxValue) value=maxValue; // "constrain" bedeutet: "nötigen"
  
  value = map(value,minValue,maxValue,0,127);
  analogWrite(potPin, value);
  
  usbMIDI.sendNoteOn(value,127,1);
  
  delay(500);

  usbMIDI.sendNoteOff(value,127,1);
  
  delay(500);
}

