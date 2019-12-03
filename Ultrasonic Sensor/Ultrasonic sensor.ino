#include <Servo.h>
int trigPin = 11;
int echoPin = 12;
int distCM
Servo servo;
void setup()
{
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT); // specifies which pin on the sensor is the output
  pinMode(echoPin, INPUT); // specifies which pin on the sensor is the input
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
  if (distCM < 5) // states that if the distance is less than 5 cm the servo turns one way
  {
    servo.write(161); 
  }
  else
    if (distCM > 10) // states that if the distance is greater than 10 cm the servo turns the other way
    {
      servo.write(70);
    }
  else
    if (5 < distCM < 10) // states that if the distance is between 5cm and 10cm the servo does not move
    {
      servo.write(90);
    }
}

int getDistance() // gets the distance in cm
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
