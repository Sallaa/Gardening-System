#include <ESP32_Servo.h>

Servo myservo;

// analog pin used to connect the potentiometer
int input_pin = A0;
// Pin to control the servo
const int servo_pin = 21;

// variable to read the value from the analog pin
int val;

void setup() {
  // attaches the servo on pin 9 to the servo object
//  pinMode(button, INPUT);
  myservo.attach(servo_pin);
  Serial.begin(9600);
}

void loop() {
  // reads the value of the potentiometer (value between 0 and 1023)
//  val = analogRead(input_pin);
  // scale it to use it with the servo (value between 0 and 180)
//  val = map(val, 0, 4095, 0, 179);
  // sets the servo position according to the scaled value
  
    myservo.write(90);
    delay(2000);

   myservo.write(0);
  delay(2000);

  
}
