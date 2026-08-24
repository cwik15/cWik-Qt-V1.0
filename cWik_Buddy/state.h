#ifndef STATE_H
#define STATE_H

enum class RobotState
{
    // Startup
    BOOT,
    WAKE,

    // Normal behaviour
    EXPLORE,

    // Obstacle handling
    STOP,
    BACK_UP,
    TURN_LEFT,
    TURN_RIGHT,

    // Personality
    DANCE,

    // Error
    ERROR_STATE
};

#endif