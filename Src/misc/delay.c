#include "system_stm32l1xx.h"

#define STM32_CYCLES_PER_LOOP 6 // This will need tweaking or calculating

void Delay(unsigned long ms)
{
    ms *= SystemCoreClock / 1000 / STM32_CYCLES_PER_LOOP;

    asm volatile(" mov r0, %[ms] \n\t"
                 "1: subs r0, #1 \n\t"
                 " bhi 1b \n\t"
                :
                : [ms] "r" (ms)
                : "r0");
}
