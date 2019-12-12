#include <Servo.h>

struct Plant
{
  public:
    // Attributes
    String plantName;
    int plantPos;
    int timerWater;
    int timerFert;
    int lastHeightMeasured;
    int waterValue;
    int fertValue;

    Plant(int pP, int tW, int tF, int lHM, int wV, int fV) : plantPos(pP),
      timerWater(tW),
      timerFert(tF),
      lastHeightMeasured(lHM),
      waterValue(wV),
      fertValue(fV)
    {

    }
};

struct GardeningSystem
{
  public:
    // General Attributes
    bool isSpaceAvailable;
    //  Plant plants[4];

    // Attributes for the turntable
    const int PIN_STEP_TURNTABLE = 22;
    const int PIN_DIRECTION_TURNTABLE = 41;
    const int STEPS_PER_TURN = 200;
    const int delay_between_step_microsec = 5000; //For 60 RMS Speed
    int currentPlantFacingChamber = 0;

    //Attributes for the pump
    const int PUMP_PIN = 45;


    // Attributes for the hopper fertilizer
    Servo hopperServo;
    const int HOPPER_PIN = 43;

    //Methods

    GardeningSystem()
    {
    }

    int measureHeight()
    {
    }

    void stepTurntable(bool forward)
    {
      // setting the direction
      if (forward == true)
      {
        digitalWrite(PIN_DIRECTION_TURNTABLE, HIGH);
      }
      else
      {
        digitalWrite(PIN_DIRECTION_TURNTABLE, LOW);
      }
      delayMicroseconds(1); // minimum delay is .6us
      // creating a step
      digitalWrite(PIN_STEP_TURNTABLE, HIGH);
      delayMicroseconds(4); // minimum delay is 1.9us
      digitalWrite(PIN_STEP_TURNTABLE, LOW);
    }

    void steps(int number_of_steps)
    {
      bool move_forward = true;
      // Establishing the direction
      if (number_of_steps >= 0)
      {
        move_forward = true;
      }
      else
      {
        move_forward = false;
        number_of_steps = -number_of_steps;
      }
      // Generating the steps
      for (int i = 0; i < number_of_steps; i++)
      {
        stepTurntable(move_forward);
        // Delay for proper speed
        delayMicroseconds(delay_between_step_microsec);
      }
    }

    void rotate(int pos)
    {
      while (pos != currentPlantFacingChamber)
      {
        steps(25);
        delay(1000);
        steps(25);
        delay(1000);
        currentPlantFacingChamber++;
        currentPlantFacingChamber = currentPlantFacingChamber % 4;
      }
      delay(500);
    }

    void pourWater(int waterValue, int pos)
    {
      //Water pump is on the left of the chamber
      pos = (pos - 1);
      if (pos < 0) {
        pos = 3;
      }
      rotate(pos);
      
      delay(200);
      analogWrite(PUMP_PIN, 255);
      Serial.println("hi");
      delay(4000);
      analogWrite(PUMP_PIN, 0);
      delay(2000);
    }

    void addFert(int fertValue, int pos)
    {
      //Fertilizer hopper is on the right of the chamber
      pos = (pos + 1);
      pos = pos % 4;
      rotate(pos);
      hopperServo.write(0);
      delay(2000);
      hopperServo.write(90);
      delay(2000);
    }

    //  void senseNewPlant(){
    //    if (isSpaceAvailable){
    //      if (this.plants == NULL){
    //
    //      }
    //    }
    //  }

    void pushPlantInside(int pos)
    {
      rotate(pos);
    }

    void pushPlantOutside(int pos)
    {
      rotate(pos);
    }
};

void setup()
{
  Serial.begin(9600);
  GardeningSystem gardeningSystem;
  pinMode(gardeningSystem.PIN_STEP_TURNTABLE, OUTPUT);
  pinMode(gardeningSystem.PIN_DIRECTION_TURNTABLE, OUTPUT);
  gardeningSystem.hopperServo.attach(gardeningSystem.HOPPER_PIN);
  pinMode(gardeningSystem.PUMP_PIN, OUTPUT);

  gardeningSystem.pourWater(2, 2);
}

void loop()
{
  // put your main code here, to run repeatedly:
}
