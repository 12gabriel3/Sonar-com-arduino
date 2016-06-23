 #include "lcd.h"
 
 LCD::LCD(uint8_t _address){
	 // Frequencia do bus
	 // prescaler = 1
	 // TWBR = 72
	 // Frequencia = 16000000/(16+2*72) = 100k
	 
	 TWBR = 72;
	 TWSR &= ~(1<<TWPS0) & ~(1<<TWPS1); // Prescaler de 1
	 
	 TWCR = (1<<TWEN);
	 
	 // Guarda o endereco
	 address = _address;
	 
	 // Sequencia para inicializar o LCD em modo de 4 bits
	 _delay_ms(15);
	 sendStart();
	 waitForReady();
	 
	 sendByte(address<<1);
	 waitForReady();
	 
	 sendByte((0x03<<4)|(1<<EN));
	 waitForReady();
	 sendByte((0x03<<4));
	 waitForReady();
	 _delay_ms(5);
	 
	 sendByte((0x03<<4)|(1<<EN));
	 waitForReady();
	 sendByte((0x03<<4));
	 waitForReady();
	 _delay_us(100);
	 
	 sendByte((0x03<<4)|(1<<EN));
	 waitForReady();
	 sendByte((0x03<<4));
	 waitForReady();
	 _delay_ms(5);
	 
	 sendByte((0x02<<4)|(1<<EN));
	 waitForReady();
	 sendByte((0x02<<4));
	 waitForReady();
	 
	 writeCommand(0x28);
	 
	 sendStop();
 }
 
 void LCD::writeCommand(uint8_t command){
	 sendByte((command & 0xF0)|(1<<EN));
	 waitForReady();
	 sendByte(command & 0xF0);
	 waitForReady();
	 
	 sendByte((command<<4)|(1<<EN));
	 waitForReady();
	 sendByte(command<<4);
	 waitForReady();
 }
 
void LCD::turnOff(){
	sendStart();
	waitForReady();
	
	sendByte(address<<1);
	waitForReady();
	
	writeCommand(0x08);
	
	sendStop();
} 

void LCD::turnOn(){
	sendStart();
	waitForReady();
	
	sendByte(address<<1);
	waitForReady();
	
	writeCommand(0x0C);
	
	sendStop();
}
 
 void LCD::sendStart(){
	 TWCR = (1<<TWINT)|(1<<TWSTA)|(1<<TWEN);
 }
 
 int8_t LCD::isReady(){
	return (TWCR & (1<<TWINT));
 }
 
 void LCD::waitForReady(){
	 while (!isReady());
 }
 
 void LCD::sendByte(uint8_t data){
	 TWDR = data;
	 TWCR = (1<<TWINT)|(1<<TWEN);
 }
 
 void LCD::sendStop(){
	 TWCR = (1<<TWINT)|(1<<TWEN)|(1<<TWSTO);
 }
 
 uint8_t LCD::getStatus(){
	 return (TWSR & 0xF8);
 }
 
 void LCD::writeByte(uint8_t data){
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