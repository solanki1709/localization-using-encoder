// This is a code to use Stepper motor using DRV8825 driver
// DIR pin of motor driver is connected to D5 of Atmega
// STEP pin is connected to D4
// M0, M1 and M2 pins of driver are connected to B0, B1 and B2 pins respectively
// ENbar pin is grounded
// SLP and RST pins of motor driver are shorted
// The coils of motor are connected to 1A, 2A and 1B, 2B of motor driver
const int step_pin = 12;    //D4 pin of Atmega 16
const int dir_pin = 13;     //D5 pin
const int mode_0 = 1;       //
const int mode_1 = 2;       //
const int mode_2 = 3;       //

void setup() 
{
  pinMode(step_pin, OUTPUT);
  pinMode(dir_pin, OUTPUT);
  pinMode(mode_0, OUTPUT);
  pinMode(mode_1, OUTPUT);
  pinMode(mode_2, OUTPUT);
  digitalWrite(mode_0, HIGH);
  digitalWrite(mode_1, HIGH);
  digitalWrite(mode_2, HIGH);    // 32 microsteps per step
}

void loop() 
{   
  for(int i=0;i<100;i++)
  {
    motor_forw();
    motor_step();
  }
  for(int i=0;i<100;i++)
  {
    motor_rev();
    motor_step();
  }
}
void motor_forw()
{
  digitalWrite(dir_pin, HIGH);
}
void motor_rev()
{
  digitalWrite(dir_pin,LOW);
}
void motor_step()
{
  digitalWrite(step_pin, HIGH);
  delay(1);
  digitalWrite(step_pin, LOW);
  delay(1);
}

