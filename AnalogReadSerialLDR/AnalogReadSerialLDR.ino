  int minValue = 400;
  int maxValue = 600;
  
  void setup() {
  Serial.begin(9600);
}

// the loop routine runs over and over again forever:

void loop() {
  // read the input on analog pin 0:

  int sensorValue = analogRead(A0);

  Serial.println(sensorValue);

  if(sensorValue<minValue) 
    sensorValue=minValue;

  if(sensorValue>maxValue) 
    sensorValue=maxValue; 

  sensorValue = map(sensorValue,minValue,maxValue,10,100);

  Serial.println(sensorValue);

  usbMIDI.sendNoteOn(sensorValue,127,1);

  delay(100-sensorValue);

  usbMIDI.sendNoteOff(sensorValue,0,1);
  
    delay(100-sensorValue);

}









