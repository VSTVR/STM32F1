#include"head.h"

int main(void)
{
	u8 t=0;
	delay_init();
	uart_init(9600);
	LED_Init();
	LCD_Init();
	usmart_dev.init(72);
	
	LCD_Clear(BLACK);
	
	lcdwrite(60,50,"George",RED);
	lcdwrite(60,70,"2017222021",YELLOW);
	lcdwrite(60,90,"BME01",GREEN);
	
	while(RTC_Init()==1)   //如果没有初始化成功
	{
		lcdwrite(60,130,"ERROR!!!!",RED);
		delay_ms(500);
		lcdwrite(60,130,"Tring......",RED);
	}
	
	showtime(t);
}

