#include <Arduino.h>

void timerInit(void);
void disableTimer(void);
void enableTimer(void);
ISR(TIMER1_COMPA_vect);

typedef enum{
  TIMER_WAIT=0,
  TIMER_FINISH
} timerRef_t;

extern timerRef_t TIMER_REF;
