#include <Wire.h> // For I2C
#include <LiquidCrystal_I2C.h> 
LiquidCrystal_I2C lcd(0x27,16,2); 

void setup()
{
   Serial.begin(9600);
   lcd.init();
   lcd.backlight();
}
void loop()
{
   lcd.setCursor(0,0);
   lcd.print("Hello world"); // tells LCD to say hello world. 
   lcd.setCursor(0,1); // Go to home of 2nd line
   lcd.print(millis() / 1000);
}