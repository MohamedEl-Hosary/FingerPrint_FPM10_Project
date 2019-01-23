/*
 * main.c
 *
 *  Created on: 21 Jan 2019
 *      Author: Mohamed El-Hosary
 */
#include "FINGER_PRINT_MAIN.h"
#include "LCD.h"

void main(void)
{
	vInit_lcd();
	while(1){
	u8 Ack=FingerPrint_Store_Main(0x01);
	switch(Ack)
	{
	case Success:
		vWrite_string("Store Succeeded");
		_delay_ms(2000);
	}
	}
}
