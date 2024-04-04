/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2024 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is prided AS-IS.
 *
 ******************************************************************************
 */

#include <stdint.h>

#include <stdio.h>
#include "stm32f4xx.h"
#include "system_stm32f4xx.h"

#include "uart.h"
#include "led3dsh.h"
#include "spi.h"
#include "led.h"
#include "i2c_lcd.h"
#include "i2c.h"


#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

int main(void)
{
	char str[32];
	//char str2[32];
		int ret;
		LIS_Data val;
		SystemInit();
		LedInit(LED_BLUE);
		LedInit(LED_GREEN);
		LedInit(LED_RED);
		LedInit(LED_ORANGE);
		UartInit(BAUD_9600);
		UartPuts("LIS3DSH Accel Demo!\r\n");
		LIS_Init();
		DelayMs(1000);
		while(1) {
			ret = LIS_DRdy();
			if(ret) {
				val = LIS_GetData();
				sprintf(str, "X=%d, Y=%d, Z=%d\r\n", val.x, val.y, val.z);
				//UartPuts(str);
			/*	sprintf(str1, "X=%d, Y=%d", val.x, val.y);
				sprintf(str2, " Z=%d", val.z);
								LcdPuts(LCD_LINE1,str1);
								LcdPuts(LCD_LINE2,str2);
			*/					DelayMs(1000);
				DelayMs(1000);

			if(val.x>6000)
			{
				LedBlink(LED_GREEN,1000);
			}
			else if(val.x<-6000)
			{
				LedBlink(LED_RED,1000);
			}
			else if(val.y>2000)
			{
			LedBlink(LED_ORANGE,1000);
			}
			else if(val.y<-2000)
			{
			LedBlink(LED_BLUE,1000);
			}
			}
		}
		return 0;
}