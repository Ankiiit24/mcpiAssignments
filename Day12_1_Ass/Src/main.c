

#include <stdint.h>
#include <stdio.h>
#include "stm32f4xx.h"
#include "system_stm32f4xx.h"

#include "i2c_lcd.h"
#include "switch.h"
#include "adc.h"

int main(void)
{
	char str[32];
	SystemInit();
	uint16_t val;
	LcdInit();
	ADC_Init();
	LcdPuts(LCD_LINE1,"LDR Reading..!!");
	SwitchInit(SWITCH);
	while(1)
		{
			while(exti0_flag == 0);
			val = ADC_GetValue();
			sprintf(str, "ADC=%-4d", val);
			LcdPuts(LCD_LINE2,str);
			exti0_flag = 0;
		}
	return 0;
}

