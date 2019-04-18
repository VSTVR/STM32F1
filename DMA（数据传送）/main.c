#include"head.h"

const u8 TEXT_TO_SEND[]={"Hello, I amf vali ha pi to be fa q~"};
#define TEXT_LENTH sizeof(TEXT_TO_SEND)-1  //TEXT_TO_SEND 字符串长度(不包含结束符)
u8 SendBuff[(TEXT_LENTH+2)*100];           //缓冲区？？？

int main(void)
{
	u16 i; float pro=0; //进度
	init();
	MYDMA_Config(DMA1_Channel4,(u32)&USART1->DR,(u32)SendBuff,(TEXT_LENTH+2)*100); 
	//DMA1 通道 4,外设为串口 1,存储器为 SendBuff,长(TEXT_LENTH+2)*100.
	lcdwrite(60,130,"KEY0: START",RED);
	
	u8 t=0;
	for(i=0;i<(TEXT_LENTH+2)*100;i++)  //填充ASCII字符集
	{
		if(t>=TEXT_LENTH)//当把要发送的数据全部输入SendBuff[]后，加入换行符
		{ 
			SendBuff[i++]=0x0d; 
			SendBuff[i]=0x0a; 
			t=0;
		}else SendBuff[i]=TEXT_TO_SEND[t++];//将要发送的数组导入SendBuff
	}
    
	i=0;
	while(1)
	{
		t=KEY_Scan(0);
		if(t==KEY0_PRES)
		{
			lcdwrite(40,150,"Start Transmit......",BLUE);
			lcdwrite(40,170,"   %",BLUE);
			printf("\r\nReceive DATA:\r\n "); 
			
			USART_DMACmd(USART1,USART_DMAReq_Tx,ENABLE); //使能USART1串口 
			MYDMA_Enable(DMA1_Channel4);//开始一次 DMA 传输！ 
			
			POINT_COLOR=BLUE;
			while(1) //传输过程中
			{
				if(DMA_GetFlagStatus(DMA1_FLAG_TC4)!=RESET)//等待通道 4 传输完成
				{
					DMA_ClearFlag(DMA1_FLAG_TC4);//清除通道 4 传输完成标志
					break; 
				}
			
				pro=DMA_GetCurrDataCounter(DMA1_Channel4);//DMA1通道4的当前还剩余数据量
				pro=1-pro/((TEXT_LENTH+2)*100);//得到百分比 
				pro*=100; //扩大 100 倍
				LCD_ShowNum(40,170,pro,3,16); //注意与showxnum的区别，这里是显示，不是替代
			}
			
		    //传输完成
			LCD_ShowNum(40,170,100,3,16); //100%
			lcdwrite(40,150,"Transmit Finished",RED); //覆盖，显示传输完成	
		    
		}
	    i++;
		delay_ms(10);
		if(i==20)    //每200ms
		{
			LED0=!LED0;
			i=0;
		}
		
	}

}



