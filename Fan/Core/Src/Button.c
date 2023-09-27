/*
 * Button.c
 *
 *  Created on: Sep 26, 2023
 *      Author: user
 */
#include "Button.h"

void Button_init(Button *button,GPIO_TypeDef *GPIOx ,uint16_t pin)
{
  button->GPIOx =GPIOx;
  button->pin = pin;
  button->prevState = RELEASED;
}
uint8_t Button_getState(Button *button)
{
  uint8_t curState = HAL_GPIO_ReadPin(button->GPIOx, button->pin);
  if((curState == PUSHED) && (button->prevState==RELEASED))
      {
          HAL_Delay(50);
          button->prevState = PUSHED; //��ư�� �������·� ��ȯ
          return ACT_PUSH;
      }
  else if((curState!= PUSHED)&&(button->prevState==PUSHED)){
          HAL_Delay(50);
          button->prevState = RELEASED; //��ư�� �� ���·� ��ȯ
          return ACT_RELEASED; // ��ư�� ���������� ��ȯ
      }

  return NO_ACT;
}

