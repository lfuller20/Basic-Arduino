const byte ledPin = 13;
const byte interruptPin = 2;
volatile byte state = LOW;

void setup ()
{
	Serial.begin(9600);
	pinMode(ledPin, OUTPUT);
	pinMode(interruptPin, INPUT_PULLUP);
	attachInterrupt(digitalPinToInterrupt(interruptPin), blink, RISING);
}

void loop ()
{
	digitalWrite(ledPin, state);
	Serial.println(state);
}

void blink()
{
	state = !state;	
}