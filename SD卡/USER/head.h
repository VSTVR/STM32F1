#ifndef __HEAD_H
#define __HEAD_H

#include "led.h"
#include "delay.h"
#include "sys.h"
#include "usart.h"
#include "lcd.h"
#include "key.h"

#include "malloc.h"  
#include "MMC_SD.h"   

//主体函数区
void Init();
void title();
void checksd(u32*sd_size);
//辅助函数区
void SD_Read_Sectorx(u32 sec);

#endif

