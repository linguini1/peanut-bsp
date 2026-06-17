/****************************************************************************
 * peanut-bsp/include/board.h
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

#ifndef __BOARDS_PEANUT_INCLUDE_BOARD_H
#define __BOARDS_PEANUT_INCLUDE_BOARD_H

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/

/* The GPIO pin controlling the arming buzzer. */

#define BUZZER_GPIO 20

/* The GPIO for the barometer interrupt */

#define BARO_INT_GPIO 0

/* Pyro channel fire pins */

#define PYRO1_FIRE_GPIO 10
#define PYRO2_FIRE_GPIO 5

/* Start LED pin */

#define START_GPIO 21

/* ADC information:
 *
 * ADC1 Channel 2: Battery monitor
 * ADC1 Channel 3: Pyro 1 continuity
 * ADC1 Channel 4: Pyro 2 continuity
 */

/* GPIO pins used by the GPIO Subsystem */

#define BOARD_NGPIOOUT 3 /* Amount of GPIO Output pins */

/* Board autoled definitions */

#define LED_STARTED       (1 << 0)
#define LED_HEAPALLOCATE  (1 << 1)
#define LED_IRQSENABLED   (1 << 2)
#define LED_STACKCREATED  (1 << 3)
#define LED_INIRQ         (1 << 4)
#define LED_SIGNAL        (1 << 5)
#define LED_ASSERTION     (1 << 6)
#define LED_PANIC         (1 << 7)

#endif /* __BOARDS_PEANUT_INCLUDE_BOARD_H */
