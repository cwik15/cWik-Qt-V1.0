#ifndef MOTORS_H
#define MOTORS_H

#include <Arduino.h>

void initMotors();

void moveForward(uint8_t speed = 180);
void moveBackward(uint8_t speed = 180);

void turnLeft(uint8_t speed = 180);
void turnRight(uint8_t speed = 180);

void stopMotors();

#endif