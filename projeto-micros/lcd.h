#ifndef TWI_H_
#define TWI_H_

/*
	Byte enviado e coneccao fisica:
	
	D7 D6 D5 D4 BACK EN RW RS
*/
#define RS 0x01
#define RW 0x02
#define EN 0x04
#define BL 0x08

#include <avr/io.h>
#include <util/delay.h>
#include <inttypes.h>

class LCD{
		uint8_t address;
	public:
		void writeCommand(uint8_t);
		void turnOff();
		void turnOn();
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