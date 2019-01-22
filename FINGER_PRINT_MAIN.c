/*
 * FINGER_PRINT_MAIN.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: WAGDY 8.1
 */
#include"FINGER_PRINT_MAIN.h"

u8 FingerPrint_Store_Main(u16 PageId)
{
	//Initialize of Ack with failure befor recieving any package
	u8 Ack=FailToFindMatchingFinger;
	enum Ack_Packet Ack_Packet;
	//Check for the ID
	 FingerPrint_CheckID(Char_1,PageId);
	 _delay_ms(300);
	Ack=FingerPrint_AckPacket_All();
	switch(Ack)
	{
	case(Command_Complete):
	  Ack_Packet=Success;
	break;
	case(Command_ErrorRecPack):
	   return ErrorRecPack;
	break;
	case(Command_ErrorWhenRecTemplate):
	  return InvalidTemplate;
	break;
	case(Command_ErrorAddrPageID):
	  return ErrorAddrPageID;
	break;
	default:
	  return UnknownError;
	break;
	}
	//*****************
	//Getting Image......
	FingerPrint_CollectImage();
	_delay_ms(300);
	Ack=FingerPrint_AckPacket_All();
	switch(Ack)
	{
	case(Command_Complete):
	  Ack_Packet=Success;
	break;
	case(Command_ErrorRecPack):
      return ErrorRecPack;
	break;
	case(Command_NoFingerOnSensor):
	  return NoFingerOnSensor;
	break;
	case(Command_FailToDetectFinger):
	  return FailToDetectFinger;
	break;
	default:
	  return UnknownError;
	break;
	}
	//**********************
	//Generate a character file and store it in char file one
	FingerPrint_GenChar(Char_1);
	_delay_ms(300);
	Ack=FingerPrint_AckPacket_All();
	switch(Ack)
	{
	case(Command_Complete):
	  Ack_Packet=Success;
	break;
	case(Command_ErrorRecPack):
	  return ErrorRecPack;
	break;
	case(Command_FailToGenCharFileOver ):
	  return FailToGenCharFileOver;
	break;
	case(Command_FailToGenCharFileLackness):
	  return FailToGenCharFileLackness;
	break;
	default:
	  return UnknownError;
	break;
	}
	//**********************
	//Generate a character file and store it in char file two
	FingerPrint_GenChar(Char_2);
	_delay_ms(300);
	Ack=FingerPrint_AckPacket_All();
	switch(Ack)
	{
	case(Command_Complete):
	  Ack_Packet=Success;
	break;
	case(Command_ErrorRecPack):
	  return ErrorRecPack;
	break;
	case(Command_FailToGenCharFileOver ):
	  return FailToGenCharFileOver;
	break;
	case(Command_FailToGenCharFileLackness):
	  return FailToGenCharFileLackness;
	break;
	default:
	  return UnknownError;
	break;
	}
	//*********************
	//Generate a template combination from charcter file one and two
	 FingerPrint_GenTemplate();
	 _delay_ms(300);
	Ack=FingerPrint_AckPacket_All();
	switch(Ack)
	{
	case(Command_Complete):
	  Ack_Packet=Success;
	break;
	case(Command_ErrorRecPack):
	  return ErrorRecPack;
	break;
	case(Command_FailToCombCharFile ):
	  return FailToCombCharFile;
	break;
	default:
	  return UnknownError;
	break;
	}
	//*******************
	//Store this template in the page Id
	 FingerPrint_Store(Char_1,PageId);
	 _delay_ms(300);
	Ack=FingerPrint_AckPacket_All();
	switch(Ack)
	{
	case(Command_Complete):
	  Ack_Packet=Success;
	break;
	case(Command_ErrorRecPack):
	  return ErrorRecPack;
	break;
	case(Command_ErrorAddrPageID ):
	  return ErrorAddrPageID;
	break;
	case(Command_ErrorWrittingFlash ):
	  return ErrorWrittingFlash;
	break;
	default:
	  return UnknownError;
	break;
	}
	//*********************
	return Ack_Packet;
}
u8 FingerPrint_Search_Main()
{
	//Initialize of Ack with failure befor recieving any package
	u8 Ack=FailToFindMatchingFinger;
	enum Ack_Packet Ack_Packet;
	//Getting Image......
	FingerPrint_CollectImage();
	_delay_ms(300);
	Ack=FingerPrint_AckPacket_All();
	switch(Ack)
	{
	case(Command_Complete):
	  Ack_Packet=Success;
	break;
	case(Command_ErrorRecPack):
      return ErrorRecPack;
	break;
	case(Command_NoFingerOnSensor):
	  return NoFingerOnSensor;
	break;
	case(Command_FailToDetectFinger):
	  return FailToDetectFinger;
	break;
	default:
	  return UnknownError;
	break;
	}
	//**********************
	//Generate a character file and store it in char file one
	FingerPrint_GenChar(Char_1);
	_delay_ms(300);
	Ack=FingerPrint_AckPacket_All();
	switch(Ack)
	{
	case(Command_Complete):
	  Ack_Packet=Success;
	break;
	case(Command_ErrorRecPack):
	  return ErrorRecPack;
	break;
	case(Command_FailToGenCharFileOver ):
	  return FailToGenCharFileOver;
	break;
	case(Command_FailToGenCharFileLackness):
	  return FailToGenCharFileLackness;
	break;
	default:
	  return UnknownError;
	break;
	}
	//**********************
	//Searching for the char file one
	 FingerPrint_Search();
	 _delay_ms(300);
	Ack=FingerPrint_AckPacket_All();
	switch(Ack)
	{
	case(Command_Complete):
	  Ack_Packet=Success;
	break;
	case(Command_ErrorRecPack):
	  return ErrorRecPack;
	break;
	case(Command_ErrorAddrPageID ):
	  return ErrorAddrPageID;
	break;
	case(Command_ErrorWhenRecTemplate):
	  return ErrorWhenRecTemplate;
	break;
	default:
	  return UnknownError;
	break;
	}
	//*********************
	return Ack_Packet;
}
