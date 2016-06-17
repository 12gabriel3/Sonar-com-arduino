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
	Uart usb;
	Ultrasonic sensor;
	
	usb.init(250000);
	
	while (1) 
    {
		
		
    }
}

