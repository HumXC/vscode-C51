#include <8051.h>
#include "lib/lcd1602.h"
#include "lib/utils.h"
#include "lib/servo.h"
#define Servo P1_0

void main()
{
    Servo_Init(Servo);
    while (1)
    {
        Servo_Write(90); // 控制舵机到90度
    }
}