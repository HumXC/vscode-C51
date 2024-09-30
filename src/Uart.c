#include <8051.h>
#include "lib/uart.h"
#include "lib/utils.h"

void main()
{
    UART_Init();
    UART_SendChar('A');
    UART_SendLF();
    char buffer[30];
    UART_SendChar('B');
    UART_SendLF();

    IntToString(FOSC, buffer);

    UART_SendChar('C');
    UART_SendLF();

    UART_SendString(buffer);
    UART_SendLF();
    UART_SendString(buffer);
    UART_SendLF();
    while (1)
    {
    }
}