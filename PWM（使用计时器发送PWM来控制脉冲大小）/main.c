#include"head.h"

//改动：Time1的CH1和CH2发出两个PWM脉冲，分别控制LED0（CH1）和LED1的亮度（CH2）

int main(void)
{
	u16 led0pwmval=0, led1pwmval=300;
	u8 dir=1;
	
	delay_init();
	LED_Init();
	
	TIM1_PWM_Init_1_2(899,0);	//不分频。PWM 频率=72000/(899+1)=80Khz 
	
	while(1)
	{
		//实现震荡——从0增到300再回到0，如此往复
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