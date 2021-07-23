# Mimicker

Mimicker is an Arduino based bot to mimic robotic arm movement. It was created during six days workshop at Grammar school. It copies the movement of the robotic arm as we move it.

## Components Used

1. Arduino Uno
1. Servo Motor *4
1. Potentiometer *4
1. Lipo Battery
1. Bread Board

## Working

Two robotic arms are created, one using potentiometer and another using servo motors. The input from potentiometer arm is used as output for servo arm. The positon of pot is read through analog pins, mapped to the respective range for the servo motor and sent to the servo motor. The servo motros move accordingly to the received value.