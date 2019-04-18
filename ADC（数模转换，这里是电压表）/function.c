#include"head.h"

void lcdwrite(u16 x,u16 y,u8 *p,u16 color)
{
	POINT_COLOR=color;
	LCD_ShowString(x,y,200,16,16,p);
}


void showvoltage(u16 adc_x,float temp)
{
	lcdwrite(60,130,"CH1_VAL: ",BLUE);
	lcdwrite(60,150,"CH1_VOL: 0.000V",BLUE);
	
	while(1)
	{
		adc_x=Get_Adc_Average(ADC_Channel_1,10); //ȡ��10��*5ms ��ms��ch1�˿�ֵ��ƽ��ֵ
		LCD_ShowxNum(132,130,adc_x,4,16,0);
		temp=(float)adc_x*(3.3/4096);//��ѹ�ļ��㹫ʽ
		adc_x=temp;//adc_xΪtemp����ѹֵ������������
		LCD_ShowxNum(132,150,adc_x,1,16,0);//��ʾ��ѹֵ��ȡ����λ1����
		temp-=adc_x; //С������
		temp*=1000;
		LCD_ShowxNum(148,150,temp,3,16,0X80);//��С�����֣�ȡ����λ3����
		LED0=!LED0;
		delay_ms(250);
	}
}
