#include "head.h"

void init()
{
	delay_init();
	uart_init(9600);
	LED_Init();
	LCD_Init();
	KEY_Init();
}




