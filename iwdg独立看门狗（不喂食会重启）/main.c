#include"head.h"

int main(void)
{
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	delay_init();
	uart_init(9600);
	LED_Init();
	KEY_Init();
	delay_ms(3000);
	
	IWDG_Init(4,625); //��������֮�󶼰������ڣ�����Ҫ����ʹ��
	LED0=0;
	while(1)
	{
		if(KEY_Scan(0)==WKUP_PRES)
		{
			IWDG_Feed();
			printf("����nice,ζ����������");
			delay_ms(10);
		}
	}
}