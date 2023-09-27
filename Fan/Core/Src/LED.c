/*
 * LED.c
 *
 *  Created on: Sep 26, 2023
 *      Author: user
 */
#include "LED.h"

void LED_init(LED *led,GPIO_TypeDef *GPIOx,uint16_t pin)
{
  led->GPIOx = GPIOx;
  led->pin = pin;
  led->state = RESET;
}
void LED_turn_on(LED *led)
{
  HAL_GPIO_WritePin(led->GPIOx, led->pin, SET);
}
void LED_turn_off(LED *led)
{
  HAL_GPIO_WritePin(led->GPIOx, led->pin, RESET);
}

