/*
 * servo.cpp
 *
 * Created: 16/06/2016 21:58:21
 *  Author: Gabriel
 */ 

#include "servo.h"
#include <inttypes.h>


void Servo::init(){
	DDRB |= (1<<DDB1);	// Configura o pino do servo como entrada
	
	/*
		Seta o timer1 com as seguintes configuracoes:
		modo 14: fast-PWM de 16 bits
		Unidade de Output compare canal A ativa
		Prescaler de 8
	*/
	
	TCCR1A |= 1<<WGM11 | 1<<COM1A1;
	TCCR1B |= 1<<WGM13 | 1<<WGM12 | 1<<CS11;
	
	//Periodo de 20ms
	ICR1 = 39999;
}

void Servo::setAngle(uint8_t angle){
	// Faz uma regrinha de tres
	uint16_t registrador = (uint16_t)angle*(500-300)/18 + 3000;
	OCR1A = registrador;
}