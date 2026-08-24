#include "servos.h"

#include <ESP32Servo.h>
#include "config.h"

Servo leftServo;
Servo rightServo;

//======================================

void initServos()
{
    leftServo.setPeriodHertz(50);
    rightServo.setPeriodHertz(50);

    leftServo.attach(LEFT_ARM_PIN, 500, 2400);
    rightServo.attach(RIGHT_ARM_PIN, 500, 2400);

    homeArms();
}

//======================================

void setLeftArm(int angle)
{
    angle = constrain(angle, 0, 180);
    leftServo.write(angle);
}

//======================================

void setRightArm(int angle)
{
    angle = constrain(angle, 0, 180);
    rightServo.write(angle);
}

//======================================

void setBothArms(int leftAngle, int rightAngle)
{
    setLeftArm(leftAngle);
    setRightArm(rightAngle);
}

//======================================

void homeArms()
{
    setLeftArm(20);
    setRightArm(160);
}