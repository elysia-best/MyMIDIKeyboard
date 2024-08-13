/*
 * (C) Copyright 2024 Elysia. All Rights Reserved.
 * Description: systick.h -- the systick configuration file
 * Author: Elysia
 * Date: 2024-08-13
 * Modify Record:
 */

#ifndef __SYSTICK_H_
#define __SYSTICK_H_

#include <stdint.h>

#define ELYSIA_MAX_DELAY 0xFFFFFFFF

#define ELYSIA_TICK_FREQ 1000U // 使用1000Hz Systick

#define ELYSIA_TICK_PERIOD ((uint32_t)(1.0f/(float)ELYSIA_TICK_FREQ))

/**
  * @Name    ELYSIA_Delay
  * @brief   阻塞延时
  * @param   Delay: 延时，ms
  * @retval
  * 1. ...
  * <modify staff>:
  * <data>        :
  * <description> :
  * 2. ...
  **/
void ELYSIA_Delay(uint32_t Delay);

/**
  * @Name    systick_increment
  * @brief   increase one per tick.
  * @param   None
  * @retval
  * 1. ...
  * <modify staff>:
  * <data>        :
  * <description> :
  * 2. ...
  **/
void systick_increment(void);

/**
  * @Name    systick_config
  * @brief   Configuring system clock.
  * @param   : None
  * @retval  : None
  * 1. ...
  * <modify staff>:
  * <data>        :
  * <description> :
  * 2. ...
  **/
void systick_config(void);

#endif


