#include"head.h"

int main(void)
{
	u8 t;u8 len;u16 time=0;
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2); //设置优先级
	delay_init();
	uart_init(9600);
	LED_Init();
	
	while(1)
	{
		if(USART_RX_STA&0x8000)       //如果端口有数据
		{
			len=USART_RX_STA&0x3fff;  //获得数据的长度
			printf("\n您发送的消息为：\n");
			for(t=0;t<len;t++)
			{
				USART1->DR=USART_RX_BUF[t];
				while((USART1->SR&0X40)==0); //每次录入数组都得等上一个录完
			}
			printf("\n");
			USART_RX_STA=0;
			delay_ms(500);
		}else{
			time++;
			if(time%5000==0)
			{
				printf("请输入想要发送的数据：\n");
			}
			if(time%500==0) LED0=!LED0;
			delay_ms(1);    //1个time为1ms
		}
	}
}