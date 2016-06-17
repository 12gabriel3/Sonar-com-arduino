/*
 * servo.h
 *
 * Created: 16/06/2016 21:55:43
 *  Author: Gabriel
 */ 


#ifndef SERVO_H_
#define SERVO_H_

#include <inttypes.h>

class Servo{
		public:
	void init();
	void setAngle(uint8_t);
};



#endif /* SERVO_H_ */