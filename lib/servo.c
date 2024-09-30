#include <8051.h>
#include "lib/lcd1602.h"
#include "lib/utils.h"
#define Servo P1_0
void delay(unsigned int t)
{
    unsigned int i;
    for (i = 0; i < t; i++)
    {
        ;
    }
}
const unsigned char low = 44;
const unsigned char high = 230;

void Servo_Write(unsigned char angle)
{
    unsigned int pulseWidth;

    if (angle > 180)
        angle = 180;

    pulseWidth = low + (high - low) * (angle / 180.0);
    Servo = 1;
    delay(pulseWidth);
    Servo = 0;
    delay(high / 2 * 20 - pulseWidth);
}
void Servo_Init(__sbit pwm_output)
{
    // Servo = pwm_output;
}
