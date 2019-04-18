#include"head.h"

const u8 TEXT_Buffer[]={"Wanqiwei668899!"};
#define SIZE sizeof(TEXT_Buffer)

int main(void)
{
	Init();
	u8 key;
	u8 datatemp[SIZE];//��Ŷ�ȡ������
	u16 i=0;
	u32 FLASH_SIZE;
	
	
	lcdwrite(50,50,"WKUP:Write Key0:Read",BLUE);
	while(SPI_Flash_ReadID()!=W25Q64)//���������flash.c�ļ����棡
	{
		lcdwrite(50,70,"cannot find w25q64",RED);
		delay_ms(500);
		LED0=!LED0;
	}
	
	//
	lcdwrite(50,50,"W25Q64 is ready!",BLUE);
	FLASH_SIZE=8*1024*1024;//8M�ֽ�
	while(1)
	{
		key=KEY_Scan(0);
		if(key==WKUP_PRES)//д��
		{
			SPI_Flash_Write((u8*)TEXT_Buffer,FLASH_SIZE-100,SIZE);
			lcdwrite(50,70,"success!",BLUE);
		}
		if(key==KEY0_PRES)//��ȡ
		{
			SPI_Flash_Read(datatemp,FLASH_SIZE-100,SIZE);
			lcdwrite(50,70,"Read successfully!",RED);
			lcdwrite(50,90,"The data is:",RED);
			lcdwrite(50,110,datatemp,BLUE);
		}
		
		i++;
		delay_ms(10);
		if(i==20)
		{
			LED1=!LED1;
			i=0;
		}
	}
}

