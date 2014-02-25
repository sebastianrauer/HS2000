
int red = 10;
int green = 9;
int buttonPin = 6;

void setup() {                
  pinMode(red, OUTPUT);   
  pinMode(green, OUTPUT);  
  pinMode(buttonPin, INPUT);
}

void loop() {
  if (digitalRead(buttonPin)==HIGH){
    digitalWrite(red, HIGH);   // turn the LED on (HIGH is the voltage level)
    digitalWrite(green, LOW);    // turn the LED off by making the voltage LOW
  }
  else{
    digitalWrite(green, HIGH);   // turn the LED on (HIGH is the voltage level)
    digitalWrite(red, LOW);    // turn the LED off by making the voltage LOW
  }
}






