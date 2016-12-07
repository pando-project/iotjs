/* Copyright 2016 Samsung Electronics Co., Ltd.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#if defined(__NUTTX__) && TARGET_BOARD == STM32F4DIS


#include "stm32_gpio.h"


void iotjs_gpio_unconfig_nuttx(int pin) {
  stm32_unconfiggpio(pin);
}


#if ENABLE_MODULE_ADC

#include "stm32_adc.h"

struct adc_dev_s* iotjs_adc_config_nuttx(int number, int timer, int pin) {
  stm32_configgpio(pin);

  uint8_t channel_list[1] = { timer };
  return stm32_adcinitialize(number, channel_list, 1);
}

#endif /* ENABLE_MODULE_ADC */


#if ENABLE_MODULE_PWM

#include "stm32_pwm.h"

struct pwm_lowerhalf_s* iotjs_pwm_config_nuttx(int timer, int pin) {
  // Set alternative function
  stm32_configgpio(pin);

  // PWM initialize
  return stm32_pwminitialize(timer);
}

#endif /* ENABLE_MODULE_PWM */


#endif // __NUTTX__
