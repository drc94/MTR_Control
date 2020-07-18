#include "TimerInt.hpp"

timerRef_t TIMER_REF;

timerRef_t *ptrTIMER;

void timerInit(void){
  cli();
  
  TCCR1A = 0;// set entire TCCR1A register to 0
  TCCR1B = 0;// same for TCCR1B
  TCNT1  = 0;//initialize counter value to 0
  // set compare match register for 0.5hz increments
  OCR1A = 7812;// = (16*10^6) / (1*1024) - 1 (must be <65536)
  // turn on CTC mode
  TCCR1B |= (1 << WGM12);
  // Set CS10 and CS12 bits for 1024 prescaler
  TCCR1B |= (1 << CS12) | (1 << CS10);  
  // enable timer compare interrupt
  TIMSK1 |= (1 << OCIE1A);

  ptrTIMER = &TIMER_REF;

  *ptrTIMER = TIMER_WAIT;

  sei();
}

void disableTimer(){
  // disable timer compare interrupt
  TIMSK1 &= ~(1 << OCIE1A);
  TCNT1  = 0; //Counter to 0

  *ptrTIMER = TIMER_WAIT;
}

void enableTimer(){
  TIMSK1 |= (1 << OCIE1A);
}

ISR(TIMER1_COMPA_vect){//timer1
  *ptrTIMER = TIMER_FINISH;
}
