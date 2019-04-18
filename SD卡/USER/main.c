#include"head.h"

int main(void)
{
	Init();
	u8 key;
	u32 sd_size;
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);// 设置中断优先级分组2
	
	title();
	
	checksd(&sd_size);
	while(1)
	{
		key=KEY_Scan(0);
		u8 i=0;
		if(key==KEY0_PRES)
		{
			for(i=0;i<sd_size;i++)
			{
				SD_Read_Sectorx(i);//KEY0按,读取SD卡扇区0的内容
			}
		}	
	}    	   

}

