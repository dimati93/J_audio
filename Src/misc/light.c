#include "stm32l1xx.h"
#include "stm32l1xx_gpio.h"

void IntitializeLight(void)
{
    RCC_AHBPeriphClockCmd(RCC_AHBENR_GPIOAEN, ENABLE);
    GPIO_InitTypeDef GPIOA_Init;

    GPIOA_Init.GPIO_Mode = GPIO_Mode_OUT;
    GPIOA_Init.GPIO_Pin = GPIO_Pin_5;
    GPIOA_Init.GPIO_Speed = GPIO_Speed_40MHz;
    GPIOA_Init.GPIO_PuPd = GPIO_PuPd_NOPULL;

    GPIO_Init(GPIOA, &GPIOA_Init);
}

void SetLight(void)
{
    GPIOA->ODR |= GPIO_Pin_5;
}

void ResetLight(void)
{
    GPIOA->ODR &= ~GPIO_Pin_5;
}
