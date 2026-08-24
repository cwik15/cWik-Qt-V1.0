#ifndef CONFIG_H
#define CONFIG_H

#include <Arduino.h>

// ==========================================================
// OLED (I2C)
// ==========================================================
constexpr uint8_t OLED_SDA = 21;
constexpr uint8_t OLED_SCL = 22;

// ==========================================================
// TB6612FNG Motor Driver
// ==========================================================
constexpr uint8_t PWMA = 25;
constexpr uint8_t AIN1 = 26;
constexpr uint8_t AIN2 = 27;

constexpr uint8_t PWMB = 33;
constexpr uint8_t BIN1 = 32;
constexpr uint8_t BIN2 = 13;

constexpr uint8_t STBY = 14;

// ==========================================================
// Servo Pins
// ==========================================================
constexpr uint8_t LEFT_ARM_PIN  = 18;
constexpr uint8_t RIGHT_ARM_PIN = 19;

// ==========================================================
// HC-SR04
// ==========================================================
constexpr uint8_t TRIG_PIN = 5;
constexpr uint8_t ECHO_PIN = 4;

// ==========================================================
// Robot Motion
// ==========================================================
constexpr uint8_t DEFAULT_SPEED = 180;
constexpr uint8_t TURN_SPEED    = 180;
constexpr uint8_t BACK_SPEED    = 150;

constexpr float SAFE_DISTANCE = 20.0f;

// ==========================================================
// Timing (milliseconds)
// ==========================================================
constexpr unsigned long BOOT_TIME      = 1500;
constexpr unsigned long BACKUP_TIME    = 350;
constexpr unsigned long TURN_TIME      = 450;
constexpr unsigned long DANCE_MIN_TIME = 20000;
constexpr unsigned long DANCE_MAX_TIME = 40000;

// ==========================================================
// Servo Angles
// Change these ONLY if your servos move differently.
// ==========================================================
constexpr uint8_t LEFT_ARM_DOWN  = 20;
constexpr uint8_t LEFT_ARM_UP    = 120;

constexpr uint8_t RIGHT_ARM_DOWN = 160;
constexpr uint8_t RIGHT_ARM_UP   = 60;

// ==========================================================
// Eye Animation
// ==========================================================
constexpr unsigned long BLINK_INTERVAL_MIN = 3000;
constexpr unsigned long BLINK_INTERVAL_MAX = 7000;

constexpr unsigned long BLINK_DURATION = 120;

#endif