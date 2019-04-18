#ifndef __CAPPWM_H
#define __CAPPWM_H

#include "sys.h"
#include "led.h"
#include "usart.h"
#include "sys.h"
 
 
void TIM1_PWM_Init(u16 arr,u16 psc);
void TIM2_Cap_Init(u16 arr,u16 psc);

#endif
