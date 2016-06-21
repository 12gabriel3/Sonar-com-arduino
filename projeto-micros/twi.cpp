 #include "TWI.h"
 
 TWI::TWI(uint8_t _address){
	 // Frequencia do bus
	 // prescaler = 1
	 // TWBR = 72
	 // Frequencia = 16000000/(16+2*72) = 100k
	 
	 TWBR = 72;
	 TWSR &= ~(1<<TWPS0) & ~(1<<TWPS1); // Prescaler de 1
	 
	 TWCR = (1<<TWEN);
	 
	 // Guarda o endereco
	 address = _address;
	 
 }
 
 void TWI::sendStart(){
	 TWCR = (1<<TWINT)|(1<<TWSTA)|(1<<TWEN);
 }
 
 int8_t TWI::isReady(){
	return (TWCR & (1<<TWINT));
 }
 
 void TWI::waitForReady(){
	 while (!isReady());
 }
 
 void TWI::sendByte(uint8_t data){
	 TWDR = data;
	 TWCR = (1<<TWINT)|(1<<TWEN);
 }
 
 void TWI::sendStop(){
	 TWCR = (1<<TWINT)|(1<<TWEN)|(1<<TWSTO);
 }
 
 uint8_t TWI::getStatus(){
	 return (TWSR & 0xF8);
 }
 
 void TWI::writeByte(uint8_t data){
	 sendStart();
	 waitForReady();
	 
	 // Escreve para o endereco especificado, com o bit R/W em 0 (Write)
	 sendByte(address<<1);
	 waitForReady();
	 
	 // Escreve os dados
	 sendByte(data);
	 waitForReady();
	 
	 sendStop();
 }