#include"head.h"

//�Ķ���Time1��CH1��CH2��������PWM���壬�ֱ����LED0��CH1����LED1�����ȣ�CH2��

int main(void)
{
	u16 led0pwmval=0, led1pwmval=300;
	u8 dir=1;
	
	delay_init();
	LED_Init();
	
	TIM1_PWM_Init_1_2(899,0);	//����Ƶ��PWM Ƶ��=72000/(899+1)=80Khz 
	
	while(1)
	{
		//ʵ���𵴡�����0����300�ٻص�0���������
		delay_ms(10);
		if(dir==1)
		{
			led0pwmval++;led1pwmval--;
		}else{
			led0pwmval--;led1pwmval++;
		}
	    
		if(led0pwmval==300 && led1pwmval==0)
		{
			dir=0;
		}else if(led0pwmval==0 && led1pwmval==300)
		{
			dir=1;
		}
	    
		TIM_SetCompare1(TIM1,led0pwmval);
		TIM_SetCompare2(TIM1,led1pwmval);
	}
}