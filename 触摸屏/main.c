#include"head.h"

int main(void)
{
	//1
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	Init();
	//1
	
	lcdwrite(50,50,"������ʵ��",RED);
	
	//2
	if(tp_dev.touchtype!=0XFF)//��׼������1.5���ʱ��ȥѡ���Ƿ����
	{
		lcdwrite(50,70,"�밴��key0��У׼��",BLUE);
	}
	delay_ms(1500);
	//2
	
	//3
	
	LCD_Clear(WHITE);//Load_Drow_Dialog();����,ԭ���벻��
	if(tp_dev.touchtype&0X80)
	{
		ctp_test();//������
	}else{
		rtp_test();//������
	}
	//3
}

