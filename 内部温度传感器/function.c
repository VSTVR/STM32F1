#include"head.h"

void lcdwrite(u16 x,u16 y,u8 *p,u16 color)
{
	POINT_COLOR=color;
	LCD_ShowString(x,y,200,16,16,p);
}

void showtemperature()
{
	u16 adc_x; float temp; float temperature;
	
	LCD_Clear(BLACK);
	lcdwrite(60,170,"Temperature: 00.00 C",RED);
	
	while(1)
	{
		adc_x=T_Get_Adc_Average(ADC_CH_TEMP,10); //注意口的名字
		temp=(float)adc_x*(3.3/4096);            //计算电压的公式
		temperature=(1.43-temp)/0.0043+25;       //计算温度
		
		LCD_ShowxNum(164,170,(u8)temperature,2,16,0);
		temperature=temperature-(u8)temperature;
		LCD_ShowxNum(188,170,temperature*100,2,16,0X80);
		
		LED0=!LED0;
		delay_ms(250);
		
	}
}
