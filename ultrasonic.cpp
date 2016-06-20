#include "ultrasonic.h"
#include <avr/delay.h>
//#include <uart.h>


//Uart usb;
// This ISR records the time of the pin change
volatile uint16_t _event_time;
ISR(TIMER1_CAPT_vect){
	_event_time = ICR1;
}

Ultrasonic::Ultrasonic(){
	// Sets PORTB0 as input (ICP1) with no pull up resistor
	DDRB &= ~(1<<DDB0);
	PORTB &= ~(1<<PORTB0);

	DDRD |= 1<<DDD7;
	
	// Initializes the timer1
	
	TCCR1B |= 1<<ICNC1 | 1<<ICES1 | 1<<CS11; // Input capture noise filter, rising edge interrupt, prescale

	TIMSK1 |= 1<<ICIE1;
}

uint16_t Ultrasonic::getRange(){
	sendPulse();
	// A funcao getPulseWidth retorna o numero de ciclos do timer que ocorreram enquanto
	// o pino echo do sensor estava em nivel alto. Eh o tempo que o som leva para refletir
	// Cada ciclo do timer representa 0.5us = 8/16MHz
	// No datasheet do sensor consta que 1 cm = 58 uS
	// Para extrair os cm no nosso caso eh preciso dividir a largura do pulso por 116
	// Multiplicmos o valor por 10 para obter os milimetros
	
	return (uint16_t)((uint32_t)getPulseWidth()*10/116);
}

void Ultrasonic::sendPulse(){
	PORTD |= (1<<PORTD7);
	_delay_us(10);
	PORTD &= ~(1<<PORTD7);
}

uint16_t Ultrasonic::getPulseWidth(){
	uint16_t rising_edge_time, falling_edge_time;
	
	rising_edge_time = _event_time;
	
	// Waits for a rising edge
	TCCR1B |= 1<<ICES1;  // Sets for interrupt on rising edge
	while(rising_edge_time == _event_time);
	
	// Saves the time of the edge
	rising_edge_time = _event_time;
	
	//Waits for a falling edge
	TCCR1B &= ~(1<<ICES1);  // Sets for interrupt on falling edge
	while(rising_edge_time == _event_time);
	
	// Saves the falling edge time
	falling_edge_time = _event_time;
		
	// Calcula a diferenca
	// Isso precisa ser feito pois o overflow acontece em 39999 e nao em 65535
	if(falling_edge_time > rising_edge_time){
		return falling_edge_time - rising_edge_time;
	} else {
		return 39999 - rising_edge_time + falling_edge_time;
	}
}