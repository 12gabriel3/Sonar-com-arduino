#define F_CPU 16000000UL

#include <avr/io.h>
#include <util/delay.h>
#include <stdint.h>
#include "uart.h"
#include "ultrasonic.h"
#include "servo.h"


int main(void)
{
	Uart usb(250000);
	Ultrasonic sensor;
	Servo servo;
	
	sei();
	
	uint8_t angulo = 0;
	
	while (1) 
    {
		while(angulo <= 180){
			usb.println(sensor.getRange());
			servo.setAngle(angulo);
			angulo++;
			_delay_ms(200);
		}
		while(angulo > 0){
			angulo--;
			usb.println(sensor.getRange());
			servo.setAngle(angulo);
			_delay_ms(200);

		}
	}

}