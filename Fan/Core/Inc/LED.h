/*
 * LED.h
 *
 *  Created on: Sep 26, 2023
 *      Author: user
 */

#ifndef INC_LED_H_
#define INC_LED_H_

#include "stm32f4xx_hal.h"
typedef struct
{
  GPIO_TypeDef *GPIOx;
  uint16_t pin;
  uint8_t state;
}LED;

void LED_init(LED *led,GPIO_TypeDef *GPIOx,uint16_t pin);
void LED_turn_on(LED *led);
void LED_turn_off(LED *led);

#endif /* INC_LED_H_ */
