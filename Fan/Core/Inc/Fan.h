/*
 * Fan.h
 *
 *  Created on: Sep 26, 2023
 *      Author: user
 */

#ifndef INC_FAN_H_
#define INC_FAN_H_
#include "main.h"

#define STOP 0
#define LEVEL1 350
#define LEVEL2 500
#define LEVEL3 750

#define RIGHT_END   50
#define LEFT_END    250
#define MIDDLE  150

enum {POWER_OFF,LEVEL_1, LEVEL_2, LEVEL_3};
enum {ROTATE_STOP, ROTATE};
enum {CCW,CW};


typedef struct
{
  TIM_HandleTypeDef * htim;
  uint16_t channel;
  uint8_t state;
}FAN;

typedef struct
{
  TIM_HandleTypeDef * htim;
  uint16_t channel;
  uint16_t curStep;
  uint8_t state;
  uint8_t direction;
}ROTATE_MOTOR;

void FAN_init(FAN *fan,TIM_HandleTypeDef* htim,uint16_t channel);
void ROTATE_MOTOR_init(ROTATE_MOTOR *rotate_motor,TIM_HandleTypeDef* htim,uint16_t channel);
void stop(FAN* fan);
void level1(FAN* fan);
void level2(FAN* fan);
void level3(FAN* fan);
void rotate(FAN *fan,ROTATE_MOTOR *rotate_motor);
void rotate_on(ROTATE_MOTOR *rotate_motor);
void rotate_off(ROTATE_MOTOR *rotate_motor);


#endif /* INC_FAN_H_ */
