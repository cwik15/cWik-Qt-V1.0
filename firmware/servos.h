#ifndef SERVOS_H
#define SERVOS_H

#include <Arduino.h>

void initServos();

void setLeftArm(int angle);
void setRightArm(int angle);

void setBothArms(int leftAngle, int rightAngle);

void homeArms();

#endif