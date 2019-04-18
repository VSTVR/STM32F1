#include"head.h"

int main(void)
{
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	
	delay_init(); 
	uart_init(9600);
	LED_Init(); 
	
	LED0=0;
	delay_ms(300); 
	WWDG_Init(0X7F,0X5F,WWDG_Prescaler_8); 
	while(1)
	{
		LED0=1; 
	}
}