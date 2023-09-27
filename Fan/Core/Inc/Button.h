/*
 * Button.h
 *
 *  Created on: Sep 26, 2023
 *      Author: user
 */

#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_

#include "stm32f4xx_hal.h"

enum {PUSHED,RELEASED};
enum {NO_ACT, ACT_PUSH,ACT_RELEASED};

typedef struct _button{
    GPIO_TypeDef *GPIOx;
    uint16_t pin;
    uint8_t prevState;

}Button;
void Button_init(Button *button,GPIO_TypeDef* GPIOx ,uint16_t pin);
uint8_t Button_getState(Button *button);

#endif /* INC_BUTTON_H_ */
