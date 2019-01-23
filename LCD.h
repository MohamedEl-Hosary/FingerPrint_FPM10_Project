/*
 * LCD.h
 *
 * Created: 4/1/2018 7:36:28 PM
 *  Author: Peter
 */ 


#ifndef LCD_H_
#define LCD_H_
#include <avr/io.h>
//#define F_CPU 12000000ul
#include <util/delay.h>
#include "macros.h"

#include "LCD_CNFG.h"
void vInit_lcd (void);
void vWrite_char (uint8_t data);
void vWrite_inst (uint8_t inst);
void vWrite_string (unsigned char* name);
void vWrite_number (uint16_t num);
void vWrite_number_32bit(uint32_t number);
void vSend_epulse (void);
void vGotoxy (uint8_t row,uint8_t col);


#define clear 0x01
#define home  0x02
#define inc_cur_left 0x04
#define inc_cur_right 0x06

#define shift_cur_left 0x10
#define shift_cur_right 0x14
#define shift_display_left 0x18
#define shift_display_right 0x1c
#define nd_line 0xc0
#define st_line 0x80

#endif
