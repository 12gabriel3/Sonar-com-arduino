#define F_CPU 16000000UL

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <inttypes.h>
#include "uart.h"
#include "lcd.h"


int main(void)
{
	Uart usb(250000);
	LCD lcd(0x27);
	
	sei();
		
	while (1) 
    {
		
	}
}

