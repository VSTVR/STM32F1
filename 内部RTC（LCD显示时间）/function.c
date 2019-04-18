#include"head.h"

void lcdwrite(u16 x,u16 y,u8 *p,u16 color)
{
	POINT_COLOR=color;
	LCD_ShowString(x,y,200,16,16,p);
}

void showtime(u8 t)
{
	lcdwrite(60,130,"    -  -  ",BLUE);  //每个字符8个像素
	lcdwrite(60,162,"  :  :  ",BLUE);
	
	while(1)
	{
		if(t!=calendar.sec)
		{
			t=calendar.sec;
			LCD_ShowNum(60,130,calendar.w_year,4,16);  //16号字占4个空
			LCD_ShowNum(100,130,calendar.w_month,2,16); //2
			LCD_ShowNum(124,130,calendar.w_date,2,16); //2
			
			switch(calendar.week)
			{
				case 0: lcdwrite(60,148,"Sunday",BLUE);break;
				case 1: lcdwrite(60,148,"Monday",BLUE);break;
				case 2: lcdwrite(60,148,"Tuesday",BLUE);break;
				case 3: lcdwrite(60,148,"Wednesday",BLUE);break;
				case 4: lcdwrite(60,148,"Thursday",BLUE);break;
				case 5: lcdwrite(60,148,"Friday",BLUE);break;
				case 6: lcdwrite(60,148,"Saturday",BLUE);break;
			}
		
			LCD_ShowNum(60,162,calendar.hour,2,16);
			LCD_ShowNum(84,162,calendar.min,2,16);
			LCD_ShowNum(108,162,calendar.sec,2,16);
			
		}
	    
		delay_ms(10);
	}
}