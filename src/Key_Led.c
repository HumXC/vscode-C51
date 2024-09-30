#include <8051.h>
#include "lib/utils.h"
#define KEY P3_0
#define LED P1_0
#define u8 unsigned char

void main(void)
{
    P1 = 0x00;
    u8 key_state = 0;
    while (1)
    {
        if (KEY)
        {
            key_state = 0;
            continue;
        }

        if (key_state)
        {
            continue;
        }
        delay(1000);
        if (!KEY)
        {
            key_state = 1;
        }
        if (key_state)
        {
            LED = !LED;
        }
    }
}
