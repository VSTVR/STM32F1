#include"head.h"

const u8 TEXT_Buffer[]={"Data needs to reserve!"};
#define SIZE sizeof(TEXT_Buffer)

int main(void)
{
	
	Init();
	
	lcdwrite(60,50,"IIC Test",RED);//60这位置不是很好！
	lcdwrite(60,90,"WK_UP: write  Key0:read",RED);
	
	while(AT24CXX_Check()==1)//如果没有发现24c02
	{
		lcdwrite(60,130,"Fail to find 24C02! ,please check again!",RED);
		delay_ms(500);
		LED0=!LED0;
	}
	
	lcdwrite(60,130,"Load 24C02 successfully!",BLUE);
	
	//后
	u8 key;
	u16 i=0;
	u8 datatemp[SIZE];
	while(1)
	{
		key=KEY_Scan(0);
		
		if(key==WKUP_PRES)
		{
			LCD_Fill(0,150,239,319,WHITE);
			lcdwrite(60,150,"start write 24c02",BLUE);
			AT24CXX_Write(0,(u8*)TEXT_Buffer,SIZE);//（起始地址，传输内容地址，数据长度）
			lcdwrite(60,150,"Successfully write!",BLUE);
		}
		if(key==KEY0_PRES)
		{
			LCD_Fill(0,150,239,319,YELLOW);
			lcdwrite(60,150,"Start to get message from 24C02",BLACK);
			AT24CXX_Read(0,datatemp,SIZE);//从24C02读取数据存入datatemp中
			lcdwrite(60,150,"The message get is: ",BLACK);
			lcdwrite(60,170,datatemp,BLACK);
		}
		
		i++;
		delay_ms(10);
		
		if(i==0)
		{
			LED1=!LED1;
			i=0;
		}
	}
}

