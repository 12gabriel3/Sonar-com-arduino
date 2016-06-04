/*
 * uart.cpp
 *
 * Created: 28/05/2016 02:24:12
 *  Author: Gabriel
 */ 
#define F_CPU 16000000UL

#include "uart.h"
#include <stdint.h>
#include <avr/io.h>

// Initializes the uart
void uart::init(uint32_t baudRate){
	// Value written on register
	uint16_t ubrr = (F_CPU/16/baudRate)-1; 
	
	// Sets the baud rate
	UBRR0H = (unsigned char)(ubrr>>8);
	UBRR0L = (unsigned char)ubrr;
	
	// Enables transmitter
	UCSR0B = (1<<TXEN0);
	
	// Sets frame format to 8 data + 2 stop bits
	UCSR0C = (1<<USBS0)|(3<<UCSZ00);
}

void uart::putchar(uint8_t data){
	// Wait for empty transmit buffer
	while(!(UCSR0A & (1<<UDRE0)));
	
	// Writes the data to the register
	UDR0 = data;
}

void uart::println(const char * str){
	int i = 0;
	// Prints until it encounters end of string character
	while(str[i] != '\0'){
		putchar((uint8_t)str[i]);
		i++;
	}
	putchar('\n');
}