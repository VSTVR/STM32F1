#ifndef __PWM_H
#define __PWM_H

#include "sys.h"
#include "led.h"


void TIM1_PWM_Init(u16 arr,u16 psc);

void TIM1_PWM_Init_1_2(u16 arr,u16 psc);

#endif
