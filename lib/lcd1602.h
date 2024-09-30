
#ifndef LCD1602_H
#define LCD1602_H
void LCD_Command(unsigned char cmd);
void LCD_Char(unsigned char data);
void LCD_Init(void);
void LCD_String(char *str);
void LCD_Clean(void);
void LCD_Cursor(unsigned char line, unsigned char column);
void LCD_SetString(char *line1, char *line2);
#endif