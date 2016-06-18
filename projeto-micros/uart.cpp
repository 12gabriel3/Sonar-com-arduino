#define F_CPU 16000000UL

#include "uart.h"

// Initializes the uart
Uart::Uart(uint32_t baudRate){
	// Value written on register
	uint16_t ubrr = (F_CPU/16/baudRate)-1; 
	
	// Sets the baud rate
	UBRR0 = ubrr;
	
	// Enables transmitter
	UCSR0B = (1<<TXEN0);
	
	// Sets frame format to 8 data + 2 stop bits
	UCSR0C = (1<<USBS0)|(3<<UCSZ00);
}

void Uart::putchar(uint8_t data){
	// Wait for empty transmit buffer
	while(!(UCSR0A & (1<<UDRE0)));
	
	// Writes the data to the register
	UDR0 = data;
}

void Uart::println(const char * str){
	int i = 0;
	// Prints until it encounters end of string character
	while(str[i] != '\0'){
		putchar((uint8_t)str[i]);
		i++;
	}
	putchar('\n');
}

void Uart::println(uint16_t number){
	uint8_t digits[5];
	uint8_t i = 0;
	
	do{
		digits[i] = number%10;
		number /= 10;
		i++;
	} while(number);
	
	do{
		i--;
		putchar('0'+digits[i]);
	}while(i);
	
	putchar('\n');
}