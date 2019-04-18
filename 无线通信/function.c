#include"head.h"

void Init()
{
	delay_init();
	uart_init(9600); 
	LED_Init(); 
	LCD_Init(); 
	KEY_Init(); 
	NRF24L01_Init(); 
}


void Check()
{
	while(NRF24L01_Check())
	{
		lcdwrite(50,50,"Cannot find NRF24L01!",RED);
		delay_ms(200);
		LCD_Fill(50,50,218,66,WHITE);
	}
	lcdwrite(50,50,"NRF24L01 is OK!",BLUE);
}


void Chosemode(u8*mode)
{
	u8 key;
	lcdwrite(50,70,"KEY0:RX_MODE   KEY1:TX_MODE",BLUE);

	key=KEY_Scan(0);
	switch(key)
	{
		case KEY0_PRES:
			*mode=0;
			break;
		case KEY1_PRES:
			*mode=1;
			break;
	}
	
	delay_ms(1000);
	LCD_Fill(50,50,266,86,WHITE);
}


void Action(u8 mode)
{
	u8 tmp_buf[33];
	u8 key;
	u8 t=0;
	
	if(mode==0)//接受模式
	{
		lcdwrite(50,50,"Receive data",BLUE);
		lcdwrite(50,70,"The data received is:",BLUE);
		NRF24L01_RX_Mode();
		
		while(1)
		{
			if(NRF24L01_RxPacket(tmp_buf)==0)//一旦接收到信息
			{
				tmp_buf[32]=0;//加入字符串结束符
				lcdwrite(218,70,tmp_buf,RED);
			}
			t++;
			delay_ms(200);
			if(t==10)
			{
				LED0=!LED0;
				t=0;
			}
		}
	}
	
	if(mode==1)//发送模式
	{
		lcdwrite(50,50,"Receive data",BLUE);
		NRF24L01_TX_Mode();
		mode=' ';//从空格键开始

		while(1)
		{
			if(NRF24L01_TxPacket(tmp_buf)==TX_OK)
			{
				lcdwrite(50,70,"Data:",BLUE);
				lcdwrite(0,90,tmp_buf,RED);
				
				key=mode;
				for(t=0;t<32;t++)
				{
					key++;
					if(key>('~'))key=' ';
					tmp_buf[t]=key;
				}
				mode++;
				if(mode>'~')mode=' ';
				tmp_buf[32]=0;//加入结束符
			}else{
				lcdwrite(50,70,"Send fail!",RED);
				delay_ms(500);
				LCD_Fill(0,190,240,218,WHITE);
			}
		}
	}

}