#ifndef UART_H
#define UART_H

#define FOSC 11059200L // 晶振频率 11.0592 MHz
#define BAUD 9600      // 波特率
void UART_Init(void);
void UART_SendChar(char c);
char UART_ReceiveChar(void);
void UART_SendString(char *str);
void UART_SendCRLF(void);
void UART_SendLF(void);

#endif