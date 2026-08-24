#include "animation.h"
#include "servos.h"
#include "config.h"

#include <Arduino.h>

void startupAnimation()
{
    homeArms();
    delay(500);

    waveAnimation();

    homeArms();
}

void waveAnimation()
{
    for(int i = 0; i < 3; i++)
    {
        setRightArm(RIGHT_ARM_UP);
        delay(250);

        setRightArm(RIGHT_ARM_DOWN);
        delay(250);
    }

    homeArms();
}

void danceAnimation()
{
    for(int i = 0; i < 4; i++)
    {
        setLeftArm(LEFT_ARM_UP);
        setRightArm(RIGHT_ARM_DOWN);
        delay(250);

        setLeftArm(LEFT_ARM_DOWN);
        setRightArm(RIGHT_ARM_UP);
        delay(250);
    }

    homeArms();
}