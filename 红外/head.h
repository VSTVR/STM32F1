#ifndef __HEAD_H
#define __HEAD_H

#include "sys.h"
#include "delay.h"
#include "usart.h"

#include "led.h"
#include "lcd.h"
#include "remote.h"
//主体函数区
void Init();
void display();
void signal_get();
//辅助函数区
void lcdwrite(u16 x,u16 y,u8 *p,u16 color);

#endif

