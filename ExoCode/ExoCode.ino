// Authors: Sebastian Cabrol, Ed Arellano Mendiola, John Petryk
// Date: 4/5/18
// Description: Code to run Colorado School of Mines exoskelton and its multiple sensors
#include "HX711.h"



int leftEncoder = 0;
int rightEncoder = 1;
int leftPotentiometer = 2;
int rightPotentiometer = 3;
int leftLoadCellCLK = 2;
int leftLoadCell = 3;
int rihgtLoadCellCLK = 2;
int rightLoadCell = 5;

float leftEncoderPos = 0;
float leftEncoderDis = 0;
float rightEncoderPos = 0;
float rightEncoderDis = 0;
float leftActuatorPos = 0;
float rightActuatorPos = 0;

const float displacementToMove = .25;

float loadWeight = 0;

void setup() {
  pinMode(leftEncoder, INPUT);
  pinMode(rightEncoder, INPUT);
  pinMode(leftPotentiometer, INPUT);
  pinMode(rightPotentiometer, INPUT);
  pinMode(leftLoadCell, INPUT);
  pinMode(rightLoadCell, INPUT);

  
  
  Serial.begin(9600);
}

void loop() {
  updateDisplacementSpring();
  if(leftEncoderDis >= displacementToMove) {
    // Move left Actuator
  }
  if(rightEncoderDis >= displacementToMove) {
    // Move right Actuator
  }
  
}

void updateDisplacementSpring() {
  currentPosLeft = (analogRead(leftEncoder)) * 5 / 1023;
  currentPosRight = (analogRead(rightEncoder)) * 5 / 1023;
  leftEncoderDis = leftEncoderPos - currentPosLeft;
  rightEncoderDis = rightEncoderPos - currentPosRight;
}

float loadCellForce(int pin) {
   
}

void calibrateLoadCell(int pin) {
  
}

void updateActuatorPos() {
  leftActuatorPos = analogRead(leftPotentiometer) * 20.32 / 1023;
  rightActuatorPos = analogRead(rightPotentiometer) * 20.32 / 1023;
}

void moveActuator(int pin, int speed) {
  
}

