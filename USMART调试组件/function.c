#include"head.h"

//sta=0 or 1,�������ⲿ����LED1��״̬
void led_set(u8 sta)
{
	LED1=sta;
} 

//�����������ò��Ժ���(������id,����״̬)
void test_fun(void(*ledset)(u8),u8 sta)  
{
	ledset(sta);
}

