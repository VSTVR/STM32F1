#ifndef __HEAD_H
#define __HEAD_H

#include"sys.h"
#include"delay.h"
#include"usart.h"
#include"lcd.h"
#include"led.h"
#include"adc.h"


void lcdwrite(u16 x,u16 y,u8 *p,u16 color);
void showvoltage(u16 adc_x,float temp);

#endif

