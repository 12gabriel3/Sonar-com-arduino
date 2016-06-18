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
#include "ultrasonic.h"



int main(void)
{
	Uart usb(250000);
	Ultrasonic sensor;
	
	sei();
	
	
	while (1) 
    {
		usb.println(sensor.getRange());
		
		_delay_ms(100);
    }
}

