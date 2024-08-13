/*
 * (C) Copyright 2024 Elysia. All Rights Reserved.
 * Description: usart.c
 * Author: Elysia
 * Date: 2024-08-13
 * Modify Record:
 */

#include "usart.h"

#include <stdint.h>
#include <stdio.h>

#include "gd32f4xx.h"

void elysia_usart_init(void) {
  // 使能时钟
  rcu_periph_clock_enable(BSP_USART_RCU);     // 开启串口时钟
  rcu_periph_clock_enable(BSP_USART_TX_RCU);  // 开启端口时钟
  rcu_periph_clock_enable(BSP_USART_RX_RCU);  // 开启端口时钟

  /* 配置复用功能 */
  gpio_af_set(BSP_USART_TX_PORT, BSP_USART_AF, BSP_USART_TX_PIN);
  gpio_af_set(BSP_USART_RX_PORT, BSP_USART_AF, BSP_USART_RX_PIN);

  /* 配置TX为复用模式 上拉模式 */
  gpio_mode_set(BSP_USART_TX_PORT, GPIO_MODE_AF, GPIO_PUPD_PULLUP,
                BSP_USART_TX_PIN);
  /* 配置RX为复用模式 上拉模式 */
  gpio_mode_set(BSP_USART_RX_PORT, GPIO_MODE_AF, GPIO_PUPD_PULLUP,
                BSP_USART_RX_PIN);

  /* 配置TX为推挽输出 50MHZ */
  gpio_output_options_set(BSP_USART_TX_PORT, GPIO_OTYPE_PP, GPIO_OSPEED_50MHZ,
                          BSP_USART_TX_PIN);
  /* 配置RX为推挽输出 50MHZ */
  gpio_output_options_set(BSP_USART_RX_PORT, GPIO_OTYPE_PP, GPIO_OSPEED_50MHZ,
                          BSP_USART_RX_PIN);

  // 配置串口的工作参数
  /* 串口配置*/
  usart_deinit(BSP_USART);                          // 复位串口
  usart_baudrate_set(BSP_USART, 115200U);           // 设置波特率
  usart_parity_config(BSP_USART, USART_PM_NONE);    // 没有校验位
  usart_word_length_set(BSP_USART, USART_WL_8BIT);  // 8位数据位
  usart_stop_bit_set(BSP_USART, USART_STB_1BIT);    // 1位停止位
  usart_receive_config(BSP_USART, USART_RECEIVE_ENABLE); // 使能串口接收
  usart_transmit_config(BSP_USART, USART_TRANSMIT_ENABLE);  // 使能串口发送
  usart_enable(BSP_USART);                                     // 使能串口

  // 使能USART中断
  nvic_irq_enable(USART0_IRQn, 0, 0);
  // 使能串口接收中断
  usart_interrupt_enable(USART0, USART_INT_RBNE);
}

void ELYSIA_UART_Transmit(uint32_t uart, uint8_t *pData, uint32_t dataSize) {
  uint32_t i;
  uint32_t dataLen = dataSize / sizeof(uint8_t);
  for (i = 0; i < dataLen; ++i) {
    usart_data_transmit(uart, pData[i]);
    while (RESET == usart_flag_get(uart, USART_FLAG_TBE))
      ;  // 发送完成判断
  }
}

/**
 * @brief 重定向c库函数printf到USARTx
 * @retval None
 */
int fputc(int ch, FILE *f) {
  usart_data_transmit(BSP_USART, (uint8_t)ch);
  while (RESET == usart_flag_get(BSP_USART, USART_FLAG_TBE))
    ;
  return ch;
}

/**
 * @brief 重定向c库函数getchar,scanf到USARTx
 * @retval None
 */
int fgetc(FILE *f) {
  uint8_t ch = 0;
  ch = usart_data_receive(BSP_USART);
  return ch;
}
