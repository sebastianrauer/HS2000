 int ledPin = 9;                    // LED connected to digital pin 9
 int potPin = A0;                   // Pin, an dem das Potentiometer angeschlossen ist
 int value;                         // speichert Wert des Potentiometers
 
 int minValue = 0;
 int maxValue = 1023;
 
 void setup()  { 
   Serial.begin(9600);              // startet serielle Datenübertragung
 } 
 
 void loop()  { 
   value = analogRead(potPin);        // liefert den Wert des Potis und speichert ihn in der V.
   Serial.println(value);             // sendet Value an seriellen Port
   if (value<minValue) {value=minValue;}  
   if (value>maxValue) {value=maxValue;}  
   // alternativ zu den ifs:   value=constrain(value,minValue,maxValue);
   value = map(value,minValue,maxValue,0,127);   // map(eingehend, eigehendUnten, eingehenOben, zielUnten, zielOben);    
   analogWrite(ledPin, value*2);           
   usbMIDI.sendControlChange(7, value, 1);      // midi controller change
   delay(10);
 }
