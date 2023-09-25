/*
 * stepper.c
 *
 *  Created on: Sep 21, 2023
 *      Author: user
 */


#include "stepper.h"
#include "delay.h"

uint8_t WD_PATTERN[4][4]=
    {
        {1,0,0,0},
        {0,1,0,0},
        {0,0,1,0},
        {0,0,0,1}
    };
uint8_t FD_PATTERN[4][4]=
    {
        {1,1,0,0},
        {0,1,1,0},
        {0,0,1,1},
        {1,0,0,1}
    };
uint8_t HD_PATTERN[8][4]=
    {
        {1,0,0,0},
        {1,1,0,0},
        {0,1,0,0},
        {0,1,1,0},
        {0,0,1,0},
        {0,0,1,1},
        {0,0,0,1},
        {1,0,0,1}
    };
StepMotor step_motor[MOTOR_COUNT]={
    {
        {GPIOA,GPIOA,GPIOA,GPIOB},
        {GPIO_PIN_5,GPIO_PIN_6,GPIO_PIN_7,GPIO_PIN_6},
        stepMotorfullStep,WAVE_DRIVE,cw,MOTOR_ON,0
    },
    {
            {GPIOC,GPIOA,GPIOA,GPIOB},
            {GPIO_PIN_7,GPIO_PIN_9,GPIO_PIN_8,GPIO_PIN_10},
            stepMotorfullStep,FULL_DRIVE,ccw,MOTOR_ON,0
     }
};


void stepMotorSpeed(uint8_t step_number,int speed)
{
  delay_us(60000000/step_motor[step_number].motor_step/speed);
}

void stepMotorDrive(uint8_t step_number)
{
  switch (step_motor[step_number].steppingMode) {
    case WAVE_DRIVE:
        HAL_GPIO_WritePin(step_motor[step_number].GPIOx[0], step_motor[step_number].GPIO_Pin[0], WD_PATTERN[step_motor[step_number].step][0]);
        HAL_GPIO_WritePin(step_motor[step_number].GPIOx[1], step_motor[step_number].GPIO_Pin[1], WD_PATTERN[step_motor[step_number].step][1]);
        HAL_GPIO_WritePin(step_motor[step_number].GPIOx[2], step_motor[step_number].GPIO_Pin[2], WD_PATTERN[step_motor[step_number].step][2]);
        HAL_GPIO_WritePin(step_motor[step_number].GPIOx[3], step_motor[step_number].GPIO_Pin[3], WD_PATTERN[step_motor[step_number].step][3]);
      break;
    case FULL_DRIVE:
        HAL_GPIO_WritePin(step_motor[step_number].GPIOx[0], step_motor[step_number].GPIO_Pin[0], FD_PATTERN[step_motor[step_number].step][0]);
        HAL_GPIO_WritePin(step_motor[step_number].GPIOx[1], step_motor[step_number].GPIO_Pin[1], FD_PATTERN[step_motor[step_number].step][1]);
        HAL_GPIO_WritePin(step_motor[step_number].GPIOx[2], step_motor[step_number].GPIO_Pin[2], FD_PATTERN[step_motor[step_number].step][2]);
        HAL_GPIO_WritePin(step_motor[step_number].GPIOx[3], step_motor[step_number].GPIO_Pin[3], FD_PATTERN[step_motor[step_number].step][3]);
        break;
    case HALF_DRIVE:
        HAL_GPIO_WritePin(step_motor[step_number].GPIOx[0], step_motor[step_number].GPIO_Pin[0], HD_PATTERN[step_motor[step_number].step][0]);
        HAL_GPIO_WritePin(step_motor[step_number].GPIOx[1], step_motor[step_number].GPIO_Pin[1], HD_PATTERN[step_motor[step_number].step][1]);
        HAL_GPIO_WritePin(step_motor[step_number].GPIOx[2], step_motor[step_number].GPIO_Pin[2], HD_PATTERN[step_motor[step_number].step][2]);
        HAL_GPIO_WritePin(step_motor[step_number].GPIOx[3], step_motor[step_number].GPIO_Pin[3], HD_PATTERN[step_motor[step_number].step][3]);
        break;
    default:
      break;
  }
  if(step_motor[step_number].motor_state==MOTOR_ON)
  {

    if(step_motor[step_number].direction==ccw)
    {
      switch (step_motor[step_number].steppingMode) {
          case WAVE_DRIVE:
            step_motor[step_number].step--;
            if(step_motor[step_number].step==255)
              step_motor[step_number].step=3;
            break;
          case FULL_DRIVE:
            step_motor[step_number].step--;
            if(step_motor[step_number].step==255)
              step_motor[step_number].step=3;
              break;
          case HALF_DRIVE:
            step_motor[step_number].step--;
            if(step_motor[step_number].step==255)
              step_motor[step_number].step=7;

              break;
          default:
            break;
        }


    }else if(step_motor[step_number].direction==cw)
    {
      switch (step_motor[step_number].steppingMode) {
              case WAVE_DRIVE:
                step_motor[step_number].step++;
                if(step_motor[step_number].step>3)
                  step_motor[step_number].step=0;
                break;
              case FULL_DRIVE:
                step_motor[step_number].step++;
                if(step_motor[step_number].step>3)
                  step_motor[step_number].step=0;
                  break;
              case HALF_DRIVE:
                step_motor[step_number].step++;
                if(step_motor[step_number].step>7)
                  step_motor[step_number].step=0;
                  break;
              default:
                break;
            }
    }
  }

}


