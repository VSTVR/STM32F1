#include"head.h"


//ע�⣺������ѹ����С��3.3V ������
int main(void)
{
	u16 adc_x; float temp;
	delay_init();
	uart_init(9600);
	LED_Init();
	LCD_Init();
	Adc_Init();
	
	lcdwrite(60,50,"Voltage Indicator",RED);
	lcdwrite(60,70,"BY George 2017222021 BME01",RED);
	
	showvoltage(adc_x,temp);
}

