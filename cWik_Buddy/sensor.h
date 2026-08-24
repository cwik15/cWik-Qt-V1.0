#ifndef SENSOR_H
#define SENSOR_H

#include <Arduino.h>

void initSensor();

float getDistance();

bool obstacleDetected();

#endif