#include"head.h"

int main(void)
{
	delay_init();
	uart_init(9600);
	LED_Init();
	LCD_Init();
	WKUP_Init(); //待机键准备
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2); //设置中断分组
	
	lcdwrite(30,50,"George",RED);
	lcdwrite(30,70,"2017222021",GREEN);
	lcdwrite(30,90,"BME01",BLUE);
	
	while(1)
	{
		LED0=!LED0;
		delay_ms(1000);
	}
}

