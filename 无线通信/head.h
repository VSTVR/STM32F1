#ifndef __HEAD_H
#define __HEAD_H

#include "sys.h"
#include "delay.h"
#include "usart.h"

#include "key.h"
#include "led.h"
#include "lcd.h"
#include "spi.h"
#include "24l01.h" //是24L01！

//主体函数区
void Init();
void Check();
void Chosemode(u8*mode);
void Action(u8 mode);
//辅助函数区
void lcdwrite(u16 x,u16 y,u8 *p,u16 color);

#endif

