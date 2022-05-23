#include <Servo.h>
#include <SoftwareSerial.h>

#define MQPin A0
#define buzzer 7
#define fan 10

//SoftwareSerial SIM900(2, 3); // GSM Module object to control a GSM Module
Servo myservo;  // servo object to control a servo
int pos = 0;    // variable to store the servo position


void setup() {
//    SIM900.begin(2400); // Baud rate of gsm module
//    Serial.begin(9600); // Baud rate of serial monitor
    pinMode(MQPin, INPUT_PULLUP);
    pinMode(buzzer, OUTPUT);
    pinMode(fan, OUTPUT);
    myservo.attach(13);  // attaches the servo on pin 13 to the servo object
    
}

void loop() {

  int gas_value = digitalRead(MQPin);
  
  if(gas_value==HIGH)
    {
      digitalWrite(buzzer, HIGH);
      for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
      // in steps of 1 degree
         myservo.write(pos);              // tell servo to go to position in variable 'pos'
      } 
      
      digitalWrite(fan,HIGH);
      delay(1000);
      digitalWrite(fan,LOW);
    }
  if(gas_value==LOW)
    {
      digitalWrite(buzzer, LOW); 
      
    }
  

}

//void sendMsg(){
//SIM900.print("AT+CMGF=1\r"); 
//Serial.print("AT+CMGF=1\r"); // AT command to send SMS message text format
//SIM900.println("AT + CMGS = \"+91xxxxxxxxxx\"");// recipient's mobile number
//Serial.println("AT + CMGS = \"+91xxxxxxxxxx\""); // recipient's mobile number
//SIM900.println("GAS is Detected go home as soon as possible or Inform somebody."); // message to send
//Serial.println("GAS is Detected go home as soon as possible or Inform somebody.");
//SIM900.println((char)26); // End AT command with a ^Z, ASCII code 26
//Serial.println((char)26);
//
//do {} while (1);
//}
