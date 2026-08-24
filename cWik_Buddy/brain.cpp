#include "brain.h"

#include "state.h"
#include "config.h"

#include "motors.h"
#include "servos.h"
#include "sensor.h"
#include "eyes.h"
#include "animation.h"

RobotState currentState = RobotState::BOOT;

unsigned long stateTimer = 0;
unsigned long nextDance = 0;

//====================================================

void initBrain()
{
    randomSeed(millis());

    stateTimer = millis();

    nextDance = millis() + random(DANCE_MIN_TIME, DANCE_MAX_TIME);

    currentState = RobotState::BOOT;
}

//====================================================

void updateBrain()
{
    switch(currentState)
    {
        //------------------------------------------
        case RobotState::BOOT:
        //------------------------------------------

            sleepyFace();

            if(millis() - stateTimer >= BOOT_TIME)
            {
                startupAnimation();

                happyFace();

                currentState = RobotState::EXPLORE;
            }

        break;

        //------------------------------------------
        case RobotState::EXPLORE:
        //------------------------------------------

            normalFace();

            moveForward(DEFAULT_SPEED);

            if(obstacleDetected())
            {
                stopMotors();

                confusedFace();

                currentState = RobotState::STOP;

                stateTimer = millis();
            }

            if(millis() >= nextDance)
            {
                stopMotors();

                currentState = RobotState::DANCE;
            }

        break;

        //------------------------------------------
        case RobotState::STOP:
        //------------------------------------------

            stopMotors();

            if(millis() - stateTimer > 300)
            {
                currentState = RobotState::BACK_UP;

                stateTimer = millis();
            }

        break;

        //------------------------------------------
        case RobotState::BACK_UP:
        //------------------------------------------

            moveBackward(BACK_SPEED);

            if(millis() - stateTimer >= BACKUP_TIME)
            {
                currentState = RobotState::TURN_LEFT;

                stateTimer = millis();
            }

        break;

        //------------------------------------------
        case RobotState::TURN_LEFT:
        //------------------------------------------

            turnLeft(TURN_SPEED);

            if(millis() - stateTimer >= TURN_TIME)
            {
                stopMotors();

                currentState = RobotState::EXPLORE;
            }

        break;

        //------------------------------------------
        case RobotState::TURN_RIGHT:
        //------------------------------------------

            turnRight(TURN_SPEED);

            if(millis() - stateTimer >= TURN_TIME)
            {
                stopMotors();

                currentState = RobotState::EXPLORE;
            }

        break;

        //------------------------------------------
        case RobotState::DANCE:
        //------------------------------------------

            happyFace();

            danceAnimation();

            nextDance = millis() + random(DANCE_MIN_TIME, DANCE_MAX_TIME);

            currentState = RobotState::EXPLORE;

        break;

        //------------------------------------------
        case RobotState::WAKE:
        case RobotState::ERROR_STATE:
        //------------------------------------------
            currentState = RobotState::EXPLORE;
        break;
    }
}