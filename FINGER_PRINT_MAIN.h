/*
 * FINGER_PRINT_MAIN.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: WAGDY 8.1
 */

#ifndef FINGER_PRINT_MAIN_H_
#define FINGER_PRINT_MAIN_H_

#include"FINGER_PRINT_MODULE.h"

//***********
#define Char_1   0x01
#define Char_2   0x02

enum Ack_Packet
{
	Success,
	NoFingerOnSensor,
	FailToDetectFinger,
    FingerNotMatch,
	FailToFindMatchingFinger,
	FailToCombCharFile,
	ErrorRecPack,
	FailToGenCharFileLackness,
	FailToGenCharFileOver,
	ErrorAddrPageID,
	ErrorWrittingFlash,
	ErrorWhenRecTemplate,
	UnknownError,
	InvalidTemplate,
};
//***********

//detect the finger and store it in the page id specified
u8 FingerPrint_Store_Main(u16 PageId);
//*******************

//detect the finger and search for it.return the page id of the finger detected
u8 FingerPrint_Search_Main(void);
//******************

#endif /* FINGER_PRINT_MAIN_H_ */
