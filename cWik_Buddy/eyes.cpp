#include "eyes.h"

#include <Wire.h>
#include <U8g2lib.h>

U8G2_SSD1306_128X64_NONAME_F_HW_I2C
u8g2(U8G2_R0,U8X8_PIN_NONE);

//=====================================================

static void clear()
{
    u8g2.clearBuffer();
}

//=====================================================

static void show()
{
    u8g2.sendBuffer();
}

//=====================================================

void initEyes()
{
    u8g2.begin();

    normalFace();
}

//=====================================================

void normalFace()
{
    clear();

    u8g2.drawRBox(20,18,30,30,8);
    u8g2.drawRBox(78,18,30,30,8);

    u8g2.drawDisc(35,33,4);
    u8g2.drawDisc(93,33,4);

    show();
}

//=====================================================

void sleepyFace()
{
    clear();

    u8g2.drawLine(20,34,50,34);
    u8g2.drawLine(78,34,108,34);

    show();
}

//=====================================================

void happyFace()
{
    clear();

    u8g2.drawArc(35, 32, 15, 32, 96);
    u8g2.drawArc(93, 32, 15, 32, 96);

    show();
}

//=====================================================

void confusedFace()
{
    clear();

    u8g2.drawRBox(20,18,30,30,8);

    u8g2.drawCircle(93,33,10);

    u8g2.drawDisc(35,33,4);
    u8g2.drawDisc(93,33,3);

    show();
}

//=====================================================

void blinkFace()
{
    clear();

    u8g2.drawBox(20,32,30,3);
    u8g2.drawBox(78,32,30,3);

    show();
}