#include"head.h"

int main(void)
{
	delay_init();
	uart_init(9600);
	LED_Init();
	LCD_Init();
	WKUP_Init(); //������׼��
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2); //�����жϷ���
	
	lcdwrite(30,50,"George",RED);
	lcdwrite(30,70,"2017222021",GREEN);
	lcdwrite(30,90,"BME01",BLUE);
	
	while(1)
	{
		LED0=!LED0;
		delay_ms(1000);
	}
}

