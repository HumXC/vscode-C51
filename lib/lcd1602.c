#include <8051.h>
#include "lib/utils.h"
#define LCD_DATA P0
#define RW P2_5
#define RS P2_6
#define EN P2_7
void commit(void)
{
    EN = 1;
    Delay(1);
    EN = 0;
    Delay(1);
}
void LCD_Command(unsigned char cmd)
{
    RS = 0;         // 选择指令寄存器
    RW = 0;         // 写模式
    LCD_DATA = cmd; // 写入命令
    commit();
}
void LCD_Cursor(unsigned char line, unsigned char column)
{
    if (line == 1)
    {
        LCD_Command(0x80 | (column - 1));
    }
    else if (line == 2)
    {
        LCD_Command(0x80 | (column - 1 + 0x40));
    }
}
void LCD_Char(unsigned char data)
{
    RS = 1;          // 选择数据寄存器
    RW = 0;          // 写模式
    LCD_DATA = data; // 写入数据
    commit();
}
void LCD_Clean(void)
{
    LCD_Command(0x01); // 清屏
}
void LCD_Init(void)
{
    Delay(10);         // 等待 LCD 启动
    LCD_Command(0x38); // 8位数据，2行显示
    LCD_Command(0x0C); // 显示开，光标关
    LCD_Command(0x06); // 写入后光标右移
    LCD_Clean();
}

void LCD_String(char *str)
{
    while (*str)
    {
        LCD_Char(*str++);
    }
}
void LCD_SetString(char *line1, char *line2)
{
    LCD_Clean();
    LCD_Cursor(1, 0);
    LCD_String(line1);
    LCD_Cursor(2, 0);
    LCD_String(line2);
    LCD_Cursor(1, 0);
}