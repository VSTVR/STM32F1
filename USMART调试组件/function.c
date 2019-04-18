#include"head.h"

//sta=0 or 1,用来在外部设置LED1的状态
void led_set(u8 sta)
{
	LED1=sta;
} 

//函数参数调用测试函数(函数的id,设置状态)
void test_fun(void(*ledset)(u8),u8 sta)  
{
	ledset(sta);
}

