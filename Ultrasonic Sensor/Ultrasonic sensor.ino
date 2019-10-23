#include <Servo.h>
int trigPin = 11;
int echoPin = 12;
int distCM
Servo servo;
void setup()
{
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  servo.attach(10);
}

void loop()
{
  distCM = getDistance();
  Serial.print(distCM);
  Serial.print("cm");
  Serial.println();
  // delay
  delay(250);
  if (distCM < 5)
  {
    servo.write(161);
  }
  else
    if (distCM > 10)
    {
      servo.write(70);
    }
  else
    if (5 < distCM < 10)
    {
      servo.write(90);
    }
}

int getDistance()
{
  long duration, cm, inches;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  cm = (duration/2) / 29.1;
  inches = (duration/2) / 74;
  return cm;
}
