#include"head.h"

int main(void)
{
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2); 
	delay_init();
	uart_init(9600);
	EXTIX_Init();
	LED_Init();
	
	LED0=0;
	while(1)
	{
		printf("OK\n");
		delay_ms(1000);
	}
}