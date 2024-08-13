/*
 * (C) Copyright 2024 Elysia. All Rights Reserved.
 * Description: usart.h   
 * Author: Elysia
 * Date: 2024-08-13
 * Modify Record:
 */

#ifndef __USART_H_
#define __USART_H_

#include <stdint.h>

#include "gd32f4xx.h"

#define BSP_USART    USART0

#define BSP_USART_RCU             RCU_USART0
#define BSP_USART_TX_RCU          RCU_GPIOA
#define BSP_USART_RX_RCU          RCU_GPIOA

#define BSP_USART_TX_PORT       GPIOA
#define BSP_USART_TX_PIN        GPIO_PIN_9
#define BSP_USART_RX_PORT       GPIOA
#define BSP_USART_RX_PIN        GPIO_PIN_10
#define BSP_USART_AF            GPIO_AF_7  // 串口是引脚复用功能7

void elysia_usart_init(void);

void ELYSIA_UART_Transmit(uint32_t uart, uint8_t *pData, uint32_t dataSize);

#endif


