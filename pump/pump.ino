#include <analogWrite.h>

const int PUMP_PIN = 23;

void setup() {
  // put your setup code here, to run once:
pinMode(PUMP_PIN, OUTPUT);
analogWrite(PUMP_PIN, 165);
}

void loop() {
  // put your main code here, to run repeatedly:
}
