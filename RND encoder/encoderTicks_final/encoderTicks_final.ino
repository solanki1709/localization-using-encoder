#include <avr/io.h>
#include <avr/interrupt.h>


volatile long int count = 0;                    

void setup() {

  sei();
  //port_init();
  Serial.begin(9600);
  DDRD &= ~(1 << PD1);
  PORTD |= (1 << PD1);
  DDRD  &= ~(1 << PD3);
  PORTD |= (1 << PD3);
  /////////////////////////////////////////////////////////
  EICRA |= (1 << ISC11) | (1 << ISC10); ////on rising
  //EIFR |= (1 << INTF1);
  EIMSK |= (1 << INT1);
}

void loop() {

  Serial.println(count);
}

ISR(INT1_vect) {
  if (bit_is_set(PIND, 3)) {
    count++;
  }
  else {
    count--;
  }
}
