#include"head.h"



int main(void)
{
	delay_init();
	uart_init(9600);
	LED_Init();
	LCD_Init();
	T_Adc_Init();
	
	showtemperature();
}

