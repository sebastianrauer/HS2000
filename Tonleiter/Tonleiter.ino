
int led = 11;
int melodie[10]={
  50,30,20,10,100,50,100,30,20,10};


void setup() {                
  pinMode(led, OUTPUT);     
}

void loop(){

  for(int ton=0; ton<10; ton=ton+1){
    digitalWrite(led, HIGH);   // turn the LED on (HIGH is the voltage level)
    usbMIDI.sendNoteOn(melodie[ton], 127, 1);
    delay(250);
    digitalWrite(led, LOW);    // turn the LED off by making the voltage LOW
    usbMIDI.sendNoteOff(melodie[ton], 0, 1);
    delay(100);

  }
}


