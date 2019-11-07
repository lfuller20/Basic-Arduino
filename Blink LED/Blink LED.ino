#include "Arduino.h"

int led =13;
int brightness = 0; 
int fadeAmount = 5; 

void setup()
{
	pinMode(led, OUTPUT); // sets pin as output
}

void loop()
{
	analogWrite(led, brightness); // sets brightness
	brightness =  brightness + fadeAmount;
	if (brightness <= 0 || brightness >= 255) {
		fadeAmount = -fadeAmount;
	}
	
	delay(30);
}
