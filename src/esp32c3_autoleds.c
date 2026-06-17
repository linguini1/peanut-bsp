/****************************************************************************
 * peanut-bsp/src/esp32c3_reset.c
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Licensed to the Apache Software Foundation (ASF) under one or more
 * contributor license agreements.  See the NOTICE file distributed with
 * this work for additional information regarding copyright ownership.  The
 * ASF licenses this file to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance with the
 * License.  You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.  See the
 * License for the specific language governing permissions and limitations
 * under the License.
 *
 ****************************************************************************/

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include <nuttx/config.h>
#include <nuttx/debug.h>

#include <assert.h>
#include <stdlib.h>

#include <arch/board/board.h>
#include <nuttx/arch.h>
#include <nuttx/board.h>

#include "espressif/esp_gpio.h"

/* LEDs
 *
 * A single start LED is available. There is also a buzzer available that can
 * optionally be configured as a panic indicator.
 *
 * The LEDs are used to encode OS-related events as follows:
 *
 *   ------------------- ----------------------- ------ ----------
 *   SYMBOL              Meaning                 LED    Buzzer
 *   ------------------- ----------------------- ------ ----------
 *   LED_STARTED         NuttX has been started  ON     OFF
 *   LED_PANIC           NuttX has been started  OFF    BEEP (1Hz)
 *
 * Thus is LED is statically on, NuttX has successfully  booted and is,
 * apparently, running normally.  If LED is flashing at approximately
 * 2Hz, then a fatal error has been detected and the system has halted.
 */

/****************************************************************************
 * Public Functions
 ****************************************************************************/

/****************************************************************************
 * Name: board_autoled_initialize
 ****************************************************************************/

void board_autoled_initialize(void)
{
  esp_configgpio(START_GPIO, OUTPUT);
  esp_gpiowrite(START_GPIO, true);

#ifdef CONFIG_PEANUT_BUZZER_PANIC
  esp_configgpio(BUZZER_GPIO, OUTPUT);
#endif
}

/****************************************************************************
 * Name: board_autoled_on
 ****************************************************************************/

void board_autoled_on(int led)
{
  switch (led)
    {
    case LED_STARTED:
      esp_gpiowrite(START_GPIO, true);
      break;
#ifdef CONFIG_PEANUT_BUZZER_PANIC
    case LED_PANIC:
      esp_gpiowrite(BUZZER_GPIO, true);
      break;
#endif
    default:
      break;
    }
}

/****************************************************************************
 * Name: board_autoled_off
 ****************************************************************************/

void board_autoled_off(int led)
{
  switch (led)
    {
    case LED_STARTED:
      esp_gpiowrite(START_GPIO, false);
      break;
#ifdef CONFIG_PEANUT_BUZZER_PANIC
    case LED_PANIC:
      esp_gpiowrite(BUZZER_GPIO, false);
      break;
#endif
    default:
      break;
    }
}
