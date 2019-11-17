#include <analogWrite.h>
/*
* Arduino code for SN754410 H-bridge
* motor driver control.
* copyleft Feb. 2010, Fabian Winkler *
*/
int speedPin = 13;
int motor1APin = 16;
int motor2APin = 17;
int speed_value_motor1;

void setup() {
pinMode(speedPin, OUTPUT); 
pinMode(motor1APin, OUTPUT); 
pinMode(motor2APin, OUTPUT);  
}

void loop() {
// put motor in forward motion
digitalWrite(motor1APin, LOW); // set leg 1 of the H-bridge low
digitalWrite(motor2APin, HIGH); // set leg 2 of the H-bridge high

//speed_value_motor1 = 0;
//digitalWrite(motor2APin, LOW);
//digitalWrite(motor1APin, HIGH); // set leg 1 of the H-bridge low

// just invert the above values for reverse motion, // i.e. motor1APin = HIGH and motor2APin = LOW
// control the speed 0- 255
speed_value_motor1 = 127; // half speed
analogWrite(speedPin, speed_value_motor1); // output speed as PWM Value
}
