#ifndef ULTRASSONIC_H_
#define ULTRASSONIC_H_

#define F_CPU 16000000UL
#include <inttypes.h>
#include "avr/io.h"
#include "avr/interrupt.h"



class Ultrasonic {
		uint16_t getPulseWidth();
		void sendPulse();
	public:
		uint16_t getRange();
		Ultrasonic();
};



#endif /* ULTRASSONIC_H_ */