/*
 * Fan.c
 *
 *  Created on: Sep 26, 2023
 *      Author: user
 */

#include "Fan.h"

void FAN_init(FAN *fan,TIM_HandleTypeDef* htim,uint16_t channel)
{
  fan->htim = htim;
  fan->channel = channel;
  fan->state = POWER_OFF;
}
void stop(FAN* fan)
{
  __HAL_TIM_SET_COMPARE(fan->htim,fan->channel,STOP);
  fan->state = POWER_OFF;
}
void level1(FAN* fan)
{
  __HAL_TIM_SET_COMPARE(fan->htim,fan->channel,LEVEL1);
  fan->state = LEVEL_1;
}
void level2(FAN* fan)
{
  __HAL_TIM_SET_COMPARE(fan->htim,fan->channel,LEVEL2);
  fan->state = LEVEL_2;
}
void level3(FAN* fan)
{
  __HAL_TIM_SET_COMPARE(fan->htim,fan->channel,LEVEL3);
  fan->state = LEVEL_3;
}
void ROTATE_MOTOR_init(ROTATE_MOTOR *rotate_motor,TIM_HandleTypeDef* htim,uint16_t channel)
{
  rotate_motor->htim=htim;
  rotate_motor->channel=channel;
  rotate_motor->curStep = MIDDLE;
  rotate_motor->state = ROTATE_STOP;
  rotate_motor->direction = CW;
}
void rotate(FAN *fan,ROTATE_MOTOR *rotate_motor)
{
  if(fan->state!=STOP && rotate_motor->state==ROTATE)
  {
    if(rotate_motor->direction==CW)
    {
      rotate_motor->curStep++;
      if(rotate_motor->curStep>=LEFT_END)
      {
        rotate_motor->direction = CCW;
      }
    }
    else
    {
      rotate_motor->curStep--;
      if(rotate_motor->curStep<=RIGHT_END)
      {
        rotate_motor->direction = CW;
      }
    }
    __HAL_TIM_SET_COMPARE(rotate_motor->htim,rotate_motor->channel,rotate_motor->curStep);
    HAL_Delay(10);
  }
}
void rotate_on(ROTATE_MOTOR *rotate_motor)
{
  rotate_motor->state = ROTATE;
}
void rotate_off(ROTATE_MOTOR *rotate_motor)
{

  rotate_motor->state = ROTATE_STOP;

}

