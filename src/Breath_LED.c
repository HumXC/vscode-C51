#include <8051.h>
#include "lib/utils.h"
#define LED P1_0
void Timer0_Init(void)
{
    TMOD = 0x02; // 8位自动重装模式
    // 100 um
    TH0 = 0xFF; // 设置高电平初值
    TL0 = 0x9C; // 设置低电平初值
    ET0 = 1;    // 使能Timer 0中断
    EA = 1;     // 使能全局中断
    TR0 = 1;    // 启动Timer 0
}

unsigned char DutyCycle = 50;
void Timer0_ISR(void) __interrupt(1)
{
    // 0xFF; 0x9C 是 100um 计时，产生 100Hz PWM 每个周期需要 100 个此调用
    static unsigned char max = 100;
    static unsigned char count = 0;
    static unsigned char forward = 1;
    if (count * 100 <= max * DutyCycle)
    {
        LED = 1;
    }
    else
    {
        LED = 0;
    }
    count++;
    if (count >= max)
    {
        count = 0;
        if (DutyCycle >= 100)
        {
            forward = -1;
        }
        if (DutyCycle <= 0)
        {
            forward = 1;
        }
        DutyCycle += forward;
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
