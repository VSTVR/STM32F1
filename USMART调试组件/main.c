#include "head.h"

int main(void)
{
	delay_init();
	uart_init(9600);
	LED_Init();
	LCD_Init();
	usmart_dev.init(72);  //≥ı ºªØUSMART
	
	LCD_Clear(GREEN);
	POINT_COLOR=RED;
	LCD_ShowString(30,50,200,16,16,"George");
	LCD_ShowString(30,80,200,16,16,"2017222021");
	LCD_ShowString(30,110,200,16,16,"BME01");
	LCD_ShowString(30,140,200,16,16,"2018/12/5");
	
	while(1)
	{
		LED0=!LED0;
		delay_ms(500);
	}
}

