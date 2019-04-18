#include"head.h"

//��ʼ��
void Init()
{
	delay_init();	    	 //��ʱ������ʼ��	  
	uart_init(9600);	 	//���ڳ�ʼ��Ϊ9600
	LED_Init();		  		//��ʼ����LED���ӵ�Ӳ���ӿ�
	LCD_Init();			   	//��ʼ��LCD	
 	KEY_Init();				//������ʼ��  
 	mem_init();				//��ʼ���ڴ��
}

//������ʾ
void title()
{
	POINT_COLOR=RED;//��������Ϊ��ɫ 
	LCD_ShowString(60,50,200,16,16,"Mini STM32");	
	LCD_ShowString(60,70,200,16,16,"SD CARD TEST");	
	LCD_ShowString(60,90,200,16,16,"ATOM@ALIENTEK");
	LCD_ShowString(60,110,200,16,16,"2014/3/13");  
	LCD_ShowString(60,130,200,16,16,"KEY0:Read Sector 0");
}

//���SD��
void checksd(u32*sd_size)
{
	while(SD_Initialize())//��ⲻ��SD��(1)
	{
		LCD_ShowString(60,150,200,16,16,"SD Card Error!");
		delay_ms(500);					
		LCD_ShowString(60,150,200,16,16,"Please Check! ");
		delay_ms(500);
		LED0=!LED0;//DS0��˸
	}
	
	//���SD���ɹ�
 	POINT_COLOR=BLUE;//��������Ϊ��ɫ 										    
	LCD_ShowString(60,150,200,16,16,"SD Card OK    ");
	LCD_ShowString(60,170,200,16,16,"SD Card Size:     MB");
	*sd_size=SD_GetSectorCount();//�õ�������
	LCD_ShowNum(164,170,*sd_size>>11,5,16);//��ʾSD������(������������)***
}

//