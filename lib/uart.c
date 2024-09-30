#include <8051.h>
#define FOSC 11059200L // 晶振频率 11.0592 MHz
#define BAUD 9600      // 波特率
void UART_Init(void)
{
    TMOD = 0x20;                         // 定时器1模式2 (8位自动重载)
    TH1 = 256 - (FOSC / 12 / 32 / BAUD); // 设置波特率重载值
    TL1 = TH1;
    TR1 = 1;     // 启动定时器1
    SCON = 0x50; // 串口模式1，8位数据，允许接收
    TI = 0;      // 设置发送标志位，准备发送
}

void UART_SendChar(char c)
{
    SBUF = c; // 将字符发送到 SBUF 寄存器
    while (!TI)
    {
    }; // 等待发送完成
    TI = 0; // 清除发送标志位
}

char UART_ReceiveChar(void)
{
    while (!RI)
        ;        // 等待数据接收完成
    RI = 0;      // 清除接收标志位
    return SBUF; // 返回接收到的字符
}

void UART_SendString(char *str)
{
    while (*str)
    {
        UART_SendChar(*str++);
    }
}
void UART_SendCRLF(void)
{
    UART_SendString("\r\n");
}
void UART_SendLF(void)
{
    UART_SendChar('\n');
}