/*
  AnalogReadSerial
 Reads an analog input on pin 0, prints the result to the serial monitor.
 Attach the center pin of a potentiometer to pin A0, and the outside pins to +5V and ground.
 
 This example code is in the public domain.
 */
 
 int maxValue = 700;
int minValue = 300;

// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
}

// the loop routine runs over and over again forever:
void loop() {
  // read the input on analog pin 0:
  int sensorValue = analogRead(A0);
  Serial.println(sensorValue);
  
    sensorValue = map(sensorValue,minValue,maxValue,0,127);

  if(sensorValue<minValue) sensorValue=minValue; // geht auch: value=constrain(value,minValue,maxValue)
  if(sensorValue>maxValue) sensorValue=maxValue; // "constrain" bedeutet: "nötigen"


  Serial.println(sensorValue);
  //sensorValue = map(sensorValue,minValue,maxValue,0,127);

  usbMIDI.sendNoteOn(sensorValue,127,1);

  delay(50);

  usbMIDI.sendNoteOff(minValue,127,1);

  delay(25);
}

