// Authors: Sebastian Cabrol, Ed Arellano Mendiola, John Petryk
// Date: 4/5/18
// Description: Code to run Colorado School of Mines exoskelton and its multiple sensors
#include "HX711.h"

const int movingAverageLen = 10;


// left encoder
const int leftEncoder = A0;
float leftEncoderPos = 0;
float leftEncoderDis = 0;
int leftENCVal = 0; // not the actual val, will be set as the average of the list below
int leftENCAvg[movingAverageLen];

// right encoder
const int rightEncoder = A1;
float rightEncoderPos = 0;
float rightEncoderDis = 0;
int rightENCVal;
int rightENCAvg[movingAverageLen];


void updateMovingAverage(int newVal, int avgArr[], int arrLen) {
  for (int i = 0; i < arrLen - 2; i++) {
    avgArr[i] = avgArr[i + 1]; // shif all values down by one
  }
  avgArr[arrLen - 1] = newVal; // set the last value to newVal
}

class LoadCell {
  
  public:
    
    LoadCell(int clkPin, int dataPin) {
      _clkPin = clkPin;
      _dataPin = dataPin;
    }

    

    
  private:
    int _movingAvgPlace;
    int _clkPin;
    int _dataPin;
    int _movingAvg[movingAverageLen];
    HX711 cell = HX711(_clkPin, _dataPin);

  
  
};

const int leftLoadCellCLK = 2;
const int leftLoadCell = 3;
HX711 leftScale(leftLoadCell, leftLoadCellCLK);
int leftLoadCellVal = 0;
int leftLCAvg[movingAverageLen];

// right load cell
const int rihgtLoadCellCLK = 4;
const int rightLoadCell = 5;
int rightLoadCellVal = 0;
int rightLCAvg[movingAverageLen];

// left actuator vals
const int leftActuatorPWM = 6;
const int leftActuatorDir = 7;

// right actuator vals
const int rightActuatorDir = 8;
const int rightActuatorPWM = 9;

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
  updateSensors();
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



void updateSensors() {
  // encoders
  
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

