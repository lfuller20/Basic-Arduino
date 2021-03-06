#include <Wire.h> // For I2C
#include <LiquidCrystal_I2C.h> 
const int buttonPin = 12; // Establishes the button pin
int buttonCounter = 0; // Establishes the starting value of the button counter
int buttonState = 0; // Establishes the state of the button prior to being pressed
int bpressed = 0;

LiquidCrystal_I2C lcd(0x27,16,2); 
void setup()
{
	pinMode(12, OUTPUT);
   Serial.begin(9600);
   lcd.init();
   lcd.backlight();
}
void loop()
{
   lcd.setCursor(0,0);
   lcd.print("Button Presses: "); // tells LCD to say hello world. 
   buttonState = digitalRead(buttonPin);
   Serial.print(buttonState);
   if ((buttonState == HIGH) && (bpressed == 0))
   {
   	buttonCounter = buttonCounter + 1; // Increases the value of the button counter by 1.
   	lcd.setCursor(0,1);
   	lcd.print(buttonCounter); 
   	bpressed = 1; 
   }
   if (buttonState == LOW)
   {
   	bpressed = 0;
   }
 }
