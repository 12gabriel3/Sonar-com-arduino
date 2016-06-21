#define F_CPU 16000000UL

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <inttypes.h>
#include "uart.h"
#include "twi.h"


int main(void)
{
	Uart usb(250000);
	TWI lcd(0x27);
	
	sei();
	
	lcd.writeByte(0b01010101);
	
	while (1) 
    {
		
	}
}

