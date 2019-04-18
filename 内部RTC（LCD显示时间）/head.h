#ifndef __HEAD_H
#define __HEAD_H

#include"sys.h"
#include"delay.h"
#include"usart.h"
#include"led.h"
#include"lcd.h"
#include"rtc.h"
#include"usmart.h"

void lcdwrite(u16 x,u16 y,u8 *p,u16 color);
void showtime(u8 t);

#endif