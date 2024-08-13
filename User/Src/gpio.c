/*
 * (C) Copyright 2024 Elysia. All Rights Reserved.
 * Description: gpio.c   
 * Author: Elysia
 * Date: 2024-08-13
 * Modify Record:
 */

#include "gpio.h"

#include "gd32f4xx.h"

void elysia_gpio_init(void) {
  rcu_periph_clock_enable(RCU_GPIOB);

  gpio_mode_set(GPIOB, GPIO_MODE_OUTPUT, GPIO_PUPD_PULLUP, GPIO_PIN_2);
  gpio_output_options_set(GPIOB, GPIO_OTYPE_PP, GPIO_OSPEED_50MHZ, GPIO_PIN_2);
  gpio_bit_reset(GPIOB, GPIO_PIN_2);
}
