#include <8051.h>
#include "lib/lcd1602.h"
#include "lib/utils.h"
#define SERVO P1_0
void Timer0_Init(void)
{
    TMOD = 0x02; // 8位自动重装模式
    // 100 um
    TH0 = 0xFF; // 设置高电平初值
    TL0 = 0xF6; // 设置低电平初值
    ET0 = 1;    // 使能Timer 0中断
    EA = 1;     // 使能全局中断
    TR0 = 1;    // 启动Timer 0
}

unsigned char DutyCycle = 90;
void Timer0_ISR(void) __interrupt(1)
{
    // 0xFF; 0x9C 是 100um 计时，产生 50Hz PWM 每个周期需要 200 个此调用
    static unsigned char max = 200;
    static unsigned char count = 0;
    if (count <= 10)
    {
        return;
    }
    if (count * 180 <= max * DutyCycle)
    {
        SERVO = 1;
    }
    else
    {
        SERVO = 0;
    }
    count++;
    if (count >= max)
    {
        count = 0;
    }
}

void main()
{
    Timer0_Init(); // 初始化Timer 0

    P1 = 0;

    while (1)
    {
    }
}

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

void ServoWrite(unsigned char angle)
{
    unsigned int pulseWidth;

    // 根据角度设置脉宽
    if (angle < 0)
        angle = 0;
    if (angle > 180)
        angle = 180;

    pulseWidth = low + (high - low) * (angle / 180.0); // 1ms + (0-180度线性映射到1-2ms)
    LCD_Clean();
    char buffer[10];
    IntToString(pulseWidth, buffer);
    LCD_String(buffer);
    Servo = 1;
    delay(pulseWidth);
    Servo = 0;
    delay(high / 2 * 20 - pulseWidth);
}

void main()
{
    LCD_Init();

    while (1)
    {
        ServoWrite(90); // 控制舵机到90度
    }
}