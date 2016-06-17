/*
 * Ultrassonic.cpp
 *
 * Created: 06/06/2016 18:48:08
 *  Author: Gabriel
 */ 

#include "ultrasonic.h"

// This ISR records the time of the pin change
volatile uint16_t _event_time;
ISR(TIMER1_CAPT_vect){
	_event_time = ICR1;
}

void Ultrasonic::init(){
	// Sets PORTB0 as input (ICP1) with no pull up resistor
	DDRB &= ~(1<<DDB0);
	PORTB &= ~(1<<PORTB0);
	
	// Initializes the timer1
	
	TCCR1B |= 1<<ICNC1 | 1<<ICES1 | 1<<CS11; // Input capture noise filter, rising edge interrupt, prescale
}

float Ultrasonic::getRange(){
	sendPulse();
	return getPulseWidth()/116.0;
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
	
	// Returns the difference
	return (falling_edge_time - rising_edge_time) 
}