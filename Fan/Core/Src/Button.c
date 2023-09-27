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
          button->prevState = PUSHED; //버튼을 누른상태로 변환
          return ACT_PUSH;
      }
  else if((curState!= PUSHED)&&(button->prevState==PUSHED)){
          HAL_Delay(50);
          button->prevState = RELEASED; //버튼을 뗀 상태로 변환
          return ACT_RELEASED; // 버튼이 떨어졌음을 반환
      }

  return NO_ACT;
}

