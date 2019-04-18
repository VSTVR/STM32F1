#include"head.h"

int main(void)
{
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	
	delay_init();
	uart_init(9600);
	LED_Init();
	
	TIM3_Int_Init(4999,7199);    //这样的参数Tout约为1秒，每一秒中断一次，LED1闪烁一次
	
	while(1)
	{
		LED0=!LED0;
		delay_ms(200);
	}
}