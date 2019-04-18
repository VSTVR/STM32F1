#ifndef __HEAD_H
#define __HEAD_H

#include "sys.h"
#include "delay.h"
#include "usart.h"

#include "key.h"
#include "led.h"
#include "lcd.h"
#include "24cxx.h"
#include "myiic.h"

#include "ctiic.h"
#include "touch.h"
#include "ft5206.h"
#include "gt9147.h"
#include "ott2001a.h"

//主体函数区
void Init();
void rtp_test();
void ctp_test();
//辅助函数区
void lcdwrite(u16 x,u16 y,u8 *p,u16 color);

#endif

