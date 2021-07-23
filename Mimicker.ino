#include <Servo.h> // Servo library

// initialize potentiometer pins for analog data;
#define pot_pin_claw  A0; // pot for claw of the arm
#define pot_pin_bottom  A1; // pot for base of the arm
#define pot_pin_joint1  A2; // pot for joint 1 of the arm
#define pot_pin_joint2  A3; // pot for joint 2 of the arm

int pot_inputs[4]; // array of potentiometer values
int value_claw;
int value_bottom;
int value_joint1;
int value_joint2;

// servo objects for each positon of joint same as pot_inputs
Servo servo_claw;
Servo servo_bottom;
Servo servo_joint1;
Servo servo_joint2;

void setup()
{
  // configure pins for servo control
  servo_claw.attach(2);
  servo_bottom.attach(3);
  servo_joint1.attach(4);
  servo_joint2.attach(5);
  Serial.begin(9600); // set baud rate at 9600 for serial communication
}

void loop() // main loop
{
  // get the pot values (position of pot)
  pot_inputs[0] = analogRead(pot_pin_claw);
  pot_inputs[1] = analogRead(pot_pin_bottom);
  pot_inputs[2] = analogRead(pot_pin_joint1);
  pot_inputs[3] = analogRead(pot_pin_joint2);
  // print the pot values to serial monitor
  Serial.println("Claw: " + String(pot_inputs[0]) + ", Bottom: " + String( pot_inputs[1]));
  Serial.println("Joint1: " + String( pot_inputs[2]) + ", Joint2: " + String( pot_inputs[3]) + "\n");
  // map teh pot values to servo positions (this might be different for different setup)
  value_claw = map(pot_inputs[0], 0, 1023, 150, 0);
  value_bottom = map(pot_inputs[1], 110, 800, 180, 0);
  value_joint1 = map(pot_inputs[2], 1023, 600, 30, 160);
  value_joint2 = map(pot_inputs[3], 170, 880, 180, 0);
  // set the servo position same as the pot position
  servo_claw.write(value_claw);
  servo_bottom.write(value_bottom);
  servo_joint1.write(value_joint1);
  servo_joint2.write(value_joint2);
}
