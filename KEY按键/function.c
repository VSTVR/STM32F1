#include"head.h"

void led_operator1()
{
	u8 t;
	delay_init();
	KEY_Init();
	LED_Init();
	
	LED0=1;
	LED1=1;
	while(1)
	{
		t=KEY_Scan(0);
		switch(t)
		{
			case KEY0_PRES:
				LED0=!LED0;
			    break;
			case KEY1_PRES:
				LED1=!LED1;
			    break;
			case WKUP_PRES:
				LED0=!LED0;
			    LED1=!LED1;
				break;
			default:
				delay_ms(10);
		}
			
	}
}