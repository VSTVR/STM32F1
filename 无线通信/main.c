#include"head.h"

int main(void)
{
	Init();
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	
	Check();
	
	u8 mode;
	Chosemode(&mode);
	
	Action(mode);
}

