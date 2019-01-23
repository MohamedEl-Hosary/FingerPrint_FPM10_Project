/*
 * main.c
 *
 *  Created on: 21 Jan 2019
 *      Author: Mohamed El-Hosary
 */
#include "FINGER_PRINT_MAIN.h"

void main(void)
{
	u8 Ack=FingerPrint_Store_Main(0x01);
	switch(Ack)
	{
	case Success:

	}
}
