#include <8051.h>
#include "lib/lcd1602.h"
#include "lib/utils.h"
void main(void)
{
    LCD_Init();
    LCD_SetString("Hello, World!", "I am C51.");
    while (1)
    {
    }
}