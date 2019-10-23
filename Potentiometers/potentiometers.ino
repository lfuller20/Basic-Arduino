#include <LiquidCrystal.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
int ledPin = 11; 
int potPin = 0;
int brightness = 0;

void setup()
{
	pinMode(ledPin, OUTPUT);
	pinMode(potPin, INPUT);
	Serial.begin(9600);
	lcd.init();
	lcd.backlight();
	lcd.setCursor(0,0);
	lcd.print("Brightness:");
}

void loop()
{
	brightness = analogRead(0);
	brightness = map(brightness, 0, 1023, 0, 10);
	lcd.setCursor(0,1);
	lcd.print(brightness);
	lcd.print("    ");
	brightness = map(brightness, 0, 10, 0, 255);
	analogWrite(ledPin, brightness);
}