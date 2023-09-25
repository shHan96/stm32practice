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

#define stepMotorHalfStep 4096
#define stepMotorfullStep 2048

enum {
  ccw,
  cw
};

void stepMotorSpeed(int speed);
void stepMotorHalfDrive(int step);

#endif /* INC_STEPPER_H_ */
