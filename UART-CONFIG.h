#ifndef UART_H_config
#define UART_H_config
#include <avr/io.h>
#define  Baudrate    57600
#define F_CPU 12000000UL
#define  UBRRVALUE   ((F_CPU)/(Baudrate*16UL)-1UL)

#endif
