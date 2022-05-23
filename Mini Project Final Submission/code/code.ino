#include <Servo.h> // include servo library to use its related functions
#define Gate 7
Servo Myservo;

int pos;
int buzzer = 10;
int smokeA0 = A5;
// Your threshold value
int sensorThres = 400;

void setup() {
  Myservo.attach(4);
  pinMode(buzzer, OUTPUT);
  pinMode(smokeA0, INPUT);
  // put your setup code here, to run once:
  pinMode(Gate, OUTPUT);
  //
  digitalWrite(Gate,LOW);
  Serial.begin(9600);
}

void loop() {
  int analogSensor = analogRead(smokeA0);

  
  Serial.print("Pin A0: ");
  Serial.println(analogSensor);
  // Checks if it has reached the threshold value
  if (analogSensor > sensorThres)
  {
    Serial.println("0");// You can display on the serial the signal value
    analogWrite(Gate,1000);
    tone(buzzer, 4000, 3000);
    Myservo.write(0);
    delay(3000);
    analogWrite(Gate,0000);
    noTone(buzzer);
  }
}
