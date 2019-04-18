#include "head.h"

void lcdwrite(u16 x,u16 y,u8 *p,u16 color)
{
	POINT_COLOR=color;
	LCD_ShowString(x,y,200,16,16,p);
}