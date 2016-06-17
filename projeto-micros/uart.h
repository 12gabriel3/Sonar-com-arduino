/*
 * uart.h
 *
 * Created: 28/05/2016 02:15:16
 *  Author: Gabriel
 */ 


#ifndef UART_H_
#define UART_H_

#include <stdint.h>
#include <avr/io.h>

class Uart {
	public:
		void init(uint32_t);
		void putchar(uint8_t);
		void println(const char *);
		void println(uint16_t);
		void print(uint16_t);
};

#endif /* UART_H_ */