
//B5,B6,E3,E4
#include<avr/io.h>
//#include<avr/interrupt.h>
//int speedMotor1 = (40/100)*255;
//int speedMotor2 = (40/100)*255;
int speedMotor;*/
void setup() {

  
Serial.begin(9600);


DDRC |= 0b11111111;
PORTC |= 0xAA;//2nd and 4th motors will move
//void loop(){}


DDRE |= (1<<4);
PORTE |= (1<<4);


DDRB |= (1<<6);
PORTB |= (1<<6);


ICR1H = 0x02;
ICR1L = 0x9A; /////666


ICR3H = 0x02;
ICR3L = 0x9A;
}

void loop() {

TCCR1B |= (1<<WGM12)|(1<<WGM13)|(1<<CS11);
TCCR1A = 0xAA;

  
//OCR1A = 200;



OCR1B= 666;
//OCR1C = 300;   //666


TCCR3A = 0xAA;
TCCR3B |= (1<<4)|(1<<3)|(1<<1);


//OCR3A = 200;
OCR3B = 666;
//OCR3C = 454;

}
//Serial.println(speedMotor);




