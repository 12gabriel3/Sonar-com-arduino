/*
 * projeto-micros.cpp
 *
 * Created: 23/05/2016 21:38:17
 * Author : Gabriel
 */ 
#define F_CPU 16000000UL

#include <avr/io.h>
#include <util/delay.h>
#include <stdint.h>
#include "uart.h"



int main(void)
{
	DDRB |= (1 << DDB5);
	uart usb;
	
	usb.init(250000);
	
	while (1) 
    {
		PORTB ^= (1<<PORTB5);
		usb.println("Givaldo Lino");
		_delay_ms(500);
		
    }
}

