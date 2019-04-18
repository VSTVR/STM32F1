#include"head.h"
#include"led.h"
#include"lcd.h"
//注意！！这个文件优点特殊2和3行的定义不能写在头文件里，不要乱动lcd.h和lcd.c 文件里宏定义的位置，不然会报错

int main(void)
{
	u8 x=0;u8 lcd_id[12];
	delay_init();
	uart_init(9600);
	LED_Init();
	LCD_Init();
	
	POINT_COLOR=RED;								 //画笔颜色为红
	sprintf((char*)lcd_id,"LCD ID:%04X",lcddev.id); //lcddev取LCD的id，打印到数组里（不是显示）,""中的是写入的数据
	
	while(1)
	{
		switch(x)
		{
			case 0:LCD_Clear(WHITE);break;   //用一团白色清屏
			case 1:LCD_Clear(BLACK);break;
			case 2:LCD_Clear(BLUE);break;
			case 3:LCD_Clear(RED);break;
			case 4:LCD_Clear(MAGENTA);break;
			case 5:LCD_Clear(GREEN);break;
			case 6:LCD_Clear(CYAN);break;
			case 7:LCD_Clear(YELLOW);break;
			case 8:LCD_Clear(BRRED);break;
			case 9:LCD_Clear(GRAY);break;
			case 10:LCD_Clear(LGRAY);break;
			case 11:LCD_Clear(BROWN);break;
		}
		
		POINT_COLOR=RED;
		LCD_ShowString(30,40,200,24,24,"Mini STM32F103RC");  //起点坐标，区域大小，字体大小
		LCD_ShowString(30,70,200,16,16,"George 2017222021"); //不能显示中文，如有需要将字库放在sd卡后调用
		LCD_ShowString(30,90,200,16,16,"BME01");
		LCD_ShowString(30,110,200,16,16,lcd_id);    		//这种方式没有警告
		LCD_ShowString(30,130,200,12,12,"2018/12/4");  
		
		x++;  			//使之不断改变
		if(x==12)x=0;   //
		LED0=!LED0;
		delay_ms(1000);

	}


}