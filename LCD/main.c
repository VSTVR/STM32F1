#include"head.h"
#include"led.h"
#include"lcd.h"
//ע�⣡������ļ��ŵ�����2��3�еĶ��岻��д��ͷ�ļ����Ҫ�Ҷ�lcd.h��lcd.c �ļ���궨���λ�ã���Ȼ�ᱨ��

int main(void)
{
	u8 x=0;u8 lcd_id[12];
	delay_init();
	uart_init(9600);
	LED_Init();
	LCD_Init();
	
	POINT_COLOR=RED;								 //������ɫΪ��
	sprintf((char*)lcd_id,"LCD ID:%04X",lcddev.id); //lcddevȡLCD��id����ӡ�������������ʾ��,""�е���д�������
	
	while(1)
	{
		switch(x)
		{
			case 0:LCD_Clear(WHITE);break;   //��һ�Ű�ɫ����
			case 1:LCD_Clear(BLACK);break;
			case 2:LCD_Clear(BLUE);break;
			case 3:LCD_Clear(RED);break;
			case 4:LCD_Clear(MAGENTA);break;
			case 5:LCD_Clear(GREEN);break;
			case 6:LCD_Clear(CYAN);break;
			case 7:LCD_Clear(YELLOW);break;
			case 8:LCD_Clear(BRRED);break;
			case 9:LCD_Clear(GRAY);break;
			case 10:LCD_Clear(LGRAY);break;
			case 11:LCD_Clear(BROWN);break;
		}
		
		POINT_COLOR=RED;
		LCD_ShowString(30,40,200,24,24,"Mini STM32F103RC");  //������꣬�����С�������С
		LCD_ShowString(30,70,200,16,16,"George 2017222021"); //������ʾ���ģ�������Ҫ���ֿ����sd�������
		LCD_ShowString(30,90,200,16,16,"BME01");
		LCD_ShowString(30,110,200,16,16,lcd_id);    		//���ַ�ʽû�о���
		LCD_ShowString(30,130,200,12,12,"2018/12/4");  
		
		x++;  			//ʹ֮���ϸı�
		if(x==12)x=0;   //
		LED0=!LED0;
		delay_ms(1000);

	}


}