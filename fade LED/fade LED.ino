int led = 9;          
int brightness = 0;  
int fadeAmount = 5;   

void setup() {
  pinMode(led, OUTPUT);
  Serial.begin(9600); 
}

void loop() {
  analogWrite(led, brightness);

  brightness = brightness + fadeAmount;

  if (brightness <= 0 || brightness >= 255) {
    fadeAmount = -fadeAmount;
  }
  Serial.println(brightness);
  delay(20);
}
