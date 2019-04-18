#include"head.h"

void Init()
{
	delay_init();
	uart_init(9600);
	LCD_Init();
	LED_Init();
	KEY_Init();
	tp_dev.init();  //触摸屏初始化
}

//电阻屏函数
void rtp_test()
{
	u8 key;u8 i=0;
	while(1) 
	{ 
		key=KEY_Scan(0);
		tp_dev.scan(0); 
		if(tp_dev.sta&TP_PRES_DOWN)
			{ 
				if(tp_dev.x[0]<lcddev.width && tp_dev.y[0]<lcddev.height)
					{ 
						if(tp_dev.x[0]>(lcddev.width-24)&&tp_dev.y[0]<16)
						{
							LCD_Clear(WHITE);//Load_Drow_Dialog();
						}							
						else TP_Draw_Big_Point(tp_dev.x[0],tp_dev.y[0],RED);	
					} 
			}else delay_ms(10);
		if(key==KEY0_PRES)
		{
			LCD_Clear(WHITE);
			TP_Adjust();
			TP_Save_Adjdata();
			LCD_Clear(WHITE);//Load_Drow_Dialog(); 
		} 
		i++;
		delay_ms(5);
		if(i==20)
		{
			LED0=!LED0;
			i=0;
		}
	}
}
//电容屏函数

const u16 POINT_COLOR_TBL[CT_MAX_TOUCH]={RED,GREEN,BLUE,BROWN,GRED}; 

void ctp_test()
{
	u8 t=0; 
	u8 i=0;
	u16 lastpos[5][2]; //最后一次的数据
	
	while(1)
	{
		tp_dev.scan(0);
		for(t=0;t< CT_MAX_TOUCH;t++)//最多 5 点触摸
		{
			if((tp_dev.sta)&(1<<t))//判断是否有点触摸？
			{
				if(tp_dev.x[t]<lcddev.width&&tp_dev.y[t]<lcddev.height)//在 LCD 范围内
				{
					if(lastpos[t][0]==0XFFFF)
					{
						lastpos[t][0] = tp_dev.x[t];
						lastpos[t][1] = tp_dev.y[t];
					}
					LCD_DrawLine(lastpos[t][0],lastpos[t][1],tp_dev.x[t],tp_dev.y[t]);//原代码不行！
					lastpos[t][0]=tp_dev.x[t];
					lastpos[t][1]=tp_dev.y[t];
					if(tp_dev.x[t]>(lcddev.width-24)&&tp_dev.y[t]<16)
					{
						LCD_Clear(WHITE);//Load_Drow_Dialog();清除
					}
				}
			}else lastpos[t][0]=0XFFFF;
		}
		
		i++;
		delay_ms(5);
		if(i==20)
		{
			LED1=!LED1;
			i=0;
		}
	}
}
