/*
 * (C) Copyright 2024 Elysia. All Rights Reserved.
 * Description: systick.c
 * Author: Elysia
 * Date: 2024-08-13
 * Modify Record:
 */

#include "systick.h"

#include "gd32f4xx.h"

volatile static uint32_t uwTick = 0;

void ELYSIA_Delay(uint32_t Delay)
{
    uint32_t tickstart = uwTick;
    uint32_t wait = Delay;

    /* Add a freq to guarantee minimum wait */
    if (wait < ELYSIA_MAX_DELAY)
    {
        wait += (uint16_t)ELYSIA_TICK_PERIOD;
    }

    while ((uwTick - tickstart) < wait)
    {
    }
}

void systick_increment(void)
{
    uwTick++;
}

void systick_config(void)
{
    /* setup systick timer for 1000Hz interrupts */
    if (SysTick_Config(SystemCoreClock / ELYSIA_TICK_FREQ))
    {
        /* capture error */
        while (1)
        {
        }
    }
    /* configure the systick handler priority */
    NVIC_SetPriority(SysTick_IRQn, 0x00U);
}
