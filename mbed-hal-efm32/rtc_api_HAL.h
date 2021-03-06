/***************************************************************************//**
 * @file rtc_api_HAL.h
 *******************************************************************************
 * @section License
 * <b>(C) Copyright 2015 Silicon Labs, http://www.silabs.com</b>
 *******************************************************************************
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Licensed under the Apache License, Version 2.0 (the "License"); you may
 * not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 ******************************************************************************/

#ifndef MBED_RTC_API_HAL_H
#define MBED_RTC_API_HAL_H

#include <stdint.h>
#include "mbed-hal/rtc_api.h"

#ifdef RTCC_COUNT
#include "em_rtcc.h"
#elif defined(RTC_COUNT)
#include "em_rtc.h"
#endif

#define RTC_CLOCKDIV 		cmuClkDiv_8
#define RTC_CLOCKDIV_INT	8
#define RTC_FREQ_SHIFT 		12


#define RTC_INIT_LPTIMER (1 << 1)
#define RTC_INIT_RTC     (1 << 0)

#ifdef __cplusplus
extern "C" {
#endif

/* Purpose of this file: extend rtc_api.h to include EFM-specific stuff*/
void rtc_set_comp0_handler(uint32_t handler);

void rtc_init_real(uint32_t flags);
void rtc_free_real(uint32_t flags);

uint32_t rtc_get_32bit(void);
uint64_t rtc_get_full(void);
uint32_t rtc_get_overflows(void);

#ifdef __cplusplus
}
#endif

#endif
