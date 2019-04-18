#include"head.h"

void init()
{
	delay_init();
	uart_init(9600);
	LED_Init();
	LCD_Init();
	KEY_Init();
	Adc_Init();
	Dac1_Init();
}


void showvoltage()
{
	u16 adc_x; float temp; u8 t=0; u16 dacval=0; u8 key;
	
	LCD_Clear(WHITE);
	lcdwrite(40,130,"WK_UP: +  / Key0: - ",BLACK);
	lcdwrite(40,150,"DAC VAL:",BLUE);
	lcdwrite(40,170,"DAC VOL:0.000 V",BLUE);
	lcdwrite(40,190,"ADC VOL:0.000 V",BLUE);
	DAC_SetChannel1Data(DAC_Align_12b_R, 0);//**设置输出的DAC值为0,这个函数定义在启动文件里，不用管它
	
	while(1)
	{
		t++;
		key=KEY_Scan(0);
		if(key==WKUP_PRES) //++
		{
			if(dacval<4000)
			{
				dacval+=200;
				DAC_SetChannel1Data(DAC_Align_12b_R, dacval);
			}
		}else if(key==KEY0_PRES)  //--
		{
			if(dacval>200)
			{
				dacval-=200;
			}else{
				dacval=0;    //默认将dacval=200时的值设为0点，脉冲最低点
			}
		    DAC_SetChannel1Data(DAC_Align_12b_R, dacval);
		}
	    
		if(t==10||key==WKUP_PRES||key==KEY0_PRES)
		{
			adc_x=DAC_GetDataOutputValue(DAC_Channel_1);//获得DAC寄存器的值
			LCD_ShowxNum(104,150,adc_x,4,16,0);
			////DAC电压值
			temp=(float)adc_x*(3.3/4096);
			LCD_ShowxNum(104,170,(u8)temp,1,16,0);
			temp=(temp-(u8)temp)*1000;
			LCD_ShowxNum(120,170,temp,3,16,0X80);
			
			adc_x=Get_Adc_Average(ADC_Channel_1,10);
			temp=(float)adc_x*(3.3/4096);
			LCD_ShowxNum(104,190,(u8)temp,1,16,0);
			temp=(temp-(u8)temp)*1000;
			LCD_ShowxNum(120,190,temp,3,16,0X80);
		    
			LED0=!LED0;
	        t=0;
		}
	    delay_ms(10);//1t=10ms
	}
	
}

