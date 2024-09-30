#include <8051.h>
#include "lib/utils.h"
#define LED P1

void main(void)
{
    P0 = 0x00;
    char index = 0;

    while (1)
    {
        if (index > 7)
        {
            index = 0;
        }
        LED = 0;
        LED = (1 << index);
        delay(1000);
        index++;
    }
}
