

#include <LiquidCrystal.h>
#include <Servo.h>

LiquidCrystal lcd(7, 6, 5, 4, 3, 2);

#define MQPin A0
#define buzzer 1


Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

int pos = 0;    // variable to store the servo position
int val = 200;

void setup() {
   myservo.attach(13);  // attaches the servo on pin 13 to the servo object
   lcd.begin(16, 2);
   pinMode(MQPin, INPUT_PULLUP);
   pinMode(buzzer, OUTPUT);
   lcd.setCursor(5, 0);
   lcd.print("GAS");
   lcd.setCursor(3, 1);
   lcd.print("DETECTOR");
   delay(1000);
   analogWrite(9,0);
  analogWrite(10,0);
   lcd.clear();
}

void loop() {

int gas_value = digitalRead(MQPin);

if(gas_value==HIGH)
{
  digitalWrite(buzzer, HIGH);
  lcd.setCursor(6, 0);
  lcd.print("GAS");
  lcd.setCursor(3, 1);
  lcd.print("DETECTED");
  
  for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
  }
  
  analogWrite(9,val);
  analogWrite(10,0);
  
  
}
else
{
 lcd.clear();
 analogWrite(9,0);
 analogWrite(10,0);
 digitalWrite(buzzer, LOW); 
}
  

}
