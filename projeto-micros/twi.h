#ifndef TWI_H_
#define TWI_H_

#include <avr/io.h>
#include <util/delay.h>
#include <inttypes.h>

class TWI{
		uint8_t address;
		
		
	public:
		uint8_t getStatus();
		void sendStart();
		void sendStop();
		void sendByte(uint8_t);
		TWI(uint8_t);
		void waitForReady();
		int8_t isReady();
		void writeByte(uint8_t);
};



#endif /* TWI_H_ */