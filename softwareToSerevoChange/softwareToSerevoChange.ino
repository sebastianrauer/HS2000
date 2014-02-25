// Controlling a servo position using a potentiometer (variable resistor) 
// by Michal Rinott <http://people.interaction-ivrea.it/m.rinott> 

#include <Servo.h> 

Servo myservo;  // create servo object to control a servo 

int potpin = A10;  // analog pin used to connect the potentiometer
int val;    // variable to read the value from the ableton analog pin 

int myChannel = 1; //midi Channel
int myControl = 10; //controller Number
int myControllerValue; //Wert von Controller

int potVal;

void myControlChange(byte theChannel, byte theControl, byte theValue)
{
  if((theControl==myControl)||(theChannel==myChannel))
  {
    myControllerValue=theValue;
  }
}

void setup() 
{ 
  usbMIDI.setHandleControlChange(myControlChange);
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object 
} 

void loop() 
{ 
  potVal = analogRead(potpin);            // reads the value of the potentiometer (value between 0 and 1023) 
  val = map(myControllerValue, 0, 1023, 0, 127);     // scale it to use it with the servo (value between 0 and 180) 
  usbMIDI.sendControlChange(myControl, potVal, myChannel);      // midi controller change
  myservo.write(potVal);                  // sets the servo position according to the scaled value 
  delay(2);                           // waits for the servo to get there 
} 


