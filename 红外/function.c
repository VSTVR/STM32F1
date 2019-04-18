#include"head.h"

void Init()
{
	delay_init();
	uart_init(9600);
	LED_Init();
	LCD_Init();
	Remote_Init();
}

void display()
{
	lcdwrite(50,50,"Value:",RED);
	lcdwrite(50,70,"Num:",RED);
	lcdwrite(50,90,"Symbol:",RED);
}

void signal_get()
{
	u8 key;
	u8 t=0;
	u8 *str=0; 
	
	while(1)
	{
		key=Remote_Scan();
		if(key)
		{
			LCD_ShowNum(98,50,key,3,16);
			LCD_ShowNum(82,70,RmtCnt,3,16);//只有按住才有效
			
			switch(key)
			{
				case 0:str="ERROR";break;
				case 162:str="POWER";break;
				case 98:str="UP";break;
				case 2:str="PLAY";break;
				case 226:str="ALIENTEK";break;
				case 194:str="RIGHT";break;
				case 34:str="LEFT";break;
				case 224:str="VOL-";break;
				case 168:str="DOWN";break;
				case 144:str="VOL+";break;
				case 104:str="1";break;
				case 152:str="2";break;
				case 176:str="3";break;
				case 48:str="4";break;
				case 24:str="5";break;
				case 122:str="6";break;
				case 16:str="7";break;
				case 56:str="8";break;
				case 90:str="9";break;
				case 66:str="0";break;
				case 82:str="DELETE";break;
			}
			
			LCD_Fill(106,90,80+8*8,90+8,WHITE);
			lcdwrite(106,90,str,BLUE);
		}else{
			delay_ms(10);
		}
		
		t++;
		if(t==20)
		{
			LED1=!LED1;
			t=0;
		}
	}
}