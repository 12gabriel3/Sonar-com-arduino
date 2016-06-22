#ifndef TWI_H_
#define TWI_H_

/*
	Byte enviado e coneccao fisica:
	
	D7 D6 D5 D4 - EN RW RS
*/
#define RS 0
#define RW 1
#define EN 2
#define D4 4
#define D5 5
#define D6 6
#define D7 7

#include <avr/io.h>
#include <util/delay.h>
#include <inttypes.h>

class LCD{
		uint8_t address;
	public:
		uint8_t getStatus();
		void sendStart();
		void sendStop();
		void sendByte(uint8_t);
		LCD(uint8_t);
		void waitForReady();
		int8_t isReady();
		void writeByte(uint8_t);
};



#endif /* TWI_H_ */