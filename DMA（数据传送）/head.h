#ifndef __HEAD_H
#define __HEAD_H

#include"sys.h"
#include"delay.h"
#include"usart.h"
#include"dma.h"
#include"key.h"
#include"lcd.h"
#include"led.h"

void init();

void lcdwrite(u16 x,u16 y,u8 *p,u16 color);

#endif



