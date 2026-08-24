#include "config.h"

#include "motors.h"
#include "servos.h"
#include "sensor.h"
#include "eyes.h"
#include "animation.h"
#include "brain.h"

void setup()
{
    Serial.begin(115200);

    initEyes();
    initMotors();
    initServos();
    initSensor();
    initBrain();

    Serial.println("cWik Buddy V1.0");
}

void loop()
{
    updateBrain();
}