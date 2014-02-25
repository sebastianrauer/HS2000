byte val; // create variable to store data 

void setup() { 
Serial.begin(57600); // open serial port 
} 

void loop() { 
val = analogRead(0) / 8; // read value from pot and make value from 0 - 127 
Serial.print(val, BYTE); // print value to serial port 
delay(5); // wait for a brief moment 
} 
