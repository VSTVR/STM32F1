#include"head.h"

void Init()
{
	delay_init();
	uart_init(9600);
	KEY_Init();
	LED_Init();
	LCD_Init();
	SPI_Flash_Init();
}