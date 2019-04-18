#include"head.h"

int main(void)
{
	//1
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	Init();
	//1
	
	lcdwrite(50,50,"触摸屏实验",RED);
	
	//2
	if(tp_dev.touchtype!=0XFF)//不准，你有1.5秒的时间去选择是否矫正
	{
		lcdwrite(50,70,"请按下key0以校准！",BLUE);
	}
	delay_ms(1500);
	//2
	
	//3
	
	LCD_Clear(WHITE);//Load_Drow_Dialog();清屏,原代码不行
	if(tp_dev.touchtype&0X80)
	{
		ctp_test();//电容屏
	}else{
		rtp_test();//电阻屏
	}
	//3
}

