#include"head.h"

int main(void)
{
	u8 t;u8 len;u16 time=0;
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2); //�������ȼ�
	delay_init();
	uart_init(9600);
	LED_Init();
	
	while(1)
	{
		if(USART_RX_STA&0x8000)       //����˿�������
		{
			len=USART_RX_STA&0x3fff;  //������ݵĳ���
			printf("\n�����͵���ϢΪ��\n");
			for(t=0;t<len;t++)
			{
				USART1->DR=USART_RX_BUF[t];
				while((USART1->SR&0X40)==0); //ÿ��¼�����鶼�õ���һ��¼��
			}
			printf("\n");
			USART_RX_STA=0;
			delay_ms(500);
		}else{
			time++;
			if(time%5000==0)
			{
				printf("��������Ҫ���͵����ݣ�\n");
			}
			if(time%500==0) LED0=!LED0;
			delay_ms(1);    //1��timeΪ1ms
		}
	}
}