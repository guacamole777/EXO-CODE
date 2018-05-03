// Authors: Sebastian Cabrol, Ed Arellano Mendiola, John Petryk
// Date: 4/5/18
// Description: Code to run Colorado School of Mines exoskelton and its multiple sensors
#include "HX711.h"


// Encoder pins and variables
const int leftEncoder = A0;
const int rightEncoder = A1;
float leftEncoderPos = 0;
float leftEncoderDis = 0;
float rightEncoderPos = 0;
float rightEncoderDis = 0;

const int leftLoadCellCLK = 2;
const int leftLoadCell = 3;
const int rihgtLoadCellCLK = 4;
const int rightLoadCell = 5;

const int leftActuatorPWM = 6;
const int rightActuatorPWM = 9;
const int leftActuatorDir = 7;
const int rightActuatorDir = 8;

const float displacementToMove = .25;

float loadWeight = 0;

const int UP = 0;
const int DOWN = 1;
const boolean LEFT = true;
const boolean RIGHT = false;

boolean moving = false;

void setup() {
  pinMode(leftEncoder, INPUT);
  pinMode(rightEncoder, INPUT);

  pinMode(leftLoadCell, INPUT);
  pinMode(rightLoadCell, INPUT);

  pinMode(leftActuatorDir, OUTPUT);
  pinMode(rightActuatorDir, OUTPUT);
  pinMode(leftActuatorPWM, OUTPUT);
  pinMode(rightActuatorPWM, OUTPUT);


  
  
  Serial.begin(9600);
}

void loop() {
  if (moving) {
    
  }
  else {
    updateDisplacementSpring();
    if(leftEncoderDis > displacementToMove) {
      moveActuator(LEFT, UP);    
    } else if (-leftEncoderDis > displacementToMove) {
      moveActuator(LEFT, DOWN);    
    }
    if(rightEncoderDis > displacementToMove) {
     moveActuator(RIGHT, UP);    
    } else if (-rightEncoderDis > displacementToMove) {
      moveActuator(RIGHT, UP);    
    }
  }
}

void updateDisplacementSpring() {
  currentPosLeft = (analogRead(leftEncoder)) * 5 / 1023;
  currentPosRight = (analogRead(rightEncoder)) * 5 / 1023;
  leftEncoderDis = leftEncoderPos - currentPosLeft;
  rightEncoderDis = rightEncoderPos - currentPosRight;
}

float leftLoadCellForce() {
   
}

float rightLoadCellForce() {
   
}

void leftCalibrateLoadCell() {
  
}

void rightCalibrateLoadCel() {
  
}


void moveActuator(int pin, int dir) {
  
}

