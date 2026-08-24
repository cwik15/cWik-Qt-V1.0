#include "sensor.h"
#include "config.h"

void initSensor()
{
    pinMode(TRIG_PIN, OUTPUT);
    pinMode(ECHO_PIN, INPUT);

    digitalWrite(TRIG_PIN, LOW);
}

float getDistance()
{
    digitalWrite(TRIG_PIN, LOW);
    delayMicroseconds(2);

    digitalWrite(TRIG_PIN, HIGH);
    delayMicroseconds(10);

    digitalWrite(TRIG_PIN, LOW);

    unsigned long duration = pulseIn(ECHO_PIN, HIGH, 30000);

    if(duration == 0)
        return 999;

    float distance = duration * 0.0343 / 2.0;

    return distance;
}

bool obstacleDetected()
{
    return getDistance() <= SAFE_DISTANCE;
}