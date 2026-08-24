#include "motors.h"
#include "config.h"

void initMotors()
{
    pinMode(AIN1, OUTPUT);
    pinMode(AIN2, OUTPUT);
    pinMode(PWMA, OUTPUT);

    pinMode(BIN1, OUTPUT);
    pinMode(BIN2, OUTPUT);
    pinMode(PWMB, OUTPUT);

    pinMode(STBY, OUTPUT);

    digitalWrite(STBY, HIGH);

    stopMotors();
}

//==========================================

void moveForward(uint8_t speed)
{
    digitalWrite(AIN1, HIGH);
    digitalWrite(AIN2, LOW);

    digitalWrite(BIN1, HIGH);
    digitalWrite(BIN2, LOW);

    digitalWrite(PWMA, HIGH);
    digitalWrite(PWMB, HIGH);
}

//==========================================

void moveBackward(uint8_t speed)
{
    digitalWrite(AIN1, LOW);
    digitalWrite(AIN2, HIGH);

    digitalWrite(BIN1, LOW);
    digitalWrite(BIN2, HIGH);

    digitalWrite(PWMA, HIGH);
    digitalWrite(PWMB, HIGH);
}

//==========================================

void turnLeft(uint8_t speed)
{
    digitalWrite(AIN1, LOW);
    digitalWrite(AIN2, HIGH);

    digitalWrite(BIN1, HIGH);
    digitalWrite(BIN2, LOW);

    digitalWrite(PWMA, HIGH);
    digitalWrite(PWMB, HIGH);
}

//==========================================

void turnRight(uint8_t speed)
{
    digitalWrite(AIN1, HIGH);
    digitalWrite(AIN2, LOW);

    digitalWrite(BIN1, LOW);
    digitalWrite(BIN2, HIGH);

    digitalWrite(PWMA, HIGH);
    digitalWrite(PWMB, HIGH);
}

//==========================================

void stopMotors()
{
    digitalWrite(PWMA, LOW);
    digitalWrite(PWMB, LOW);

    digitalWrite(AIN1, LOW);
    digitalWrite(AIN2, LOW);

    digitalWrite(BIN1, LOW);
    digitalWrite(BIN2, LOW);
}