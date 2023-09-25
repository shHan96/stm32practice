/*
 * stepper.h
 *
 *  Created on: Sep 21, 2023
 *      Author: user
 */

#ifndef INC_STEPPER_H_
#define INC_STEPPER_H_

#include "tim.h"
#include "main.h"

#define MOTOR_COUNT 2
#define MOTOR_OFF 0
#define MOTOR_ON 1
#define stepMotorHalfStep 4096
#define stepMotorfullStep 2048
#define WAVE_DRIVE 0
#define FULL_DRIVE 1
#define HALF_DRIVE 2
enum {
  ccw,
  cw
};
typedef struct
{

}Step_Info;

typedef struct
{
  GPIO_TypeDef *GPIOx[4];
  uint16_t GPIO_Pin[4];
  uint16_t motor_step;
  uint8_t steppingMode;
  uint8_t direction;
  uint8_t motor_state;
  uint8_t step;
}StepMotor;



void stepMotorSpeed(uint8_t step_number,int speed);
void stepMotorDrive(uint8_t step_number);
//void stepRun(uint8_t step_number);

#endif /* INC_STEPPER_H_ */

