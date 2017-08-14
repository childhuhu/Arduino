#include "Arduino.h"

#define EN1  5//control right motor speed
#define EN2  6//control left motor speed
#define IN1  4//control right motor direction
#define IN2  7//control left motor direction
#define FORW 1//forward
#define BACK 0//backward
#define SPEED 255//0-255
#define STOP_CTL '0'
#define FORW_CTL '1'
#define BACK_CTL '2'
#define LEFT_CTL '3'
#define RIGHT_CTL '4'

void MotorControl(int M1_DIR,int M1_EN,int M2_DIR,int M2_EN)
{
  //M1
  if(M1_DIR==FORW)//Motor 1 direction
    digitalWrite(IN1,HIGH);
  else
    digitalWrite(IN1,LOW);
  if(M1_EN==0)//Motor 1 speed
    analogWrite(EN1,LOW);//stop
  else
    analogWrite(EN1,M1_EN);//analog value of speed
  //M2
  if(M2_DIR==FORW)
    digitalWrite(IN2,HIGH);
  else
    digitalWrite(IN2,LOW);
  if(M2_EN==0)
    analogWrite(EN2,LOW);
  else
    analogWrite(EN2,M2_EN);
}

void setup()
{
  Serial.begin(9600);
  pinMode(EN1, OUTPUT);
  pinMode(EN2, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
}

char lastKey = STOP_CTL;

void loop()
{
    char thisKey = lastKey;
    if (Serial.available() > 0) {
        thisKey = Serial.read();
    }
    switch (thisKey) {
        case STOP_CTL:
            MotorControl(FORW,0,FORW,0);
            break;
        case FORW_CTL:
            MotorControl(FORW,SPEED,FORW,SPEED);
            break;
        case BACK_CTL:
            MotorControl(BACK,SPEED,BACK,SPEED);
            break;
        case LEFT_CTL:
            MotorControl(BACK,SPEED,FORW,SPEED);
            break;
        case RIGHT_CTL:
            MotorControl(FORW,SPEED,BACK,SPEED);
            break;
        default:
            break;
    }
    lastKey = thisKey;
  }
