#include"head.h"

//初始化
void Init()
{
	delay_init();	    	 //延时函数初始化	  
	uart_init(9600);	 	//串口初始化为9600
	LED_Init();		  		//初始化与LED连接的硬件接口
	LCD_Init();			   	//初始化LCD	
 	KEY_Init();				//按键初始化  
 	mem_init();				//初始化内存池
}

//标题显示
void title()
{
	POINT_COLOR=RED;//设置字体为红色 
	LCD_ShowString(60,50,200,16,16,"Mini STM32");	
	LCD_ShowString(60,70,200,16,16,"SD CARD TEST");	
	LCD_ShowString(60,90,200,16,16,"ATOM@ALIENTEK");
	LCD_ShowString(60,110,200,16,16,"2014/3/13");  
	LCD_ShowString(60,130,200,16,16,"KEY0:Read Sector 0");
}

//检查SD卡
void checksd(u32*sd_size)
{
	while(SD_Initialize())//检测不到SD卡(1)
	{
		LCD_ShowString(60,150,200,16,16,"SD Card Error!");
		delay_ms(500);					
		LCD_ShowString(60,150,200,16,16,"Please Check! ");
		delay_ms(500);
		LED0=!LED0;//DS0闪烁
	}
	
	//检测SD卡成功
 	POINT_COLOR=BLUE;//设置字体为蓝色 										    
	LCD_ShowString(60,150,200,16,16,"SD Card OK    ");
	LCD_ShowString(60,170,200,16,16,"SD Card Size:     MB");
	*sd_size=SD_GetSectorCount();//得到扇区数
	LCD_ShowNum(164,170,*sd_size>>11,5,16);//显示SD卡容量(扇区数求容量)***
}

//