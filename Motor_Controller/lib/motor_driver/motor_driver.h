#ifndef MOTOR_DRIVER_H_
#define MOTOR_DRIVER_H_

#include <Arduino.h>
#include <config.h>
#include "commands.h"

//pwm paramters
const int mtr_left_pwm_channel = 8;
const int mtr_right_pwm_channel = 9;
const int lresolution = 8;
const int freq = 4000;

void robot_setup();
void initMotorController();
void setMotorSpeed(int i, int spd);
void setMotorSpeeds(int leftSpeed, int rightSpeed);

#endif   