#include "gd32f4xx.h"
#include "systick.h"

int main(void) {
  systick_config();

  rcu_periph_clock_enable(RCU_GPIOB);

  gpio_mode_set(GPIOB, GPIO_MODE_OUTPUT, GPIO_PUPD_PULLUP, GPIO_PIN_2);
  gpio_output_options_set(GPIOB, GPIO_OTYPE_PP, GPIO_OSPEED_50MHZ, GPIO_PIN_2);

  gpio_bit_reset(GPIOB, GPIO_PIN_2);

  while (1) {
    gpio_bit_set(GPIOB, GPIO_PIN_2);
    ELYSIA_Delay(1000);

    gpio_bit_reset(GPIOB, GPIO_PIN_2);
    ELYSIA_Delay(1000);
  }
}
