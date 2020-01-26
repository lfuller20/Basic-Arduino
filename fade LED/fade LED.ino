int led = 9;          
int brightness = 0;  
int fadeAmount = 5; // specifies the variable of the fade amount

void setup() {
  pinMode(led, OUTPUT);
  Serial.begin(9600); // starts the serial monitor
}

void loop() {
  analogWrite(led, brightness);

  brightness = brightness + fadeAmount; 

  if (brightness <= 0 || brightness >= 255) {
    fadeAmount = -fadeAmount;
  }
  Serial.println(brightness); // prints the brightness of the led as it is fading in and out
  delay(20);
}
