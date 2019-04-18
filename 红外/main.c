#include"head.h"

int main(void)
{
	Init();
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2); 
	
	display();
	
	signal_get();
}

