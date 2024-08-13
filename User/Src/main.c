#include "main.h"

#include "gd32f4xx.h"
#include "systick.h"
#include "usart.h"
#include "gpio.h"

#include "stdio.h"

int main(void) {
  systick_config();
  elysia_gpio_init();
  elysia_usart_init();

  while (true) {
    ELYSIA_UART_Transmit(USART0, "Hello world!\n", sizeof("Hello world!\n"));
    ELYSIA_Delay(10);
  }
}
