#ifndef __EXTI_H
#define __EXIT_H	 

#include "sys.h"
#include "delay.h"
#include "usart.h" 	  
#include "led.h"
#include "key.h"		    
	 
void EXTIX_Init(void);//IO≥ı ºªØ

void EXTI0_IRQHandler(void);
void EXTI9_5_IRQHandler(void);
void EXTI15_10_IRQHandler(void);
		 					    
#endif

