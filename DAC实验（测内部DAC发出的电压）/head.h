#ifndef __HEAD_H
#define __HEAD_H

#include"sys.h"
#include"delay.h"
#include"usart.h"
#include"led.h"
#include"lcd.h"
#include"adc.h"
#include"dac.h"
#include"key.h"

void init();
void showvoltage();

void lcdwrite(u16 x,u16 y,u8 *p,u16 color);


#endif

