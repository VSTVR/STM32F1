#include"head.h"

const u8 TEXT_TO_SEND[]={"Hello, I amf vali ha pi to be fa q~"};
#define TEXT_LENTH sizeof(TEXT_TO_SEND)-1  //TEXT_TO_SEND �ַ�������(������������)
u8 SendBuff[(TEXT_LENTH+2)*100];           //������������

int main(void)
{
	u16 i; float pro=0; //����
	init();
	MYDMA_Config(DMA1_Channel4,(u32)&USART1->DR,(u32)SendBuff,(TEXT_LENTH+2)*100); 
	//DMA1 ͨ�� 4,����Ϊ���� 1,�洢��Ϊ SendBuff,��(TEXT_LENTH+2)*100.
	lcdwrite(60,130,"KEY0: START",RED);
	
	u8 t=0;
	for(i=0;i<(TEXT_LENTH+2)*100;i++)  //���ASCII�ַ���
	{
		if(t>=TEXT_LENTH)//����Ҫ���͵�����ȫ������SendBuff[]�󣬼��뻻�з�
		{ 
			SendBuff[i++]=0x0d; 
			SendBuff[i]=0x0a; 
			t=0;
		}else SendBuff[i]=TEXT_TO_SEND[t++];//��Ҫ���͵����鵼��SendBuff
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
			
			USART_DMACmd(USART1,USART_DMAReq_Tx,ENABLE); //ʹ��USART1���� 
			MYDMA_Enable(DMA1_Channel4);//��ʼһ�� DMA ���䣡 
			
			POINT_COLOR=BLUE;
			while(1) //���������
			{
				if(DMA_GetFlagStatus(DMA1_FLAG_TC4)!=RESET)//�ȴ�ͨ�� 4 �������
				{
					DMA_ClearFlag(DMA1_FLAG_TC4);//���ͨ�� 4 ������ɱ�־
					break; 
				}
			
				pro=DMA_GetCurrDataCounter(DMA1_Channel4);//DMA1ͨ��4�ĵ�ǰ��ʣ��������
				pro=1-pro/((TEXT_LENTH+2)*100);//�õ��ٷֱ� 
				pro*=100; //���� 100 ��
				LCD_ShowNum(40,170,pro,3,16); //ע����showxnum��������������ʾ���������
			}
			
		    //�������
			LCD_ShowNum(40,170,100,3,16); //100%
			lcdwrite(40,150,"Transmit Finished",RED); //���ǣ���ʾ�������	
		    
		}
	    i++;
		delay_ms(10);
		if(i==20)    //ÿ200ms
		{
			LED0=!LED0;
			i=0;
		}
		
	}

}



