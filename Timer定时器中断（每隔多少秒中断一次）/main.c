#include"head.h"

int main(void)
{
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	
	delay_init();
	uart_init(9600);
	LED_Init();
	
	TIM3_Int_Init(4999,7199);    //�����Ĳ���ToutԼΪ1�룬ÿһ���ж�һ�Σ�LED1��˸һ��
	
	while(1)
	{
		LED0=!LED0;
		delay_ms(200);
	}
}