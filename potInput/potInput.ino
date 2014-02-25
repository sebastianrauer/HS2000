int ledPin = 9;
int potPin = A10;
int value;

setup void()
{

}

void loop()
{
value = analogRead()potPin);
value = map(value,0,1023,0,255);
analogWrite(ledPin, value);
}
