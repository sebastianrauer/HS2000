
int green = 10;
int ton = 42;
int buttonPin = 6;
int buttonPin02 = 9;
int regler = A10;

void setup() {                
  pinMode(green, OUTPUT);     
  pinMode(buttonPin, INPUT);
  pinMode(buttonPin02, INPUT);
  Serial.begin(38400);
}

int val;

void loop(){

  val = analogRead(0);
  Serial.print("analog 0 is: ");
  Serial.println(val);

  usbMIDI.sendControlChange(48,analogRead(A0)/8,1);
  val = analogRead(0) / 8; // read value from pot and make value from 0 - 127 
  Serial.print(val, BYTE); // print value to serial port 

  if 
    (digitalRead(buttonPin)==HIGH)
  {
    digitalWrite(green, HIGH);   // turn the LED on (HIGH is the voltage level)
    usbMIDI.sendNoteOn(ton, 100, 10);

    digitalWrite(green, LOW);   // turn the LED on (HIGH is the voltage level)
    usbMIDI.sendNoteOn(ton, 100, 10);
  }

else
{
  digitalWrite(green, LOW);    // turn the LED off by making the voltage LOW
  usbMIDI.sendNoteOff(ton, 0, 10);
}

delay(250);

}












