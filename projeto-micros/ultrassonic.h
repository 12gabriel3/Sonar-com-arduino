/*
 * ultrassonic.h
 *
 * Created: 06/06/2016 18:50:01
 *  Author: Renata
 */ 


#ifndef ULTRASSONIC_H_
#define ULTRASSONIC_H_

#include <inttypes.h>
#include "avr/io.h"
#include "avr/interrupt.h"



class Ultrassonic {
		uint16_t getPulseWidth();
	public:
		float getRange();
};



#endif /* ULTRASSONIC_H_ */