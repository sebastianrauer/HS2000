
int pin = A8;                      
int value;                                 //speichert Wert des Lichtsensors





int maxValue = 220;                        //Maximalwert des Lichtsensorwertes (kann verändert werden je nach Lichtverhältnissen)
int minValue = 180;
int diffValue = maxValue - minValue;      //Minimalwert des Lichtsensorwertes (kann verändert werden je nach Lichtverhältnissen)


void setup()  { 
  Serial.begin(9600);                     //dient der Überprüfung des Wertes (oben rechts aus Serial Monitor klicken)
} 


void loop()  { 
  value = analogRead(pin);
  Serial.println(value);                  


  if (value<minValue) {                   // wenn extremwert erreicht ist, wird nicht erhöhr oder erniedrigt 
    value = minValue;
  }
  if (value>maxValue) {
    value = maxValue;
  }  



/* Den Lichtsensor kann man kalibrieren (d.h. Maximal- und Minimalwert (s.o.) den gegebenen Lichtverhältnissen anpassen)
   daher muss der zu verlgeichende Wert (der Wert nach "<") flexibel bleiben. Es gibt 5 verschiedene Akkorde, also gibt
   es 5 Abstufungen. mal 0,2; mal 0,4; mal 0,6 usw. So muss man im Code immer nur maxValue und minValue ändern  */
  if (value < 0.2* diffValue + minValue){ 
    //G H D
    usbMIDI.sendNoteOn(55, 127, 1);
    usbMIDI.sendNoteOn(59, 127, 1);
    usbMIDI.sendNoteOn(62, 127, 1);
    delay(500);
    usbMIDI.sendNoteOff(55, 127, 1);
    usbMIDI.sendNoteOff(59, 127, 1);
    usbMIDI.sendNoteOff(62, 127, 1);
    delay(500);

  }

  else if(value < 0.4* diffValue + minValue){
    // D F A
    usbMIDI.sendNoteOn(50, 127, 1);
    usbMIDI.sendNoteOn(53, 127, 1);
    usbMIDI.sendNoteOn(57, 127, 1);
    delay(500);
    usbMIDI.sendNoteOff(50, 127, 1);
    usbMIDI.sendNoteOff(53, 127, 1);
    usbMIDI.sendNoteOff(57, 127, 1);
    delay(500);

  }
  else if (value < 0.6* diffValue + minValue){
    //CDG
    usbMIDI.sendNoteOn(48, 127, 1);
    usbMIDI.sendNoteOn(50, 127, 1);
    usbMIDI.sendNoteOn(55, 127, 1);
    delay(500);
    usbMIDI.sendNoteOff(48, 127, 1);
    usbMIDI.sendNoteOff(50, 127, 1);
    usbMIDI.sendNoteOff(55, 127, 1);
    delay(500);
  }

  else if (value < 0.8* diffValue + minValue){
    // FAC
    usbMIDI.sendNoteOn(53, 127, 1);
    usbMIDI.sendNoteOn(67, 127, 1);
    usbMIDI.sendNoteOn(60, 127, 1);
    delay(500);
    usbMIDI.sendNoteOff(53, 127, 1);
    usbMIDI.sendNoteOff(67, 127, 1);
    usbMIDI.sendNoteOff(60, 127, 1);
    delay(500);
  }

  // ACE
  else{
    usbMIDI.sendNoteOn(57, 127, 1);
    usbMIDI.sendNoteOn(60, 127, 1);
    usbMIDI.sendNoteOn(64, 127, 1);
    delay(500);
    usbMIDI.sendNoteOff(57, 127, 1);
    usbMIDI.sendNoteOff(60, 127, 1);
    usbMIDI.sendNoteOff(64, 127, 1);
    delay(500);
  }
}











